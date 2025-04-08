#include "caballero.hpp"

caballero::caballero(string n):
Guerreros(35, 15, 28, 70, 70, n),
proteccion(false), protegido(nullptr) {}

string caballero::Get_grupo() const {
    return "Caballero";
}