#include <Servo.h>
#include <SoftwareSerial.h>

#define SERVO_2 // Porta Digital 2 PWM
#define SERVO_3 // Porta Digital 3 PWM
#define SERVO_4 // Porta Digital 4 PWM
#define SERVO_5 // Porta Digital 5 PWM
#define SERVO_6 // Porta Digital 6 PWM

#define MAO_ABERTA '0'
#define MAO_UM '1'
#define MAO_DOIS '2'
#define MAO_TRES '3'
#define MAO_QUATRO '4'
#define MAO_JOIA '5'
#define MAO_FECHADA '6'
#define POLEGAR_FECHADO 'P'
#define POLEGAR_ABERTO 'p'
#define INDICADOR_FECHADO 'I'
#define INDICADOR_ABERTO 'i'
#define MEDIO_FECHADO 'M'
#define MEDIO_ABERTO 'm'
#define ANELAR_FECHADO 'A'
#define ANELAR_ABERTO 'a'
#define MINDINHO_FECHADO 'H'
#define MINDINHO_ABERTO 'h'

SoftwareSerial bluetooth(0,1);
//1- mindinho, 2- anelar, 3- medio, 4- indicador, 5- polegar
Servo s1, s2, s3, s4, s5; // Variável Servo
int pos1, pos2, pos3, pos4, pos5; // Posição Servo
// Estado dos dedos -- 0 = aberto, 1 = fechado
int estDedo1 = 0, estDedo2 = 0, estDedo3 = 0, estDedo4 = 0, estDedo5 = 0; 


char comando;

void setup ()
{
  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
  s5.attach(6);
  Serial.begin(9600);
  s1.write(0); // Inicia motor 1 posição zero
  s2.write(0); // Inicia motor 2 posição zero
  s3.write(0); // Inicia motor 3 posição zero
  s4.write(0); // Inicia motor 4 posição zero
  s5.write(0); // Inicia motor 5 posição zero
}

