#include "Magos.hpp"

Magos::Magos(int a, int rm, int m, int mm, int dm, string n):
vivo(true), vida(100), vida_maxima(100), 
armadura(a), resistencia_magica(rm),
daño_fisico(FISICO_BASICO), daño_magico(dm), 
mana(m), mana_maximo(mm),
nombre(n){}

bool Magos::Esta_vivo() const {
    return this->vida > 0;
}

string Magos::Get_nombre() const {
    return this->nombre;
}

int Magos::Get_vida() const {
    return this->vida;
}

int Magos::Get_vida_maxima() const {
    return this->vida_maxima;
}

void Magos::morir(int vida_restante) {
    this->vida = vida_restante;
    if (this->vivo == true){
        this->vivo = false;
    }
    else {
        this->vivo = true;
    }
    return;
}

int Magos::Get_dano_fisico() const {
    return this->daño_fisico;
}

int Magos::Get_dano_magico() const {
    return this->daño_magico;
}

int Magos::Get_armadura() const {
    return this->armadura;
}

int Magos::Get_resistencia_m() const {
    return this->resistencia_magica;
}

int Magos::Get_mana() const {
    return this->mana;
}

void Magos::recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) {
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

    if (vida <= 0) {
        this->morir(0);
        cout << Get_nombre() << " ha muerto." << endl;
    }
    return;
}


void Magos::equipar_arma(shared_ptr<arma> a) {
    if (this->armas.first == nullptr) {
        this->armas.first = a;
    } else if (this->armas.second == nullptr) {
        this->armas.second = a;
    } else {
        cout << "No se pueden equipar mas armas." << endl;
    }
    return;
}

void Magos::eliminar_arma(int posicion) {
    if (posicion == 1) {
        this->armas.first = this->armas.second;
    }
    this->armas.second = nullptr;
    return;
}

pair<shared_ptr<arma>, shared_ptr<arma>> Magos::Get_armas() {
    return this->armas;
}

void Magos::ataque_rapido(shared_ptr<personaje> enemigo) {
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
}


void Magos::atacar_con_arma(shared_ptr<personaje> enemigo) {
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

    enemigo->recibir_ataque(daño.first, daño.second, false);
}


void Magos::recibir_efecto(EFFECTO efecto) {
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
        default:
            duracion = 0;
            break;
    }
    shared_ptr<EfectoActivo> efecto_activo = make_shared<EfectoActivo>();
    efecto_activo->tipo = efecto;
    efecto_activo->duracion_restante = duracion;
    this->efectos.push_back(efecto_activo);   
    return;
}

void Magos::procesar_efectos() {
    // Reiniciar flags antes de volver a activar los que sigan vigentes
    paralizado = false;
    confundido = false;
    asustado = false;
    quemado = false;
    hemorragia = false;
    potenciado = false;
    protegido = false;

    for (size_t i = 0; i < efectos.size(); ++i) {
        shared_ptr<EfectoActivo> efecto = efectos[i];
        int daño = 0;
        switch (efecto->tipo) {
            case PARALIZAR:
                paralizado = true;
                break;

            case CONFUSION:
                confundido = true;
                break;

            case MIEDO:
                asustado = true;
                break;

            case ENVENENAR:
                {
                daño = 12 * (1 - resistencia_magica / 100.0);
                vida -= daño;
                cout << Get_nombre() << " sufre " << daño << " de daño mágico por veneno." << endl;
                }
                break;

            case QUEMADURA:
                quemado = true;
                vida -= 10; 
                cout << Get_nombre() << " sufre 10 de daño por quemadura (ignora armadura)." << endl;
                break;

            case HEMORRAGIA:
                hemorragia = true;
                daño = vida * 0.10;
                vida -= daño;
                cout << Get_nombre() << " pierde " << daño << " de vida por hemorragia (ignora armadura)." << endl;
                break;

            case POTENCIAR_ALIADO:
                potenciado = true;
                break;

            case PROTECCION:
                protegido = true;
                break;
            
            case INMORTALIDAD:
                inmortal = true;
                break;
            
            default:
                break;
        }

        efecto->duracion_restante--;

        // Si terminó, eliminar
        if (efecto->duracion_restante <= 0) {
            cout << "El efecto " << efecto->tipo << " ha finalizado." << endl;
            efectos.erase(efectos.begin() + i);
            --i;
        }
    }

    // Revisión de muerte
    if (vida <= 0) {
        vida = 0;
        vivo = false;
        cout << Get_nombre() << " ha muerto por los efectos." << endl;
    }
}