#include "ferramentas.h"


// ===========================================

int FerramentasMedicao::anguloPino(int pino) {
    switch (pino) {
        case 1: return PINO_ESQUERDO;            
        case 2: return PINO_CENTRAL;            
        case 3: return PINO_DIREITO;       
    }
}

int FerramentasMedicao::anguloServoVertical(int pino, int nivel) {
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

int FerramentasMedicao::anguloServoHorizontal(int pino, int nivel) {
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

// ===========================================

void verificarOperacao(const char *nome_operacao, bool sucesso) {

    Serial.println("===============================");

    Serial.print("Operacao: ");
    Serial.println(nome_operacao);
    
    if (sucesso) {
        Serial.println("Status: SUCESSO");
    } else {
        Serial.println("Status: FALHA");
    }

    Serial.println("===============================");

}

// ===========================================

FerramentasMovimentacao::FerramentasMovimentacao() {}

int FerramentasMovimentacao::mover(Servo &servo_alvo, int ANG_inicial, int ANG_final) {
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
    
    delay(200);
    return ANG_final;
}