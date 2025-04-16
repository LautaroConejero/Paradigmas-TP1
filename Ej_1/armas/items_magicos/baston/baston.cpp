#include "baston.hpp"

baston::baston() :
    Item_magicos("Baston", 100, 11, 5) {
}

string baston::Get_calidad() const {
    return "Mistico";
}

int baston::rafaga_magica() {
    durabilidad--;
    int daño = daño_magico;

    int crit = rand() % 100;
    if (crit < chance_critico) {
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

int baston::canalizacion_elemental() {
    durabilidad -= 2;
    int daño = daño_magico + 6;

    int crit = rand() % 100;
    if (crit < chance_critico) {
        ignorar_armadura = true;
        daño *= 2;
    } else {
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

pair<int, TIPO_DAÑO> baston::Atacar() {
    ignorar_armadura = false;
    if (durabilidad <= 0) {
        cout << "El baston esta roto y no puede atacar." << endl;
        return {0, MAGICO};
    }

    int daño = 0;
    int ataque = rand() % 2;
    if (ataque == 0){
        daño = rafaga_magica();
    }
    else {
        daño = canalizacion_elemental();
    }
    return {daño, MAGICO};
}
