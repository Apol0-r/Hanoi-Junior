#ifndef BRACOROBOTICO_H
#define BRACOROBOTICO_H

#include <Servo.h>
#include "ferramentas.h"

class BracoRobotico {
  protected:
    int POS_base,
        POS_garra,
        POS_vertical,
        POS_horizontal;

    Servo servo_base,
          servo_garra,
          servo_vertical,
          servo_horizontal;

    FerramentasMovimentacao movimentar;
    FerramentasExibicao exibir;

  public:
    BracoRobotico(int PIN_base, int PIN_garra, int PIN_vertical, int PIN_horizontal);

    bool inicializar();
    bool posicao_padrao();

    bool moverBase(int angulo);
    bool moverGarra(int angulo);
    bool moverHasteHorizontal(int angulo);
    bool moverHasteVertical(int angulo);

    void exibirStatus();

    ~BracoRobotico();
};

#endif