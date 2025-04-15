#include "hacha_doble.hpp"

hacha_doble::hacha_doble() :
ArmaCombate("Hacha doble", 13, 65, 15),
doble_golpe(25) {
}

string hacha_doble::Get_tipo() const {
    return "Arma pesada";
}

int hacha_doble::swing() {
    durabilidad -= 2;
    int daño = daño_fisico + 5;
    int prob = rand() % 100;

    efecto_arma = HEMORRAGIA;
    if (prob < doble_golpe) {
        cout << "El hacha doble ha hecho un doble golpe." << endl;
        return daño * 2;
    } else {
        return daño;
    }
}

int hacha_doble::doble_corte(){
    durabilidad -= 4;

    int daño = daño_fisico + 10;
    int prob = rand() % 100;

    ignorar_armadura = true;
    if (prob < doble_golpe) {
        cout << "El hacha doble ha hecho un doble golpe." << endl;
        daño = daño * 2;
    }
    return daño;
}

pair<int, TIPO_DAÑO> hacha_doble::Atacar() {
    efecto_arma = NINGUNO;
    ignorar_armadura = false;

    if (durabilidad <= 0) {
        cout << "El hacha doble está rota." << endl;
        return make_pair(0, FISICO);
    }

    int ataque = rand() % 2;
    int daño = 0;
    if (ataque == 0) {
        daño = swing();
    } else {
        daño = doble_corte();
    }
    int prob = rand() % 100;
    if (prob < chance_critico) {
        cout << "El hacha doble ha hecho un golpe crítico." << endl;
        daño *= 2;
    }
    return make_pair(daño, FISICO);
}