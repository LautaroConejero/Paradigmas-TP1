#include "conjurador.hpp"

conjurador::conjurador():
Magos(10, 15, 85, 85, 25, "Elion"),
invocaciones_maximas(2){}

string conjurador::Get_grupo() const {
    return "Conjurador";
}
string conjurador::get_tipo_mago() const{
    return "Mago neutral";
}

void conjurador::invocar_animal() {
    if (mana < 18) {
        cout << "No hay suficiente mana." << endl;
        return;
    }
    if (static_cast<int>(invocaciones_vivas.size()) < invocaciones_maximas) {
        cout << "Elija el tipo de animal a invocar: " << endl;
        cout << "0. Lobo (20 mana)" << endl;
        cout << "1. Oso (25 mana)" << endl;
        cout << "2. Aguila (18 mana)" << endl;
        cout << "3. Serpiente (22 mana)" << endl;
        int opcion;
        cin >> opcion;
        while (opcion < 0 || opcion > 3) {
            cout << "Opcion invalida. Elija nuevamente: " << endl;
            cin >> opcion;
        }
        shared_ptr<InvocacionAnimal> invocacion = make_shared<InvocacionAnimal>();
        invocacion->tipo = static_cast<INVOCAIONES_ANIMALES>(opcion);
        switch (opcion) {
            case LOBO:
                if (mana < 20) {
                    cout << "No hay suficiente mana." << endl;
                    return;
                }
                mana -= 20;
                invocacion->vida = 30;
                invocacion->daño_fisico = 15;
                invocacion->prob_efecto = 30;
                invocacion->efecto_asociado = HEMORRAGIA;
                break;
            case OSO:
                if (mana < 25) {
                    cout << "No hay suficiente mana." << endl;
                    return;
                }
                mana -= 25;
                invocacion->vida = 50;
                invocacion->daño_fisico = 20;
                invocacion->prob_efecto = 25;
                invocacion->efecto_asociado = MIEDO;
                break;
            case AGUILA:
                if (mana < 18) {
                    cout << "No hay suficiente mana." << endl;
                    return;
                }
                mana -= 18;
                invocacion->vida = 25;
                invocacion->daño_fisico = 10;
                invocacion->prob_efecto = 35;
                invocacion->efecto_asociado = CONFUSION;
                break;
            case SERPIENTE:
                if (mana < 22) {
                    cout << "No hay suficiente mana." << endl;
                    return;
                }
                mana -= 22;
                invocacion->vida = 20;
                invocacion->daño_fisico = 8;
                invocacion->prob_efecto = 40;
                invocacion->efecto_asociado = ENVENENAR;
                break;
        }

    } else {
        cout << "No se pueden invocar mas animales." << endl;
    }
    return;
}

void conjurador::ataque_con_invocacion(shared_ptr<personaje> enemigo) {
    if (invocaciones_vivas.empty()) {
        cout << "No tienes invocaciones activas para atacar." << endl;
        return;
    }

    cout << "Invocaciones disponibles para atacar:" << endl;
    for (size_t i = 0; i < invocaciones_vivas.size(); ++i) {
        shared_ptr<InvocacionAnimal> inv = invocaciones_vivas[i];
        cout << i + 1 << ". ";

        switch (inv->tipo) {
            case LOBO: cout << "Lobo"; break;
            case OSO: cout << "Oso"; break;
            case AGUILA: cout << "Águila"; break;
            case SERPIENTE: cout << "Serpiente"; break;
            default: cout << "Bestia"; break;
        }

        cout << " | Vida: " << inv->vida << " | Daño: " << inv->daño_fisico << endl;
    }

    int opcion;
    cout << "Selecciona una invocación para atacar: ";
    cin >> opcion;

    if (opcion < 1 || opcion > (int)invocaciones_vivas.size()) {
        cout << "Opción inválida." << endl;
        return;
    }

    shared_ptr<InvocacionAnimal> invocacion = invocaciones_vivas[opcion - 1];

    cout << "La invocación ataca causando " << invocacion->daño_fisico << " de daño físico." << endl;
    enemigo->recibir_ataque(invocacion->daño_fisico, FISICO, false);

    float prob = (rand() % 100) / 100.0f;
    if (prob < invocacion->prob_efecto) {
        enemigo->recibir_efecto(invocacion->efecto_asociado);
        cout << "¡El efecto especial fue aplicado al enemigo!" << endl;
    } else {
        cout << "El efecto no se activó esta vez." << endl;
    }
    return;
}

void conjurador::recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) {
    if (!invocaciones_vivas.empty()) {
        shared_ptr<InvocacionAnimal> inv = invocaciones_vivas.front();
        cout << "Una invocación se interpone para proteger al conjurador." << endl;

        if (inv->vida >= daño) {
            inv->vida -= daño;
            cout << "La invocación absorbió todo el daño. Vida restante: " << inv->vida << endl;
        } else {
            daño = daño - inv->vida;
            cout << "La invocación murió absorbiendo " << inv->vida << " de daño." << endl;
            invocaciones_vivas.erase(invocaciones_vivas.begin());
        }
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

void conjurador::paralisis(shared_ptr<personaje> enemigo) {
    if (mana < 10) {
        cout << "No hay suficiente mana." << endl;
        return;
    }
    enemigo->recibir_efecto(PARALIZAR);
    cout << "El conjurador ha paralizado al enemigo." << endl;
    mana -= 10;
    return;
}

void conjurador::efecto_aleatorio(shared_ptr<personaje> enemigo) {
    if (mana < 10) {
        cout << "No hay suficiente mana." << endl;
        return;
    }
    int efecto_random = rand() % 6;

    EFFECTO efecto_aplicado = static_cast<EFFECTO>(efecto_random);
    enemigo->recibir_efecto(efecto_aplicado);
    cout << "El conjurador ha aplicado un efecto aleatorio al enemigo." << endl;
    cout << "El efecto aplicado es: " << efecto_aplicado << endl;

    mana -= 10;
    return;
}

bool conjurador::invocacion_maxima(shared_ptr<personaje> enemigo) {
    static bool usada = false;

    if (usada) {
        cout << "Ya has usado la invocación máxima en este combate." << endl;
        return false;
    }

    if (mana < 50) {
        cout << "No tienes suficiente maná para invocar al dragón espiritual." << endl;
        return false;
    }

    usada = true;
    mana -= 50;
    cout << "El Espíritu del Dragón desciende y ataca a " << enemigo->Get_nombre() <<  endl;

    int daño = 50;
    enemigo->recibir_ataque(daño, MAGICO, true); 
    enemigo->recibir_efecto(QUEMADURA);
    cout << "El efecto de quemadura ha sido aplicado a " << enemigo->Get_nombre() << " durante 3 rondas." << endl;
    return true;
}
