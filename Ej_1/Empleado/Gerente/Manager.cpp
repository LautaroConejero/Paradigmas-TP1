#include "Manager.hpp"

Manager::Manager(int ant, int sal, string nom, int bonus): 
Empleado(nom, "Gerente", ant, sal), bonus(bonus) {}

bool Manager::updateBono(float nuevoBono) {
    if (nuevoBono < 0 || nuevoBono <= this->bonus) {
        return false;
    }
    this->bonus = nuevoBono;
    return true;
}

float Manager::getBono() const {
    return this->bonus;
}

bool Manager::setLevel(string nuevoNivel) {
    if (nuevoNivel != "Alto" && nuevoNivel != "Medio" && nuevoNivel != "Bajo") {
        return false;
    }
    this->level = nuevoNivel;
    return true;
}