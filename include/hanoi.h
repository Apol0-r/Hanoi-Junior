#ifndef HANOI_H
#define HANOI_H

#define PINO_ESQUERDO 107
#define PINO_CENTRAL 96
#define PINO_DIREITO 85



#define NIVEL_4_VERTICAL 0
#define NIVEL_3_VERTICAL 142
#define NIVEL_2_VERTICAL 0
#define NIVEL_1_VERTICAL 0

#define NIVEL_4_HORIZONTAL 0
#define NIVEL_3_HORIZONTAL 146
#define NIVEL_2_HORIZONTAL 0
#define NIVEL_1_HORIZONTAL 0

#include "braco_robotico.h"

int descobrir_anguloPino(int pino);
int descobrir_anguloServoVertical(int nivel);
int descobrir_anguloServoHorizontal(int nivel);

bool moverDisco(int origem, int destino, BracoRobotico &braco_goat);
bool resolverHanoi(int n, int origem, int destino, int aux, BracoRobotico &braco_goat);

#endif