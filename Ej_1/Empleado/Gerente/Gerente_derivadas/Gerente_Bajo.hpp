#ifndef GERENTE_BAJO_HPP
#define GERENTE_BAJO_HPP

#include "../Manager.hpp"

class GerenteBajo: public Manager {
    public:
        GerenteBajo(int ant, int sal, string nom, int bonus);
};

#endif