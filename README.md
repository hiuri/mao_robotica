# Projeto Mão Robótica
Trabalho final de Projeto Integrado em Computação 2021/2 - UFES Campus Goiabeiras

Grupo: Gabriel Gatti e Hiuri Liberato



# Resumo
Criação de uma mão robótica que executa movimentos de acordo com os comandos recebidos via Bluetooth pelo aplicativo mobile.

# Descrição
O projeto inclui a montagem de um circuito com 1 Arduino MEGA, 5 servomotores e um módulo Bluetooth HC-05. 

A movimentação de cada dedo é dada pela rotação em 180° de seus respectivos servomotores e necessita da inclusão da biblioteca “Servo.h”. Inicialmente, todos os dedos ficam na posição aberta. Dentre as opções de movimentação há a de mover separadamente cada dedo (abrir/fechar) e a de fazer gestos pré-estabelecidos de: mão fechada; somente o indicador levantado; indicador e médio levantados; indicador, médio e anelar levantados; somente polegar abaixado; e somente o polegar levantado. Ao selecionar alguma opção no aplicativo, o smartphone se comunica com o Arduino enviando um certo caractere correspondente à ação escolhida. No código, esse caractere é lido na função loop() e a movimentação dos dedos é feita a partir disso com a chamada das funções dedoX_abrir() e dedoX_fechar() (X = número do dedo). 

O aplicativo mobile foi desenvolvido com a ferramenta App Inventor.

A alimentação do sistema é feita com um power bank de 2000 mAh.

# Esquemático

# Aplicativo
