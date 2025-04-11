#include "amuleto.hpp"

amuleto::amuleto() :
    Item_magicos("Amuleto", 60, 10, 5) {}

int amuleto::pulso_arcano() {
    durabilidad--;

    int daño = daño_magico;
    efecto_arma = NINGUNO;

    int crit = rand() % 100;
    if (crit < chance_critico * 100) {
        daño *= 2;
    }

    switch (encantamiento) {
        case FUEGO: efecto_arma = QUEMADURA; break;
        case AGUA: efecto_arma = CONFUSION; break;
        case TIERRA: efecto_arma = MIEDO; break;
        case AIRE: efecto_arma = PARALIZAR; break;
        case ELECTRICIDAD: efecto_arma = HEMORRAGIA; break;
        default: efecto_arma = NINGUNO; break;
    }

    return daño;
}

int amuleto::estallido_canalizado() {
    durabilidad -= 2;

    int daño = daño_magico + 6;
    efecto_arma = NINGUNO;

    int crit = rand() % 100;
    if (crit < chance_critico) {
        daño *= 2;
    } else {
        // Efecto único si no hay crítico
        switch (encantamiento) {
            case FUEGO: efecto_arma = QUEMADURA; break;
            case AGUA: efecto_arma = CONFUSION; break;
            case TIERRA: efecto_arma = MIEDO; break;
            case AIRE: efecto_arma = PARALIZAR; break;
            case ELECTRICIDAD: efecto_arma = HEMORRAGIA; break;
            default: efecto_arma = NINGUNO; break;
        }
    }

    return daño;
}

pair<int, TIPO_DAÑO> amuleto::Atacar() {
    if (durabilidad <= 0) {
        cout << "El amuleto está roto y no puede atacar." << endl;
        return {0, MAGICO};
    }
    int daño = 0;
    int ataque = rand() % 2;
    if (ataque == 0){
        daño = pulso_arcano();
    }
    else {
        daño = estallido_canalizado();
    }

    return {daño, MAGICO};
}
