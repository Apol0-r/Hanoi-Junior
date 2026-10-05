#ifndef HANOI_H
#define HANOI_H

#define PINO_ESQUERDO 106
#define PINO_CENTRAL 96
#define PINO_DIREITO 87

#define NIVEL_4_VERTICAL_CENTRAL 162
#define NIVEL_3_VERTICAL_CENTRAL 145
#define NIVEL_2_VERTICAL_CENTRAL 139
#define NIVEL_1_VERTICAL_CENTRAL 129

#define NIVEL_4_HORIZONTAL_CENTRAL 135
#define NIVEL_3_HORIZONTAL_CENTRAL 146
#define NIVEL_2_HORIZONTAL_CENTRAL 154
#define NIVEL_1_HORIZONTAL_CENTRAL 164

#define NIVEL_4_VERTICAL 165
#define NIVEL_3_VERTICAL 148
#define NIVEL_2_VERTICAL 141
#define NIVEL_1_VERTICAL 130

#define NIVEL_4_HORIZONTAL 138
#define NIVEL_3_HORIZONTAL 147
#define NIVEL_2_HORIZONTAL 155
#define NIVEL_1_HORIZONTAL 165

#include "braco_robotico.h"

int descobrir_anguloPino(int pino);
int descobrir_anguloServoVertical(int pino, int nivel);
int descobrir_anguloServoHorizontal(int pino, int nivel);

bool moverDisco(int origem, int destino, BracoRobotico &braco_goat);
bool resolverHanoi(int n, int origem, int destino, int aux, BracoRobotico &braco_goat);

#endif