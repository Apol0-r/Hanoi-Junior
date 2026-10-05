#include "hanoi.h"

static int discosNoPino[3] = {3, 0, 0};


int descobrir_anguloPino(int pino) {
    switch (pino) {
        case 1: return PINO_ESQUERDO;            
        case 2: return PINO_CENTRAL;            
        case 3: return PINO_DIREITO;       
    }
}

int descobrir_anguloServoVertical(int pino, int nivel) {
    if (pino == 2) {
        switch (nivel) {
            case 1: return NIVEL_1_VERTICAL_CENTRAL;    
            case 2: return NIVEL_2_VERTICAL_CENTRAL;
            case 3: return NIVEL_3_VERTICAL_CENTRAL;
            case 4: return NIVEL_4_VERTICAL_CENTRAL;
            default: return NIVEL_4_VERTICAL_CENTRAL;
        }
    } else {
        switch (nivel) {
        case 1: return NIVEL_1_VERTICAL;    
        case 2: return NIVEL_2_VERTICAL;
        case 3: return NIVEL_3_VERTICAL;
        case 4: return NIVEL_4_VERTICAL;
        default: return NIVEL_4_VERTICAL_CENTRAL;
        }
    }
}

int descobrir_anguloServoHorizontal(int pino, int nivel) {
    if (pino == 2) {
        switch (nivel) {
            case 1: return NIVEL_1_HORIZONTAL_CENTRAL;    
            case 2: return NIVEL_2_HORIZONTAL_CENTRAL;
            case 3: return NIVEL_3_HORIZONTAL_CENTRAL;
            case 4: return NIVEL_4_HORIZONTAL_CENTRAL;
            default: return NIVEL_4_VERTICAL_CENTRAL;
        }
    } else {
        switch (nivel) {
        case 1: return NIVEL_1_HORIZONTAL;    
        case 2: return NIVEL_2_HORIZONTAL;
        case 3: return NIVEL_3_HORIZONTAL;
        case 4: return NIVEL_4_HORIZONTAL;
        default: return NIVEL_4_VERTICAL_CENTRAL;
        }
    }
}

bool moverDisco(int origem, int destino, BracoRobotico &braco_goat) {

    int nivelOrigem = discosNoPino[origem - 1];
    int nivelDestino = discosNoPino[destino - 1] + 1;

    int anguloPinoOrigem = descobrir_anguloPino(origem);
    int anguloPinoDestino = descobrir_anguloPino(destino);

    int anguloVertical = descobrir_anguloServoVertical(origem, nivelOrigem);
    int anguloHorizontal= descobrir_anguloServoHorizontal(origem, nivelOrigem); 

    int anguloVerticalRecuo = descobrir_anguloServoVertical(origem, 4);
    int anguloHorizontalRecuo = descobrir_anguloServoHorizontal(origem, 4);

    int anguloVerticalSoltura = descobrir_anguloServoVertical(destino, 4);
    int anguloHorizontalSoltura = descobrir_anguloServoHorizontal(destino, 4);


    // -------------------------------------------------------------
    // ETAPA 1: Ir até o pino de Origem em posição elevada
    // -------------------------------------------------------------
    braco_goat.posicao_padrao();

    braco_goat.moverGarra(GARRA_ABERTA);
    // braco_goat.moverVertical(anguloVerticalRecuo);
    // braco_goat.moverHorizontal(anguloHorizontalRecuo);
    braco_goat.moverBase(anguloPinoOrigem);

    // -------------------------------------------------------------
    // ETAPA 2: Descer para a altura do disco e Coletar
    // -------------------------------------------------------------
    // braco_goat.moverHorizontal(anguloHorizontal);
    // braco_goat.moverVertical(anguloVertical);
    braco_goat.moverVerticalEHorizontal(anguloVertical, anguloHorizontal);
    braco_goat.moverGarra(GARRA_FECHADA);

    // -------------------------------------------------------------
    // ETAPA 3: Elevar o braço (Recuo / Altura Segura para transporte)
    // -------------------------------------------------------------
    // braco_goat.moverHorizontal(anguloHorizontalRecuo);
    // braco_goat.moverVertical(anguloVerticalRecuo);
    braco_goat.moverVerticalEHorizontal(anguloVerticalRecuo, anguloHorizontalRecuo);
    

    // -------------------------------------------------------------
    // ETAPA 4: Giro da Base e Soltura do Disco
    // -------------------------------------------------------------
    braco_goat.moverBase(anguloPinoDestino);
    // braco_goat.moverVertical(anguloVerticalSoltura);
    // braco_goat.moverHorizontal(anguloHorizontalSoltura);
    // braco_goat.moverHorizontal(anguloVerticalSoltura-10);
    braco_goat.moverVerticalEHorizontal(anguloVerticalSoltura, anguloHorizontalSoltura);
    braco_goat.moverGarra(GARRA_ABERTA); // aqui é pra soltar o disco do alto

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