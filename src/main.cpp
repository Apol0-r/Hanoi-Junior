
#include "braco_robotico.h"

#define PIN_GARRA 3
#define PIN_HORIZONTAL 5
#define PIN_VERTICAL 6
#define PIN_BASE 9

BracoRobotico braco_goat(PIN_BASE, PIN_GARRA, PIN_VERTICAL, PIN_HORIZONTAL);

void setup() {
  braco_goat.inicializar();
}

void loop() {
  // put your main code here, to run repeatedly:
}

