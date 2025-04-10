#ifndef LIDER_EQUIPO_HPP
#define LIDER_EQUIPO_HPP

#include "../Manager.hpp"

class LiderEquipo : public Manager {
    public:
        LiderEquipo(int ant, int sal, string nom, int bonus);
};

#endif