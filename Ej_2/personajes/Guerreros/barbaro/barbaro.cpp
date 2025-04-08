#include "barbaro.hpp"

barbaro::barbaro(string n):
Guerreros(10, 5, 40, 100, 100, n),
berserker(false), furia(0) {}

string barbaro::Get_grupo() const {
    return "Barbaro";
}