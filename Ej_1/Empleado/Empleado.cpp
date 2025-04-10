#include "Empleado.hpp"

Empleado::Empleado(string n, string p, int a, float s) : 
 antiguedad(a), salario(s),
 nombre(n), puesto(p) {}

float Empleado::getSalario() const {
    return this->salario;
}

bool Empleado::updateSalario(float nuevoSalario) {
    if (nuevoSalario > 0 || nuevoSalario <= salario) {
        this->salario = nuevoSalario;
        return true;
    }
    return false;
}