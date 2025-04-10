#include "Departamento.hpp"

Departamento::Departamento(string nombre, string ubicacion) : 
nombre(nombre), ubicacion(ubicacion) {
}

static int Departamento::contarEmpleados() {
    return CantEmpleadosDepts;
}

vector<Empleado> Departamento::getEmpleados() const {
    return empleados;
}

bool Departamento::contratarEmpleados(Empleado empleado) {
    for (size_t i = 0; i < empleados.size(); i++) {
        if (empleados[i].nombre == empleado.nombre) {
            cout << "El empleado ya existe en el departamento." << endl;
            return false;
        }
    }
    empleados.push_back(empleado);
    cout << "El empleado " << empleado.nombre << " ha sido contratado." << endl;
    CantEmpleadosDepts++;
    return true;
}

bool Departamento::despedirEmpleados(Empleado empleado) {
    for (size_t i = 0; i < empleados.size(); i++) {
        if (empleados[i].nombre == empleado.nombre) {
            empleados.erase(empleados.begin() + i);
            cout << "El empleado " << empleado.nombre << " ha sido despedido." << endl;
            CantEmpleadosDepts--;
            return true;
        }
    }
    cout << "El empleado no existe en el departamento." << endl;
    return false;
}
