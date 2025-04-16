#include "pocion.hpp"

pocion::pocion() :
    Item_magicos("Pocion", 8, 15, 0) {
}

void pocion::exploto() {
    explosion = true;
    durabilidad = 0; // La poción se rompe al explotar
}

string pocion::Get_calidad() const {
    return "Comun";
}

int pocion::explosion_alquimica() {
    durabilidad--;

    int daño;
    int explosion = rand() % 100;
    if (explosion < probabilidad_explotar) {
        exploto();
        daño = (daño_magico + 10)*2;
        ignorar_armadura = true; 
        return daño; // Daño explosivo
        
    }

    daño = daño_magico + (rand() % 5); // daño entre 10–14

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

int pocion::salpicadura_corrosiva() {
    durabilidad -= 2;
    int daño = daño_magico + (rand() % 3); // daño 10–12

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

pair<int, TIPO_DAÑO> pocion::Atacar() {
    if (durabilidad <= 0) {
        return {0, MAGICO};
    }

    int ataque = rand() % 2;
    int daño = 0;
    if (ataque == 0){
        daño = explosion_alquimica();
    }
    else {
        daño = salpicadura_corrosiva();
    }

    int prob_critico = rand() % 100;
    if (prob_critico < chance_critico) {
        daño *= 2; // Duplicar el daño en caso de crítico
        cout << "¡Crítico!" << endl;
    }
    return {daño, MAGICO};
}
