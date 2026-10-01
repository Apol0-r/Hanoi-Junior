# ifndef BRACOROBOTICO_H
# define BRACOROBOTICO_H

#define ANGULO_INICIALIZACAO_BASE 90
#define ANGULO_INICIALIZACAO_GARRA 90
#define ANGULO_INICIALIZACAO_HORIZONTAL 120
#define ANGULO_INICIALIZACAO_VERTICAL 90

#define POS_INICIAL_BASE 180 
#define POS_INICIAL_GARRA 20
#define POS_INICIAL_HORIZONTAL 160
#define POS_INICIAL_VERTICAL 180


#define POS_PADRAO_BASE 96
#define POS_PADRAO_GARRA 60
#define POS_PADRAO_HORIZONTAL 115
#define POS_PADRAO_VERTICAL 110


#include <Servo.h>
#include <Arduino.h>


class BracoRobotico {
  private: 
    int POS_base,
        POS_garra,
        POS_vertical,
        POS_horizontal;
    
    Servo servo_base,
          servo_garra,
          servo_vertical,
          servo_horizontal;
  public:
    BracoRobotico(int PIN_base, int PIN_garra, int PIN_vertical, int PIN_horizontal) {
      
      servo_base.attach(PIN_base);
      servo_base.write(ANGULO_INICIALIZACAO_BASE);
      
      servo_garra.attach(PIN_garra);
      servo_garra.write(ANGULO_INICIALIZACAO_GARRA);

      servo_vertical.attach(PIN_vertical);
      servo_vertical.write(ANGULO_INICIALIZACAO_VERTICAL);

      servo_horizontal.attach(PIN_horizontal);
      servo_horizontal.write(ANGULO_INICIALIZACAO_HORIZONTAL);
    }

    void inicializar();
    void posicao_padrao();
    void exibir_monitor();
    int movimenta_servo(Servo &servo_alvo, int ANG_inicial, int ANG_final);

};

# endif