#ifndef DEPARTMENTO_HPP
#define DEPARTMENTO_HPP

#include <iostream>
#include <vector>
#include <string>
#include "../Empleado/Empleado.hpp"
using namespace std;

class Departamento {
    private:
        vector<Empleado> empleados;
        static int CantEmpleadosDepts;
    public:
        string nombre;
        string ubicacion;
        Departamento(string nombre, string ubicacion);

        static int contarEmpleados();
        vector<Empleado> getEmpleados() const;    
        bool contratarEmpleados(Empleado empleado);
        bool despedirEmpleados(Empleado empleado);
};


#endif