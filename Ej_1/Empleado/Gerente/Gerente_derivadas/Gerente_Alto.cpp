#include "Gerente_Alto.hpp"

GerenteAlto::GerenteAlto(int ant, int sal, string nom, int bonus):
    Manager(ant, sal, nom, bonus) {
    setLevel("Alto");
}