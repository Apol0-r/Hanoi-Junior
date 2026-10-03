#include "braco_robotico.h"
#include "depuracao.h"
#include "hanoi.h"

#define PIN_GARRA 3
#define PIN_HORIZONTAL 5
#define PIN_VERTICAL 6
#define PIN_BASE 9

void setup() {

  BracoRobotico braco_goat(PIN_BASE, PIN_GARRA, PIN_VERTICAL, PIN_HORIZONTAL);

  bool operacao;
  
  Serial.begin(9600);
  
  operacao = braco_goat.posicao_padrao();
  verificarOperacao("Posicao Padrao", operacao);
  exibirStatus(braco_goat);

  delay(1000);

  // braco_goat.moverBase(PINO_ESQUERDO);
  // braco_goat.moverHorizontal(NIVEL_3_HORIZONTAL);
  // braco_goat.moverVertical(NIVEL_3_VERTICAL);
  // braco_goat.moverGarra(GARRA_ABERTA);

  // exibirStatus(braco_goat);
  
  // delay(1000);
  // operacao = braco_goat.posicao_padrao();

  // verificarOperacao("Posicao Padrao", operacao);
  // exibirStatus(braco_goat);

  braco_goat.moverBase(PINO_ESQUERDO);
  braco_goat.moverHorizontal(NIVEL_3_HORIZONTAL);
  braco_goat.moverVertical(NIVEL_3_VERTICAL);
  braco_goat.moverGarra(GARRA_FECHADA);
  exibirStatus(braco_goat);
  
}

void loop() {
  // put your main code here, to run repeatedly:
}

