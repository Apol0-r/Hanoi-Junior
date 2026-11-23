#include "hanoi.h"

// ===========================================

TorreHanoi::TorreHanoi(int posicao_torre_inicial, BracoRobotico &braco_usado)
: discosNoPino{0}, braco_goat(braco_usado) {
    discosNoPino[posicao_torre_inicial - 1] = 3;
}
TorreHanoi::~TorreHanoi() {} 

void TorreHanoi::medicaoAngulos(int origem, int destino) {
    nivelOrigem = discosNoPino[origem - 1];
    nivelDestino = discosNoPino[destino - 1] + 1;

    anguloPinoOrigem = medir.anguloPino(origem);
    anguloPinoDestino = medir.anguloPino(destino);

    anguloVertical = medir.anguloServoVertical(origem, nivelOrigem);
    anguloHorizontal= medir.anguloServoHorizontal(origem, nivelOrigem);

    anguloVerticalRecuo = medir.anguloServoVertical(origem, 4);
    anguloHorizontalRecuo = medir.anguloServoHorizontal(origem, 4);

    anguloVerticalSoltura = medir.anguloServoVertical(destino, 4);
    anguloHorizontalSoltura = medir.anguloServoHorizontal(destino, 4);
}

bool TorreHanoi::moverDisco(int origem, int destino) {

    medicaoAngulos(origem, destino);
    braco_goat.posicao_padrao();

    // 1. Ir até o pino de Origem em posição elevada
    braco_goat.moverGarra(GARRA_ABERTA);
    braco_goat.moverBase(anguloPinoOrigem);

    
    // 2. Descer para a altura do disco e Coletar
    braco_goat.moverHasteVertical(anguloVertical);
    delay(500);
    braco_goat.moverHasteHorizontal(anguloHorizontal);
    braco_goat.moverGarra(GARRA_FECHADA);

    // 3. Elevar o braço (Recuo / Altura Segura para transporte)
    braco_goat.moverHasteHorizontal(anguloHorizontalRecuo);
    braco_goat.moverHasteVertical(anguloVerticalRecuo);

    // 4. Giro da Base e Soltura do Disco
    braco_goat.moverBase(anguloPinoDestino);
    braco_goat.moverHasteVertical(anguloVerticalSoltura);
    delay(500);
    braco_goat.moverHasteHorizontal(anguloHorizontalSoltura);
    braco_goat.moverGarra(GARRA_ABERTA);

    Serial.println("===============================");
    Serial.print("Disco movido do pino ");
    Serial.print(origem);
    Serial.print(" para o pino ");
    Serial.println(destino);

    discosNoPino[origem - 1]--;
    discosNoPino[destino - 1]++;

    exibirStatus();
    
    return true;
}

void TorreHanoi::exibirStatus() {
    Serial.println("===============================");
    Serial.print("Discos no Pino 1: ");
    Serial.println(discosNoPino[0]);
    Serial.print("Discos no Pino 2: ");
    Serial.println(discosNoPino[1]);
    Serial.print("Discos no Pino 3: ");
    Serial.println(discosNoPino[2]);
    Serial.println("===============================");
}

// ===========================================

bool resolverHanoi(int n, int origem, int destino, int aux, TorreHanoi &torre) {
    if (n == 1) {
        // Caso Base: Mover apenas 1 disco diretamente
        torre.moverDisco(origem, destino);
        return true;
    }
    
    // 1. Mover n-1 discos da Origem para o Auxiliar
    resolverHanoi(n - 1, origem, aux, destino, torre);

    // 2. Mover o disco restante da Origem para o Destino
    torre.moverDisco(origem, destino);

    // 3. Mover n-1 discos do Auxiliar para o Destino
    resolverHanoi(n - 1, aux, destino, origem, torre);

    return true;
}