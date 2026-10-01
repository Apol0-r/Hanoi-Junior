#include <braco_robotico.h>

void BracoRobotico::exibir_monitor() {

}

int BracoRobotico::movimenta_servo(Servo &servo_alvo, int ANG_inicial, int ANG_final) {
    int diferenca = ANG_final - ANG_inicial;
    int i;

    if (diferenca < 0) {
        for (i = ANG_inicial; i != ANG_final; i--) {
            servo_alvo.write(i);
            delay(15);
            
        }
    } else if (diferenca > 0) {
        for (i = ANG_inicial; i != ANG_final; i++) {
            servo_alvo.write(i);
            delay(15);
        }
    }

    servo_alvo.write(ANG_final);

    delay(2000);

    return i;
}

void BracoRobotico::posicao_padrao() {
    POS_base = movimenta_servo(servo_base, POS_base, POS_PADRAO_BASE);
    POS_garra = movimenta_servo(servo_garra, POS_garra, POS_PADRAO_GARRA);
    POS_vertical = movimenta_servo(servo_vertical, POS_vertical, POS_PADRAO_VERTICAL);
    POS_horizontal = movimenta_servo(servo_horizontal, POS_horizontal, POS_PADRAO_HORIZONTAL);
}

void BracoRobotico::inicializar() {

    POS_base = movimenta_servo(servo_base, ANGULO_INICIALIZACAO_BASE, POS_INICIAL_BASE);
    POS_garra = movimenta_servo(servo_garra, ANGULO_INICIALIZACAO_GARRA, POS_INICIAL_GARRA);
    POS_horizontal = movimenta_servo(servo_horizontal, ANGULO_INICIALIZACAO_HORIZONTAL, POS_INICIAL_HORIZONTAL);
    POS_vertical = movimenta_servo(servo_vertical, ANGULO_INICIALIZACAO_VERTICAL, POS_INICIAL_VERTICAL);

    posicao_padrao();

}





