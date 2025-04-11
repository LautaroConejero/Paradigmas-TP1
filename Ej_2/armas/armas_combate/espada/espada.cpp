#include "espada.hpp"

espada::espada() : 
ArmaCombate("Espada", 12, 100, 20) {
}

void espada::cortar_espada() {
    espada_cortada = true;
    int proba_hemorragia = rand() % 100;
    if (proba_hemorragia < 50) {
        cout << "La espada ahora aplica Hemorragia." << endl;
        efecto_arma = HEMORRAGIA;
    } 
    cout << "La espada ha sido cortada. " << endl;
    cout << "Hace mas daño fisico, pero se gasta mas rapido" << endl;

}

int espada::puntazo_al_pecho() {
    if (durabilidad > 0) {
        ignorar_armadura = true;
        
        if (espada_cortada) {
            durabilidad -= 3;
            return daño_fisico * 2.5;
        }
        durabilidad -= 2;
        if (durabilidad <= 20){
            cortar_espada();
        }
        return daño_fisico * 2;
    } else {
        cout << "La espada está rota." << endl;
        return 0;
    }
}

int espada::doble_corte(){
    if (durabilidad > 0) {
        ignorar_armadura = false;
        
        if (espada_cortada) {
            durabilidad -= 2;
            int daño = daño_fisico * 1.5;
            int proba_doble = rand() % 100;
            if (proba_doble < 30) {
                cout << "El ataque ha sido doble." << endl;
                return daño * 1.5;
            } else {
                return daño;
            }
        }
        int daño = daño_fisico * 1;
            int proba_doble = rand() % 100;
            if (proba_doble < 30) {
                cout << "El ataque ha sido doble." << endl;
                return daño * 1.5;
            } else {
                return daño;
            }

    }
    cout << "La espada está rota." << endl;
    return 0;
}

pair<int, TIPO_DAÑO> espada::Atacar() {
    int ataque = rand () % 2;
    int daño = 0;
    if (ataque == 0) {
        daño = puntazo_al_pecho();
    } else {
        daño = doble_corte();
    }
    int critico = rand() % 100;
    if (critico < chance_critico) {
        cout << "Golpe critico!" << endl;
        daño *= 2;
    }
    return {daño, FISICO};
} 