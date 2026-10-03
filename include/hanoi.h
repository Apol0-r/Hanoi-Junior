#ifndef HANOI_H
#define HANOI_H

#define PINO_ESQUERDO 75
#define PINO_CENTRAL 93
#define PINO_DIREITO 108

#define NIVEL_3_VERTICAL 165
#define NIVEL_2_VERTICAL 0
#define NIVEL_1_VERTICAL 0

#define NIVEL_3_HORIZONTAL 130
#define NIVEL_2_HORIZONTAL 0
#define NIVEL_1_HORIZONTAL 0

#include "braco_robotico.h"

bool moverDisco(int origem, int destino, BracoRobotico &braco_goat);
bool resolverHanoi(int n, int origem, int destino, int aux, BracoRobotico &braco_goat);

#endif