#ifndef ARMA_HPP
#define ARMA_HPP

enum TIPO_DAÑO{
    FISICO,
    MAGICO
};

#include <iostream>
#include <string>
#include <memory>
#include <utility>
using namespace std;

class arma{    
    public:
        virtual string Get_nombre() = 0;
        virtual int Get_durabilidad() = 0;
        virtual int Get_daño_fisico() = 0;
        virtual int Get_daño_magico() = 0;
        virtual pair<int, TIPO_DAÑO> Elegir_ataque() = 0;  
        
};

#endif