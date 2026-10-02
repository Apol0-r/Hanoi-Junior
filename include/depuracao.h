#ifndef DEPURACAO_H
#define DEPURACAO_H

#include <Arduino.h>
#include "braco_robotico.h"

/** 
exibirStatus literalmente exibe a posição de cada servo motor (Base, Garra, Vertical, Horizontal). Seu funcionamento
depende de getters que foram implementados na própria classe BracoRobotico. 
*/
void exibirStatus(const BracoRobotico &braco_goat);


/** 
verificarOperacao é uma função que verifica se a ação que você está tentando executar foi um sucesso ou não.
Sua implementabilidade requer que as funções de ação retornem um bool. (Dar um olhada nas funções inicializar 
e posicao_padrao em braco_robotico.h)
*/
void verificarOperacao(const char *nome_operacao, bool sucesso);


#endif
