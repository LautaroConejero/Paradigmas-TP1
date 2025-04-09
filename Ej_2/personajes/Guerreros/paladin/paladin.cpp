#include "paladin.hpp"

paladin::paladin(string n): 
Guerreros(30,25,25,70,70, n),
escudo (false), fe(0), vida_fe(0), estamina_fe(0), daño_fe(0) {
}

string paladin::Get_grupo() const {
    return "Paladin";
}

int paladin::Get_vida() const {
    return this->vida + this->vida_fe;
}


void paladin::usar_escudo() {
    if (estamina < 40){
        cout << "No hay suficiente estamina." << endl;
        return;
    }
    escudo = true;
    estamina -= 40;
    cout << "El paladin alza su escudo." << endl;
    cout << "Es capaz de proteger un ataque. por completo." << endl;
    cout << "el daño que hara sera reducido" << endl;
    return;
}

void paladin::recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) {
    if (escudo == true) {
        escudo = false;
        cout << "El paladin ha protegido el ataque." << endl;
        return;
    }
    if (ignorar_armadura == true) {
        this->vida -= daño;
        return;
    }
    if (tipo == FISICO) {
        this->vida -= daño*(1 - this->armadura/100.0);
    } else if (tipo == MAGICO) {
        this->vida -= daño*(1 - this->resistencia_magica/100.0);
    }
    if (this->vida < 0) {
        this->vida = 0;
        this->vivo = false;
    }
    return;
}

void paladin::aplicar_fe() {
    int nueva_vida_fe = vida_maxima * fe / 100;
    int nueva_estamina_fe = estamina_maxima * fe / 100;

    vida_maxima -= vida_fe;
    estamina_maxima -= estamina_fe;

    vida_fe = nueva_vida_fe;
    estamina_fe = nueva_estamina_fe;


    vida_maxima += vida_fe;
    estamina_maxima += estamina_fe;

    vida += vida_fe;
    estamina += estamina_fe;

    if (vida > vida_maxima) {
        vida = vida_maxima;
    }
    if (estamina > estamina_maxima) {
        estamina = estamina_maxima;
    }
    return;
}

void paladin::aumentar_la_fe(int daño_infligido){
    this->fe += daño_infligido*0.1;
    if (this->fe > 100){
        this->fe = 100;
    }
    cout << "El paladin ha aumentado su fe." << endl;
    cout << "Ahora es mas resistente." << endl;
    aplicar_fe();
    return;

}

void paladin::ataque_rapido(shared_ptr<personaje> enemigo) {
    int daño;
    if (armas.first == nullptr) {
        daño = daño_fisico;
    }
    else if (armas.second == nullptr) {
        daño = daño_fisico + armas.first->Get_daño_fisico();
    } else {
        daño = daño_fisico + armas.first->Get_daño_fisico() + armas.second->Get_daño_fisico();
    }
    int daño_total = daño + daño_fe;
    if (escudo){
        daño_total = daño_total/5;
        aumentar_la_fe(daño_total);
        enemigo->recibir_ataque(daño_total, FISICO, false);
    }
    aumentar_la_fe(daño_total);
    enemigo->recibir_ataque(daño_total, FISICO, false);
    return;
}

void paladin::atacar_con_arma(shared_ptr<personaje> enemigo) {
    cout << "Con que arma quieres atacar?" << endl;
    if (armas.first != nullptr) {
        cout << "1. " << armas.first->Get_nombre() << endl;
    }
    if (armas.second != nullptr) {
        cout << "2. " << armas.second->Get_nombre() << endl;
    }
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 2) {
        cout << "Opcion invalida. Elige una opcion valida." << endl;
        cin >> opcion;
    }
    pair<int, TIPO_DAÑO> daño;
    if (opcion == 1) {
        daño = armas.first->Elegir_ataque();
    } else if (opcion == 2) {
        daño = armas.second->Elegir_ataque();
    }
    if (daño.second == FISICO) {
        daño.first += this->daño_fisico;
    }
    else{
        daño.first += this->daño_magico;
    }
    int daño_total = daño.first + daño_fe;
    if (escudo){
        daño_total = daño_total/5;
        aumentar_la_fe(daño_total);
        enemigo->recibir_ataque(daño_total, daño.second, false);
    }
    aumentar_la_fe(daño_total);
    enemigo->recibir_ataque(daño_total, daño.second, false);
    return;
}

void paladin::bendecir_armas() {
    if (this->fe >= 15) {
        this->fe -= 10;
        cout << "Las armas del paladin" << Get_nombre() << "han sido bendecidas con fe." << endl;
        daño_fe = 6;
    } else {
        cout << "No hay suficiente fe para bendecir las armas." << endl;
    }
    aplicar_fe();
    return;
}

void paladin::golpe_divino(shared_ptr<personaje> enemigo) {
    if (escudo){
        cout << "El paladin no puede usar el golpe divino mientras tiene el escudo activado." << endl;
        return;
    }
    if (this->fe >= 35) {
        cout << "El paladin ha llamado a la luz para hacer un golpe divino." << endl;
        enemigo->recibir_ataque(35+this->daño_fe, MAGICO, true);
        this->fe -= 35;
        aplicar_fe();
    } else {
        cout << "No hay suficiente fe para usar el golpe divino." << endl;
    }
    return;
}