#ifndef HACHA_DOBLE_HPP
#define HACHA_DOBLE_HPP

#include "../armas_combate.hpp"

class hacha_doble : public ArmaCombate {
    public:
        hacha_doble(int df, int d, float c);
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif