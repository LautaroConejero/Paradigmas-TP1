#include "lanza.hpp"

lanza::lanza() :
ArmaCombate("Lanza", 9, 85, 10) {
}

void lanza::cortar_lanza_mitad() {
    if (durabilidad > 70) {
        lanza_doble = true;
        daño_fisico = daño_fisico * 2.5;
        durabilidad -= 20;
    }
    return;    
}

int lanza::arrojar_lanza() {
    if (durabilidad > 0) {
        if (lanza_arrojada == false) {
            lanza_arrojada = true;
            tiempo_espera = 2;

            durabilidad -= 10;
            if(lanza_doble){
                durabilidad -= 10;
            }

            efecto_arma = HEMORRAGIA;
            return daño_fisico*0.75;
            
        } else {
            cout << "La lanza ya ha sido arrojada." << endl;
            return 0;
        }
    }
    cout << "La lanza está rota." << endl;
    return 0;
}


int lanza::estocada() {
    if (durabilidad > 0) {
        if (lanza_arrojada == false) {
            durabilidad -= 5;
            if(lanza_doble){
                durabilidad -= 5;
            }

            ignorar_armadura = true;
            return daño_fisico;
        } else {
            cout << "La lanza ya ha sido arrojada." << endl;
            tiempo_espera--;
            if (tiempo_espera == 0) {
                lanza_arrojada = false;
                cout << "La lanza ha vuelto." << endl;
            }
            return 0;
        }
    } else {
        cout << "La lanza está rota." << endl;
        return 0;
    }
}

pair<int, TIPO_DAÑO> lanza::Atacar() {
    efecto_arma = NINGUNO;
    ignorar_armadura = false;

    int ataque = rand() % 2;
    int daño = 0;
    if (ataque == 0) {
        daño = arrojar_lanza();
    } else {
        daño = estocada();
    }

    int critico = rand() % 100;
    if (critico < chance_critico) {
        cout << "Golpe critico!" << endl;
        daño *= 2;
    }
    return {daño, FISICO};
}
