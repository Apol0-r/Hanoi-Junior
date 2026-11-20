#ifndef FERRAMENTAS_H
#define FERRAMENTAS_H

#include <Arduino.h>
#include "braco_robotico.h"
#include "defines.h"

void verificarOperacao(const char *nome_operacao, bool sucesso);

class FerramentasExibicao {
    public:
        FerramentasExibicao() {};
        void exibirStatus(const BracoRobotico &braco_goat);
        void verificarOperacao(const char *nome_operacao, bool sucesso);
};

class FerramentasMovimentacao {
    public: 
        FerramentasMovimentacao() {};
        int mover(Servo &servo_alvo, int ANG_inicial, int ANG_final);
        
};

class FerramentasMedicao {

    public: 
        FerramentasMedicao() {};
        int anguloPino(int pino);
        int anguloServoVertical(int pino, int nivel);
        int anguloServoHorizontal(int pino, int nivel);

};


#endif
