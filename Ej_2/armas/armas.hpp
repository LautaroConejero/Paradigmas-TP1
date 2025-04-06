#ifndef ARMA_HPP
#define ARMA_HPP

#include <iostream>
#include <string>
using namespace std;

class arma{    
    public:
        virtual string Get_nombre() = 0;
        virtual int Get_durabilidad() = 0;
        virtual int Get_daño_fisico() = 0;
        virtual int Get_daño_magico() = 0;    
};

#endif