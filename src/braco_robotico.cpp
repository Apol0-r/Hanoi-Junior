#include "braco_robotico.h"






int BracoRobotico::movimenta_suave(Servo &servo_alvo, int ANG_inicial, int ANG_final) {
    if (ANG_inicial == ANG_final) return ANG_final;

    int diferenca = ANG_final - ANG_inicial;
    int i;

    if (diferenca < 0) {
        for (i = ANG_inicial; i >= ANG_final; i--) {
            servo_alvo.write(i);
            delay(15);
            
        }
    } else if (diferenca > 0) {
        for (i = ANG_inicial; i <= ANG_final; i++) {
            servo_alvo.write(i);
            delay(15);
        }
    }
    
    // servo_alvo.write(ANG_final);

    delay(200);

    return ANG_final;
}

 bool BracoRobotico::moverVerticalEHorizontal(int anguloVertical, int anguloHorizontal) {
    int delta_vertical = anguloVertical - POS_vertical;
    int delta_horizontal = anguloHorizontal - POS_horizontal;

    int passos = max(abs(delta_vertical), abs(delta_horizontal));

    if (passos == 0) return true;

    int POS_V_inicial = POS_vertical;
    int POS_H_inicial  = POS_horizontal;

    for (int i = 0; i <= passos; i++) {
        int POS_V_atual = POS_V_inicial + (delta_horizontal*i)/passos;
        int POS_H_atual = POS_H_inicial + (delta_horizontal*i)/passos;

        servo_vertical.write(POS_V_atual);
        servo_horizontal.write(POS_H_atual);

        delay(15);
    }

    POS_vertical = anguloVertical;
    POS_horizontal = anguloHorizontal;

    delay(200);
    return true;
 }


bool BracoRobotico::moverBase(int angulo) {
    POS_base = movimenta_suave(servo_base, POS_base, angulo);
    return true;
}

bool BracoRobotico::moverGarra(int angulo) {
    // POS_garra = movimenta_suave(servo_garra, POS_garra, angulo);
    POS_garra = angulo;
    servo_garra.write(POS_garra);
    return true;
}

bool BracoRobotico::moverHorizontal(int angulo) {
    POS_horizontal = movimenta_suave(servo_horizontal, POS_horizontal, angulo);
    return true;
}

bool BracoRobotico::moverVertical(int angulo) {
    POS_vertical = movimenta_suave(servo_vertical, POS_vertical, angulo);
    return true;
}



bool BracoRobotico::posicao_padrao() {
    POS_base = movimenta_suave(servo_base, POS_base, POS_PADRAO_BASE);
    POS_garra = movimenta_suave(servo_garra, POS_garra, POS_PADRAO_GARRA);
    POS_vertical = movimenta_suave(servo_vertical, POS_vertical, POS_PADRAO_VERTICAL);
    POS_horizontal = movimenta_suave(servo_horizontal, POS_horizontal, POS_PADRAO_HORIZONTAL);

    return true;
}

bool BracoRobotico::inicializar() {

    POS_base = movimenta_suave(servo_base, POS_base, POS_CALIBRACAO_BASE);
    POS_garra = movimenta_suave(servo_garra, POS_garra, POS_CALIBRACAO_GARRA);
    POS_horizontal = movimenta_suave(servo_horizontal, POS_horizontal, POS_CALIBRACAO_HORIZONTAL);
    POS_vertical = movimenta_suave(servo_vertical, POS_vertical, POS_CALIBRACAO_VERTICAL);

    return true;
}







int BracoRobotico::getPOS_base() const {
    return POS_base;
}   
int BracoRobotico::getPOS_garra() const {
    return POS_garra;
}   
int BracoRobotico::getPOS_vertical() const {
    return POS_vertical;
}   
int BracoRobotico::getPOS_horizontal() const {
    return POS_horizontal;
}   









