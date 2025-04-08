#include "gladiador.hpp"

gladiador::gladiador(string n):
Guerreros(20, 10, 35, 90, 90, n),
honor(0), adrenalina(0), capacidad_esquivar(20), furia_activada(false) {}

string gladiador::Get_grupo() const {
    return "Gladiador";
}