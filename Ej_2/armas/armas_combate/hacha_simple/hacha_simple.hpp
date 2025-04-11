#ifndef HACHA_SIMPLE_HPP
#define HACHA_SIMPLE_HPP

#include "../armas_combate.hpp"

class hacha_simple : public ArmaCombate {
    public:
        hacha_simple();
        string Get_tipo() const override;
        int corte_rapido();
        int corte_dirigido();
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif