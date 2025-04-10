#include "Lider_Equipo.hpp"

LiderEquipo::LiderEquipo(int ant, int sal, string nom, int bonus):
Manager(ant, sal, nom, bonus) {
setLevel("Lider de equipo");
}