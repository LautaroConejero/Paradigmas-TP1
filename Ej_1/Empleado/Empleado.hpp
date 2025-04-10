#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <iostream>
#include <string>
using namespace std;

class Empleado {
    private:
        int antiguedad;
        float salario;

    public:
        string nombre;
        string puesto;
        Empleado(string n, string p, int a, float s);
        bool updateSalario(float nuevoSalario);
        float getSalario() const;
};

#endif