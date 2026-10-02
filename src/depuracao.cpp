#include "depuracao.h"

void exibirStatus(const BracoRobotico &braco_goat) {

    Serial.println("===============================");

    Serial.print("Base: ");
    Serial.println(braco_goat.getPOS_base());

    Serial.print("Garra: ");
    Serial.println(braco_goat.getPOS_garra());

    Serial.print("Vertical: ");
    Serial.println(braco_goat.getPOS_vertical());

    Serial.print("Horizontal: ");
    Serial.println(braco_goat.getPOS_horizontal());

    Serial.println("===============================");
}

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