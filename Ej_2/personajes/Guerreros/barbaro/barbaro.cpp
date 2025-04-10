#include "barbaro.hpp"
#include "../../../../Ej_3/Equipos.hpp"

barbaro::barbaro(string n):
Guerreros(10, 5, 40, 100, 100, n), furia(0) {}

string barbaro::Get_grupo() const {
    return "Barbaro";
}

void barbaro::aumentar_furia(int daño_infligido) {
    this->furia += daño_infligido*0.3;
    cout << "El barbaro aumento su furia" << endl;
    aplicar_bonuses_por_furia();
    return;
}

void barbaro::aplicar_bonuses_por_furia() {
    // Quitar bonus anterior si hay
    daño_fisico -= bonus_daño_furia;
    bonus_daño_furia = 0;

    if (furia >= 90) {
        bonus_daño_furia = daño_fisico * 0.35;
    } else if (furia >= 70) {
        bonus_daño_furia = daño_fisico * 0.23;
    } else if (furia >= 50) {
        bonus_daño_furia = daño_fisico * 0.17;
    }

    daño_fisico += bonus_daño_furia;

    if (bonus_daño_furia > 0)
        cout << Get_nombre() << " entra en un estado de furia (+"<< bonus_daño_furia << " daño)" << endl;
    return;
}


bool barbaro::olfato_de_caza(shared_ptr<personaje> enemigo){
    if (vida < vida_maxima*0.5){
        cout << "El barbaro siente el olor de la sangre" << endl;
        cout << "El barbaro aumenta su daño fisico" << endl;
        return true;
    }
    else {
        cout << "El barbaro no siente el olor de la sangre" << endl;
        cout << "El barbaro no aumenta su daño fisico" << endl;
        return false;
    }
}

void barbaro::rompe_huesos(shared_ptr<personaje> enemigo){
    if (furia >= 30){
        if (vida < vida_maxima*0.5){
        enemigo->recibir_ataque(daño_fisico*0.5, FISICO, true);
        furia -= 30;
        }
        else{
            enemigo->recibir_ataque(daño_fisico*0.25, FISICO, true);
            furia -= 30;
        }
        aplicar_bonuses_por_furia();
    } else {
        cout << "No hay suficiente furia." << endl;
    }
    return;
}

void barbaro::grito_de_batalla(Equipo enemigos) {
    if (estamina < 20 || furia < 20){
        cout << "No hay suficiente estamina." << endl;
        return;
    }
    cout << "El barbaro grita de batalla." << endl;
    cout << "Cada enemigo tiene la posibilidad de asustarse." << endl;
    vector<shared_ptr<personaje>> enemigos_vivos = enemigos.devolver_vivos();
    for (size_t i = 0; i < enemigos_vivos.size(); i++){
        int prob = rand() % 100;
        if (prob < 80) {
            cout << enemigos_vivos[i]->Get_nombre() << " se asusta." << endl;
            enemigos_vivos[i]->recibir_efecto(MIEDO);
        } else {
            cout << enemigos_vivos[i]->Get_nombre() << " no se asusta." << endl;
        }
    }
    estamina -= 20;
    furia -= 20;
    aplicar_bonuses_por_furia();
    return;
}

void barbaro::recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) {
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

    if (ignorar_armadura) {
        vida -= daño;
    } else {
        if (tipo == FISICO) {
            vida -= daño * (1 - armadura / 100.0);
        } else if (tipo == MAGICO) {
            vida -= daño * (1 - resistencia_magica / 100.0);
        }
    }
    if (vida <= 0 && inmortal == true) {
        vida = 1;
        inmortal = false;
    
        cout << Get_nombre() << " desafía a la muerte!" << endl;
        cout << "Entra en un estado de furia inquebrantable: su cuerpo se niega a caer." << endl;
        cout << "Su vida queda al límite..." << endl;
        return;
    }
    
    if (vida <= 0) {
        this->morir(0);
        cout << Get_nombre() << " ha muerto." << endl;
    }
    aumentar_furia(daño); // Aumentar furia al recibir daño
    return;
}

void barbaro::ataque_rapido(shared_ptr<personaje> enemigo) {
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

    enemigo->recibir_ataque(daño, FISICO, false);
    aumentar_furia(daño); // Aumentar furia al atacar
    return;
}

void barbaro::atacar_con_arma(shared_ptr<personaje> enemigo) {
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
        daño = armas.first->Elegir_ataque();
    } else {
        daño = armas.second->Elegir_ataque();
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

    enemigo->recibir_ataque(daño.first, daño.second, false);

    aumentar_furia(daño.first); // Aumentar furia al atacar
    return;
}

void barbaro::recibir_efecto(EFFECTO efecto) {
    if (efecto == MIEDO){
        cout << "El barbaro no puede ser asustado." << endl;
        return;
    }
    int duracion;
    switch (efecto) {
        case PARALIZAR:
            duracion = 1;
            break;
        case CONFUSION:
            duracion = 2;
            break;
        case MIEDO:
            duracion = 2;
            break;
        case ENVENENAR:
            duracion = 3;
            break;
        case QUEMADURA:
            duracion = 3;
            break;
        case HEMORRAGIA:
            duracion = 2;
            break;
        case POTENCIAR_ALIADO:
            duracion = 3;
            break;
        case PROTECCION:
            duracion = 2;
            break;
        case INMORTALIDAD:
            duracion = 3;
            break;
    }
    shared_ptr<EfectoActivo> efecto_activo = make_shared<EfectoActivo>();
    efecto_activo->tipo = efecto;
    efecto_activo->duracion_restante = duracion;
    this->efectos.push_back(efecto_activo);   
    return;
}

void barbaro::modo_berserker() {
    if (furia < 100 || vida > vida_maxima * 0.3) {
        cout << "No estás lo suficientemente furioso ni herido para activar el modo berserker." << endl;
        return;
    }

    recibir_efecto(INMORTALIDAD);
    furia = 0;

    cout << Get_nombre() << " entra en MODO BERSERKER: daño aumentado, no puede morir por 3 turnos." << endl;
    // Activá buffs especiales (como flag o temporizador si manejás rondas)
}


