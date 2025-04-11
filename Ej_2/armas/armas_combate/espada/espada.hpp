#ifndef ESPADA_HPP
#define ESPADA_HPP

#include "../armas_combate.hpp"
class espada : public ArmaCombate {
    bool espada_cortada = false;
    public:
        espada();
        int puntazo_al_pecho();
        int doble_corte();
        void cortar_espada();
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif