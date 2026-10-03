
#include "braco_robotico.h"
#include "depuracao.h"

#define PIN_GARRA 3
#define PIN_HORIZONTAL 5
#define PIN_VERTICAL 6
#define PIN_BASE 9



void setup() {

  BracoRobotico braco_goat(PIN_BASE, PIN_GARRA, PIN_VERTICAL, PIN_HORIZONTAL);

  bool operacao;

  // braco_goat.teste();
  
  Serial.begin(9600);

  operacao = braco_goat.inicializar();
  verificarOperacao("Inicializacao p/ Extremos", operacao);

  delay(1000);

  // operacao = braco_goat.moverBase(90);
  // verificarOperacao("Mover a base", operacao);

  operacao = braco_goat.posicao_padrao();
  verificarOperacao("Posicao Padrao", operacao);

  exibirStatus(braco_goat);
}

void loop() {
  // put your main code here, to run repeatedly:
}

