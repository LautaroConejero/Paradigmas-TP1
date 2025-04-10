#include "Entidades_organizativas.hpp"

EntidadOrganizativa::EntidadOrganizativa(string nom) : nombre(nom) {}

int EntidadOrganizativa::ContarSubentidades() {
    int total = 0;
    for (size_t i = 0; i < entidades.size(); ++i) {
        total += 1;
    }
    return total;
}