void loop()
{ 
  delay(800);
  comando = Serial.read();
  Serial.print(comando);
  
   // Movimentacoes dos dedos de acordo com o comando recebido
    if(comando == MAO_ABERTA){
      if(!EstaAberto(estDedo1)) dedo1_abrir();
      if(!EstaAberto(estDedo2)) dedo2_abrir();
      if(!EstaAberto(estDedo3)) dedo3_abrir();
      if(!EstaAberto(estDedo4)) dedo4_abrir();
      if(!EstaAberto(estDedo5)) dedo5_abrir();
    }
    else if(comando == MAO_UM){
      if(EstaAberto(estDedo1)) dedo1_fechar();
      if(EstaAberto(estDedo2)) dedo2_fechar();
      if(EstaAberto(estDedo3)) dedo3_fechar();
      if(!EstaAberto(estDedo4)) dedo4_abrir();
      if(EstaAberto(estDedo5)) dedo5_fechar();
    }
    else if(comando == MAO_DOIS){
      if(EstaAberto(estDedo1)) dedo1_fechar();
      if(EstaAberto(estDedo2)) dedo2_fechar();
      if(!EstaAberto(estDedo3)) dedo3_abrir();
      if(!EstaAberto(estDedo4)) dedo4_abrir();
      if(EstaAberto(estDedo5)) dedo5_fechar();
    }
    else if(comando == MAO_TRES){
      if(EstaAberto(estDedo1)) dedo1_fechar();
      if(!EstaAberto(estDedo2)) dedo2_abrir();
      if(!EstaAberto(estDedo3)) dedo3_abrir();
      if(!EstaAberto(estDedo4)) dedo4_abrir();
      if(EstaAberto(estDedo5)) dedo5_fechar();
    }
    else if(comando == MAO_QUATRO){
      if(!EstaAberto(estDedo1)) dedo1_abrir();
      if(!EstaAberto(estDedo2)) dedo2_abrir();
      if(!EstaAberto(estDedo3)) dedo3_abrir();
      if(!EstaAberto(estDedo4)) dedo4_abrir();
      if(EstaAberto(estDedo5)) dedo5_fechar();
    }
    else if(comando == MAO_JOIA){
      if(EstaAberto(estDedo1)) dedo1_fechar();
      if(EstaAberto(estDedo2)) dedo2_fechar();
      if(EstaAberto(estDedo3)) dedo3_fechar();
      if(EstaAberto(estDedo4)) dedo4_fechar();
      if(!EstaAberto(estDedo5)) dedo5_abrir();
    }
    else if(comando == MAO_FECHADA){
      if(EstaAberto(estDedo1)) dedo1_fechar();
      if(EstaAberto(estDedo2)) dedo2_fechar();
      if(EstaAberto(estDedo3)) dedo3_fechar();
      if(EstaAberto(estDedo4)) dedo4_fechar();
      if(EstaAberto(estDedo5)) dedo5_fechar();
    }
    else if(comando == POLEGAR_FECHADO){
        if(EstaAberto(estDedo5)) dedo5_fechar();
    }
    else if(comando == POLEGAR_ABERTO){
        if(!EstaAberto(estDedo5)) dedo5_abrir();
    }
    else if(comando == INDICADOR_FECHADO){
        if(EstaAberto(estDedo4)) dedo4_fechar();
    }
    else if(comando == INDICADOR_ABERTO){
        if(!EstaAberto(estDedo4)) dedo4_abrir();
    }
    else if(comando == MEDIO_FECHADO){
        if(EstaAberto(estDedo3)) dedo3_fechar();
    }
    else if(comando == MEDIO_ABERTO){
        if(!EstaAberto(estDedo3)) dedo3_abrir();
    }
    else if(comando == ANELAR_FECHADO){
        if(EstaAberto(estDedo2)) dedo2_fechar();
    }
    else if(comando == ANELAR_ABERTO){
        if(!EstaAberto(estDedo2)) dedo2_abrir();
    }
    else if(comando == MINDINHO_FECHADO){
        if(EstaAberto(estDedo1)) dedo1_fechar();
    }
    else if(comando == MINDINHO_ABERTO){
        if(!EstaAberto(estDedo1)) dedo1_abrir();
    }

}

//Funcoes basicas de abrir e fechar cada dedo
void dedo1_abrir(){
  for(pos1 = 180; pos1 >= 0; pos1--)
  { 
    s1.write(pos1);
    estDedo1 = 0;
  }
}

void dedo2_abrir(){
  for(pos2 = 180; pos2 >= 0; pos2--)
  { 
    s2.write(pos2);
    estDedo2 = 0;
  }
}

void dedo3_abrir(){
  for(pos3 = 180; pos3 >= 0; pos3--)
  { 
    s3.write(pos3);
    estDedo3 = 0;
  }
}

void dedo4_abrir(){
  for(pos4 = 180; pos4 >= 0; pos4--)
  { 
    s4.write(pos4);
    estDedo4 = 0; 
  }
}

void dedo5_abrir(){
  for(pos5 = 180; pos5 >= 0; pos5--)
  { 
    s5.write(pos5);
    estDedo5 = 0; 
  }
}

void dedo1_fechar(){
  for(pos1 = 0; pos1 < 180; pos1++)
  { 
    s1.write(pos1);
    estDedo1 = 1;
  }
}

void dedo2_fechar(){
  for(pos2 = 0; pos2 < 180; pos2++)
  { 
    s2.write(pos2);
    estDedo2 = 1;
  }
}

void dedo3_fechar(){
  for(pos3 = 0; pos3 < 180; pos3++)
  { 
    s3.write(pos3);
    estDedo3 = 1;
  }
}

void dedo4_fechar(){
  for(pos4 = 0; pos4 < 180; pos4++)
  { 
    s4.write(pos4);
    estDedo4 = 1; 
  }
}

void dedo5_fechar(){
  for(pos5 = 0; pos5 < 180; pos5++)
  { 
    s5.write(pos5);
    estDedo5 = 1; 
  }
}

int EstaAberto(int estDedo){
  if(estDedo == 0) return 1;
  else return 0;
}
