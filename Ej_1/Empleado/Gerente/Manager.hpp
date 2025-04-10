#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "../Empleado.hpp"

class Manager: public Empleado {
    protected:
        int bonus;
        string level;
    public:
        Manager(int ant, int sal, string nom, int bonus);
        bool updateBono(float nuevoBono); 
        float getBono() const;
        bool setLevel(string nuevoNivel);
};

#endif