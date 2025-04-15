#ifndef ARMA_HPP
#define ARMA_HPP

enum TIPO_DAÑO{
    FISICO,
    MAGICO
};

enum EFFECTO{
    PARALIZAR,
    CONFUSION,
    MIEDO,
    ENVENENAR,
    QUEMADURA,
    HEMORRAGIA,
    POTENCIAR_ALIADO,
    PROTECCION,
    INMORTALIDAD,
    NINGUNO
};


#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <cstdlib>

using namespace std;

class arma{    
    public:
        virtual string Get_nombre() const = 0;
        virtual int Get_durabilidad() const = 0;
        virtual int Get_daño_fisico() const = 0;
        virtual int Get_daño_magico() const = 0;
        virtual pair<int, TIPO_DAÑO> Atacar() = 0;  
        
};

#endif

