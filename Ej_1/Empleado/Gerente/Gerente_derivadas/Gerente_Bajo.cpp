#include "Gerente_Bajo.hpp"

GerenteBajo::GerenteBajo(int ant, int sal, string nom, int bonus):
    Manager(ant, sal, nom, bonus) {
    setLevel("Bajo");
}