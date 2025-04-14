#include "paladin.hpp"

paladin::paladin(): 
Guerreros(30,25,25,70,70, "Thalorín"),
escudo (false), fe(0), vida_fe(0), estamina_fe(0), daño_fe(0) {
}

string paladin::Get_grupo() const {
    return "Paladin";
}

int paladin::Get_vida() const {
    return this->vida + this->vida_fe;
}

string paladin::Get_tipo_guerrero() const {
    return "Guerrero sagrado";
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
    if (protegido) {
        int mitigacion = rand() % 81 + 20; // 20% a 100% de mitigación
        int daño_mitigado = daño * mitigacion / 100; 
        daño -= daño_mitigado;
        cout << Get_nombre() << " está protegido y recibe solo " << daño << " de daño." << endl;
    }

    if (asustado) {
        daño *= 1.3;
        cout << Get_nombre() << " está asustado y recibe daño aumentado." << endl;
    }

    int vida_actual = vida + vida_fe;
    if (ignorar_armadura) {
        vida -= daño;
    } else {
        if (tipo == FISICO) {
            vida -= daño * (1 - armadura / 100.0);
        } else if (tipo == MAGICO) {
            vida -= daño * (1 - resistencia_magica / 100.0);
        }
    }
    cout << "" << Get_nombre() << " recibe " << vida_actual - (vida + vida_fe) << " de daño." << endl;

    if (vida <= 0) {
        this->morir(0);
        cout << Get_nombre() << " ha muerto." << endl;
    }
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
    if (paralizado) {
        cout << Get_nombre() << " está paralizado y no puede atacar este turno." << endl;
        return;
    }

    if (confundido) {
        int prob = rand() % 100;
        if (prob < 35) {
            recibir_ataque(daño_fisico + daño_magico, FISICO, false);
            cout << Get_nombre() << " se ha atacado a sí mismo por confusión." << endl;
            return;
        }
    }

    int daño;
    if (armas.first == nullptr) {
        daño = daño_fisico;
    }
    else if (armas.second == nullptr) {
        daño = daño_fisico + armas.first->Get_daño_fisico();
    } else {
        daño = daño_fisico + armas.first->Get_daño_fisico() + armas.second->Get_daño_fisico();
    }

    if (quemado) {
        daño *= 0.8;
        cout << Get_nombre() << " está quemado y su daño fue reducido." << endl;
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
    if (paralizado) {
        cout << Get_nombre() << " está paralizado y no puede atacar este turno." << endl;
        return;
    }

    if (confundido) {
        int prob = rand() % 100;
        if (prob < 35) {
            recibir_ataque(daño_fisico + daño_magico, FISICO, false);
            cout << Get_nombre() << " se ha atacado a sí mismo por confusión." << endl;
            return;
        }
    }

    if (armas.first == nullptr && armas.second == nullptr) {
        cout << Get_nombre() << " no tiene armas equipadas." << endl;
        return;
    }

    cout << "Con qué arma quieres atacar?" << endl;
    if (armas.first != nullptr) {
        cout << "1. " << armas.first->Get_nombre() << endl;
    }
    if (armas.second != nullptr) {
        cout << "2. " << armas.second->Get_nombre() << endl;
    }
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 2) {
        cout << "Opción inválida. Elige nuevamente." << endl;
        cin >> opcion;
    }

    pair<int, TIPO_DAÑO> daño;
    if (opcion == 1) {
        daño = armas.first->Atacar();
    } else {
        daño = armas.second->Atacar();
    }

    if (daño.second == FISICO) {
        daño.first += daño_fisico;
    } else {
        daño.first += daño_magico;
    }

    if (quemado) {
        daño.first *= 0.8;
        cout << Get_nombre() << " está quemado y su daño fue reducido." << endl;
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