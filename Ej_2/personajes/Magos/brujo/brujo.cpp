#include "brujo.hpp"
#include "../../../../Ej_3/Equipos.hpp"
brujo::brujo(string n):
    Magos(10, 20, 90, 90, 35, n),
    estado_frenesi(false), demonio_invocado(false),
    pacto_usado(false), rondas_pacto(0) {}

string brujo::Get_grupo() const {
    return "Brujo";
}

void brujo::maldecir_enemigo(shared_ptr<personaje> enemigo) {
    if (mana < 10) {
        cout << "No tienes suficiente maná para lanzar una maldición." << endl;
        return;
    }
    mana -= 20;
    int tipo = rand() % 6;
    EFFECTO efecto;
    switch (tipo) {
        case 0: efecto = PARALIZAR; break;
        case 1: efecto = CONFUSION; break;
        case 2: efecto = MIEDO; break;
        case 3: efecto = ENVENENAR; break;
        case 4: efecto = QUEMADURA; break;
        case 5: efecto = HEMORRAGIA; break;
        default: efecto = PARALIZAR; break; // Por las
    }

    enemigo->recibir_ataque(5, MAGICO, true);
    enemigo->recibir_efecto(efecto);
    cout << "El brujo ha maldecido a " << enemigo->Get_nombre() << " con ";
    switch (efecto) {
        case PARALIZAR: cout << "paralización."; break;
        case CONFUSION: cout << "confusión."; break;
        case MIEDO: cout << "miedo."; break;
        case ENVENENAR: cout << "veneno."; break;
        case QUEMADURA: cout << "quemadura."; break;
        case HEMORRAGIA: cout << "hemorragia."; break;
        default: break;
    }
    if (demonio_invocado) {
        EFFECTO efecto2;
        int tipo = rand() % 6;
        switch (tipo) {
            case 0: efecto2 = PARALIZAR; break;
            case 1: efecto2 = CONFUSION; break;
            case 2: efecto2 = MIEDO; break;
            case 3: efecto2 = ENVENENAR; break;
            case 4: efecto2 = QUEMADURA; break;
            case 5: efecto2 = HEMORRAGIA; break;
            default: efecto2 = PARALIZAR; break; // Por las
        }

        enemigo->recibir_ataque(5, MAGICO, true);
        enemigo->recibir_efecto(efecto2); // Segundo efecto dura un poco menos

        cout << "El pacto demoníaco intensifica la maldición... también aplica ";
        switch (efecto2) {
            case PARALIZAR: cout << "paralización."; break;
            case CONFUSION: cout << "confusión."; break;
            case MIEDO: cout << "miedo."; break;
            case ENVENENAR: cout << "veneno."; break;
            case QUEMADURA: cout << "quemadura."; break;
            case HEMORRAGIA: cout << "hemorragia."; break;
            default: break;
        }
    }
    return;
}   

void brujo::control_mental(Equipo enemigos, shared_ptr<personaje> enemigo){
    if (mana < 25) {
        cout << "No tienes suficiente maná para usar control mental." << endl;
        return;
    }
    mana -= 25;
    cout << "Gracias a su control mental, el brujo ha tomado el control de " << enemigo->Get_nombre() << "." << endl;
    cout << "Ahora el enemigo atacara a su propio equipo." << endl;
    
    int enemigo_index = rand() % enemigos.verificar_vivos();
    shared_ptr<personaje> enemigo_atacado = enemigos.devolver_vivos()[enemigo_index];
    cout << "El brujo ha controlado a " << enemigo->Get_nombre() << " y lo ha hecho atacar a " << enemigo_atacado->Get_nombre() << "." << endl;
    
    int daño = 10 + (enemigo->Get_dano_fisico() + enemigo->Get_dano_magico()) / 2;
    enemigo_atacado->recibir_ataque(daño, MAGICO, false);
    return;
}

void brujo::estado_de_frenesi() {
    if (estado_frenesi == false) {
        estado_frenesi = true;
        cout << "El brujo ha entrado en estado de frenesi." << endl;
        cout << "Tendras la chance de atacar a alguien y si muere, te salvas de la muerte." << endl;
    }
    else {
        estado_frenesi = false;
    }
    return;
}

void brujo::pacto_demoniaco() {
    if (pacto_usado) {
        cout << "Ya has hecho un pacto. " << endl;
        return;
    }

    if (vida < vida_maxima * 0.3 || mana < 40) {
        cout << "No tienes suficiente vida o maná para realizar el pacto demoníaco." << endl;
        return;
    }

    vida -= vida * 0.3;
    mana -= 40;

    demonio_invocado = true;
    pacto_usado = true;
    rondas_pacto = 3;
    cout << "El PACTO DEMONÍACO ha sido sellado" << endl;
    cout << "Daño mágico aumentado y las maldiciones se intensifican durante 3 rondas." << endl;
}

void brujo::procesar_efectos() {
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
        }

        efecto->duracion_restante--;

        // Si terminó, eliminar
        if (efecto->duracion_restante <= 0) {
            cout << "El efecto " << efecto->tipo << " ha finalizado." << endl;
            efectos.erase(efectos.begin() + i);
            --i;
        }
    }

    if (vida <= 0) {
        vida = 0;
        vivo = false;
        cout << Get_nombre() << " ha muerto por los efectos." << endl;
    }
    if (demonio_invocado) {
        rondas_pacto--;
        if (rondas_pacto <= 0) {
            demonio_invocado = false;
            pacto_usado = false;
            cout << "El pacto demoníaco ha terminado." << endl;
        }
    }
    return;
}

void brujo::recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) {
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
        estado_de_frenesi();
    }
    return;
}

void brujo::ataque_rapido(shared_ptr<personaje> enemigo) {
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

    if (demonio_invocado) {
        daño *= 1.5; // Aumenta el daño por el pacto demoníaco
        cout << "El pacto demoníaco aumenta el daño." << endl;
    }

    enemigo->recibir_ataque(daño, FISICO, false);
    if (estado_frenesi) {
        if (!enemigo->Esta_vivo()) {
            cout << "Con la ayuda del estado frenesi, el brujo ha sobrevivido." << endl;
            estado_de_frenesi();
            this->vida = vida_maxima * 0.3;
        }
    }
}

void brujo::atacar_con_arma(shared_ptr<personaje> enemigo) {
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

    if (demonio_invocado) {
        daño.first *= 1.5; // Aumenta el daño por el pacto demoníaco
        cout << "El pacto demoníaco aumenta el daño." << endl;
    }

    enemigo->recibir_ataque(daño.first, daño.second, false);
    if (estado_frenesi) {
        if (!enemigo->Esta_vivo()) {
            cout << "Con la ayuda del estado frenesi, el brujo ha sobrevivido." << endl;
            estado_de_frenesi();
            this->vida = vida_maxima * 0.3;
        }
    }
    return;
}

