#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <iostream>
#include <string>
#include <memory>
#include "../armas/armas.hpp"
#include <vector>

using namespace std;

class personaje{
    public:
        virtual string Get_nombre() = 0;
        virtual int Get_vida() = 0;
        virtual int Get_armadura() = 0;
        virtual int Get_resistencia_m() = 0;
        virtual void recibir_ataque(int daño) = 0;
        // virtual void recibir_efecto() = 0;
        virtual void equipar_armas(shared_ptr<arma> a) = 0;
        virtual string Get_armas() = 0;
        virtual bool Esta_vivo() = 0;
        virtual int ataque_rapido() = 0;
        virtual int atacar_con_arma();
        // virtual int usar_habilidad() = 0;
};

#endif