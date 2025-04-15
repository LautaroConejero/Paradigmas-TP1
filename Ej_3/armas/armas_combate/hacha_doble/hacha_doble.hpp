#ifndef HACHA_DOBLE_HPP
#define HACHA_DOBLE_HPP

#include "../armas_combate.hpp"

class hacha_doble : public ArmaCombate {
    private:
        int doble_golpe;
    public:
        hacha_doble();
        string Get_tipo() const override;
        int swing();
        int doble_corte();
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif