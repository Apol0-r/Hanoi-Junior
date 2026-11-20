#include <Arduino.h>
#include "braco_robotico.h"
#include "ferramentas.h"
#include "hanoi.h"
#include "defines.h"


void setup() {

  BracoRobotico braco_goat(PIN_BASE, PIN_GARRA, PIN_VERTICAL, PIN_HORIZONTAL);
  TorreHanoi torre(1, braco_goat);
  bool operacao;
  
  Serial.begin(9600);
  
  braco_goat.posicao_padrao();
  
  delay(1000);

  operacao = braco_goat.posicao_padrao();
  verificarOperacao("Posicao Padrao", operacao);

  torre.exibirStatus();
  operacao = resolverHanoi(3, 1, 3, 2, torre);

  verificarOperacao("Resolver Hanoi", operacao);
}

void loop() {}

