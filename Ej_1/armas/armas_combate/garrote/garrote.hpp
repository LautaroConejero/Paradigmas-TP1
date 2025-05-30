#ifndef GARROTE_HPP
#define GARROTE_HPP

#include "../armas_combate.hpp"

class garrote : public ArmaCombate {
    private:
        bool astillado = false;        
    public:
        garrote();
        ~garrote() = default;
        string Get_tipo() const override;
        
        void astillar_garrote();
        int golpe_cargado();
        int aplastamiento();
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif