#include "armas.hpp"

#ifndef ARMAS_COMBATE_HPP
#define ARMAS_COMBATE_HPP

class ArmaCombate : public Arma {
    protected:
        float daño;
        int durabilidad;
        float chance_critico;
    
    public:
        virtual  ataque_cargado();
}

#endif