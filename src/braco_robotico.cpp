#include "braco_robotico.h"
#include "defines.h"
#include "ferramentas.h"


BracoRobotico::BracoRobotico(int PIN_base, int PIN_garra, int PIN_vertical, int PIN_horizontal) 
: POS_base(POS_PADRAO_BASE), POS_garra(POS_PADRAO_GARRA), POS_vertical(POS_PADRAO_VERTICAL), POS_horizontal(POS_PADRAO_HORIZONTAL) {
    
    servo_base.attach(PIN_base);
    servo_base.write(POS_base);
    
    servo_garra.attach(PIN_garra);
    servo_garra.write(POS_garra);

    servo_vertical.attach(PIN_vertical);
    servo_vertical.write(POS_vertical);
    
    servo_horizontal.attach(PIN_horizontal);
    servo_horizontal.write(POS_horizontal);
}

BracoRobotico::~BracoRobotico() {
    servo_base.detach();
    servo_garra.detach();
    servo_vertical.detach();
    servo_horizontal.detach();
}

bool BracoRobotico::moverBase(int angulo) {
    POS_base = movimentar.mover(servo_base, POS_base, angulo);
    return true;
}
bool BracoRobotico::moverGarra(int angulo) {
    POS_garra = angulo;
    servo_garra.write(POS_garra);
    return true;
}
bool BracoRobotico::moverHasteHorizontal(int angulo) {
    POS_horizontal = movimentar.mover(servo_horizontal, POS_horizontal, angulo);
    return true;
}
bool BracoRobotico::moverHasteVertical(int angulo) {
    POS_vertical = movimentar.mover(servo_vertical, POS_vertical, angulo);
    return true;
}

bool BracoRobotico::posicao_padrao() {
    moverBase(POS_PADRAO_BASE);
    moverGarra(GARRA_ABERTA);
    moverHasteHorizontal(POS_PADRAO_HORIZONTAL);
    moverHasteVertical(POS_PADRAO_VERTICAL);
    return true;
}
bool BracoRobotico::inicializar() {
    moverBase(ANGULO_INICIALIZACAO_BASE);
    moverGarra(ANGULO_INICIALIZACAO_GARRA);
    moverHasteHorizontal(ANGULO_INICIALIZACAO_HORIZONTAL);  
    moverHasteVertical(ANGULO_INICIALIZACAO_VERTICAL);
    return true;
}












