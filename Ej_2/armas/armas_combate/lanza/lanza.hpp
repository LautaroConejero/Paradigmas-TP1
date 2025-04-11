#ifndef LANZA_HPP
#define LANZA_HPP

#include "../armas_combate.hpp"

class lanza : public ArmaCombate {
    private:
        bool lanza_arrojada = false;
        int tiempo_espera = 0;
        bool lanza_doble = false;      
    public:
        lanza();
        void cortar_lanza_mitad();

        int arrojar_lanza();
        int estocada();

        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif