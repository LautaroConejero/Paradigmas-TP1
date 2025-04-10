#include "Gerente_Medio.hpp"

GerenteMedio::GerenteMedio(int ant, int sal, string nom, int bonus):
    Manager(ant, sal, nom, bonus) {
    setLevel("Medio");
}
