#ifndef HANOI_H
#define HANOI_H


#include "braco_robotico.h"
#include "ferramentas.h"


class TorreHanoi {
    protected:
        int nivelOrigem, nivelDestino,
            anguloPinoOrigem, anguloPinoDestino,
            anguloVertical, anguloHorizontal,
            anguloVerticalRecuo, anguloHorizontalRecuo,
            anguloVerticalSoltura, anguloHorizontalSoltura;


        int discosNoPino[3];
        BracoRobotico &braco_goat;
        FerramentasMedicao medir;

    public:

        TorreHanoi(int posicao_torre_inicial, BracoRobotico &braco_usado);
        
        void medicaoAngulos(int origem, int destino);

        bool moverDisco(int origem, int destino);

        bool resolverHanoi(int n, int origem, int destino, int aux);

        ~TorreHanoi() {};

};

bool resolverHanoi(int n, int origem, int destino, int aux, TorreHanoi &torre);



#endif