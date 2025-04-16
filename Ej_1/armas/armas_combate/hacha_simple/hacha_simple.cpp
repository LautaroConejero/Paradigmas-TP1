#include "hacha_simple.hpp"

hacha_simple::hacha_simple() :
ArmaCombate("Hacha simple", 10, 75, 10) {
}

string hacha_simple::Get_tipo() const {
    return "Arma perforante";
}

int hacha_simple::corte_rapido() {
    durabilidad--;
    int daño = daño_fisico;
    return daño;
}

int hacha_simple::corte_dirigido() {
    durabilidad -= 2;
    int daño = daño_fisico + 3;

    int prob = rand() % 100;
    if (prob < chance_critico * 100) {
        cout << "¡Corte crítico dirigido! El enemigo queda atemorizado." << endl;
        efecto_arma = MIEDO; 
        daño *= 2;
    }
    return daño;
}

pair<int, TIPO_DAÑO> hacha_simple::Atacar() {
    int daño = 0;
    int ataque = rand() % 2;
    if (ataque == 0) {
        daño = corte_rapido();
    } else {
        daño = corte_dirigido();
    }
    return make_pair(daño, FISICO);
}


