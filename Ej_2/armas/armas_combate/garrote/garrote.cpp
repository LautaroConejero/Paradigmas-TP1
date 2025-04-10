#include "garrote.hpp"

garrote::garrote(string n, int df, int d, float c) :
ArmaCombate("Garrote", df, d, c) {
}

void garrote::astillar_garrote() {
    if (durabilidad < 20) {
        astillado = true;
        daño_fisico = daño_fisico * 2;
    }
    return;    
}

int garrote::golpe_cargado() {
    efecto_arma = NINGUNO;
    int prob_pegar = rand() % 100;
    if (prob_pegar < 50) {
        return daño_fisico * 2;
    } else {
        durabilidad -= 0.5*durabilidad - 10;
        astillar_garrote(); 
        return 0;
    }
}

int garrote::aplastamiento() {
    if (durabilidad <= 0) {
        cout << "El garrote está roto." << endl;
        return 0;
    }

    int daño = daño_fisico + 10;
    ignorar_armadura = true;

    if (astillado) {
        durabilidad -= 3;
        if (rand() % 100 < 30) {
            efecto_arma = HEMORRAGIA;
            cout << "Aplica hemorragia." << endl;
        } else {
            efecto_arma = NINGUNO;
        }
    } else {
        durabilidad -= 2;
        efecto_arma = NINGUNO;
    }

    cout << "Aplastamiento ignora la armadura." << endl;
    astillar_garrote();
    return daño;
}

pair<int, TIPO_DAÑO> garrote::Atacar(){
    int ataque = rand () % 2;
    int daño = 0;
    if (ataque == 0) {
        daño = golpe_cargado();
    } else {
        daño = aplastamiento();
    }
    int critico = rand() % 100;
    if (critico < chance_critico) {
        cout << "Golpe critico!" << endl;
        daño *= 2;
    }
    return {daño, FISICO};
}