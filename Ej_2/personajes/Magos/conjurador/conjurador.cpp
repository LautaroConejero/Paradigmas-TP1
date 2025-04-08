#include "conjurador.hpp"

conjurador::conjurador(string n):
Magos(15, 25, 85, 85, 25, n),
invocaciones_maximas(2){}

string conjurador::Get_grupo() const {
    return "Conjurador";
}