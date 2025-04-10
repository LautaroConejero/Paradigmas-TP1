#ifndef GARROTE_HPP
#define GARROTE_HPP

#include "../armas_combate.hpp"

class garrote : public ArmaCombate {
    private:
        bool astillado = false;        
    public:
        garrote(int df, int d, float c);

        void astillar_garrote();
        int golpe_cargado();
        int aplastamiento();
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif