#ifndef HACHA_SIMPLE_HPP
#define HACHA_SIMPLE_HPP

#include "../armas_combate.hpp"

class hacha_simple : public ArmaCombate {
    public:
        hacha_simple(int df, int d, float c);
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif