#include "hanoi.h"

static int discosNoPino[3] = {3, 0, 0};


int descobrir_anguloPino(int pino) {
    switch (pino) {
        case 1:
            return PINO_ESQUERDO;
            break;
        case 2:
            return PINO_CENTRAL;
            break;
        case 3:
            return PINO_DIREITO;
            break;
    }
    return 0;
}

int descobrir_anguloServoVertical(int nivel) {
    switch (nivel) {
        case 1:
            return NIVEL_1_VERTICAL;    
        case 2:
            return NIVEL_2_VERTICAL;
            break;
        case 3:
            return NIVEL_3_VERTICAL;
            break;
    }
}

int descobrir_anguloServoHorizontal(int nivel) {
    switch (nivel) {
        case 1:
            return NIVEL_1_HORIZONTAL;
            break;
        case 2:
            return NIVEL_2_HORIZONTAL;
            break;
        case 3:
            return NIVEL_3_HORIZONTAL;
            break;
    }
}

bool moverDisco(int origem, int destino, BracoRobotico &braco_goat) {

    int nivelOrigem = discosNoPino[origem - 1];
    int nivelDestino = discosNoPino[destino - 1] + 1;

    int anguloPino = descobrir_anguloPino(origem);
    int anguloVertical = descobrir_anguloServoVertical(nivelOrigem);
    int anguloHorizontal= descobrir_anguloServoHorizontal(nivelOrigem); 

    
    braco_goat.moverBase(anguloPino); 
    braco_goat.moverHorizontal(anguloHorizontal);
    braco_goat.moverVertical(anguloVertical);
    braco_goat.moverGarra(GARRA_ABERTA);

    discosNoPino[origem - 1]--;
    discosNoPino[destino - 1]++;

    return true;
}

bool resolverHanoi(int n, int origem, int destino, int aux, BracoRobotico &braco_goat) {
    if (n == 1) {
        // Caso Base: Mover apenas 1 disco diretamente
        moverDisco(origem, destino, braco_goat);
        return true;
    }

    // 1. Mover n-1 discos da Origem para o Auxiliar
    resolverHanoi(n - 1, origem, aux, destino, braco_goat);

    // 2. Mover o disco restante da Origem para o Destino
    moverDisco(origem, destino, braco_goat);
    // 3. Mover n-1 discos do Auxiliar para o Destino
    resolverHanoi(n - 1, aux, destino, origem, braco_goat);

    return true;
}