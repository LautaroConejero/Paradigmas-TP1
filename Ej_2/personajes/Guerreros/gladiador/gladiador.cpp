#include "gladiador.hpp"

gladiador::gladiador(string n):
Guerreros(20, 10, 35, 90, 90, n),
honor(0), adrenalina(0), capacidad_esquivar(20),esquivar_activado(false), capacidad_adrenalina(0), 
armadura_adrenalina(0), espiritu_activado(false), espiritu_usado(false), cantidad_efectos_no_recibidos(0),
daño_honor(0) {}

string gladiador::Get_grupo() const {
    return "Gladiador";
}

void gladiador::aumentar_adrenalina(int daño_infligido) {
    this->adrenalina += daño_infligido/4;
    cout << "El gladiador aumento su adrenalina" << endl;
    aplicar_adrenalina();
    return;
}

void gladiador::aplicar_adrenalina() {
    armadura_adrenalina = 0.15*adrenalina;
    capacidad_adrenalina = adrenalina*0.75;
    return;
}
void gladiador::embestida(shared_ptr<personaje> enemigo) {
    if (estamina < 15){
        cout << "No hay suficiente estamina." << endl;
        return;
    }
    if (this->adrenalina >= 30){
        this->adrenalina -= 30;
        cout << "El gladiador embiste al enemigo." << endl;
        cout << "Lo inmovibiliza y le hace daño fisico." << endl;

        enemigo->recibir_ataque((daño_fisico+daño_honor)*0.75, FISICO, false);
        enemigo->recibir_efecto(PARALIZAR);
        aplicar_adrenalina();
    } else {
        cout << "No hay suficiente adrenalina." << endl;
    }
    return;
}

void gladiador::entretener_al_publico() {
    if (esquivar_activado == false){
        cout << "El gladiador escucha los cantos del publico" << endl;
        cout << "Es hora de entretener al coliseo" << endl;
        cout << endl;

        cout << "Por cada golpe esquivado, el gladiador aumenta su honor" << endl;
        esquivar_activado = true;
        return;
    }

    cout << "El gladiador no esquivara mas ataques." << endl;
    cout << "El gladiador ha dejado de entretener al publico." << endl;
    esquivar_activado = false;
    return;
}

void gladiador::aplicar_honor(){
    daño_honor = 0.3*honor;
    return;
}

void gladiador::recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) {
    if (esquivar_activado == true){
        int probabilidad_esquivar = rand() % 100 + 1;
        if (probabilidad_esquivar <= capacidad_esquivar){
            cout << "El gladiador ha esquivado el ataque." << endl;
            cout << "El gladiador ha aumentado su honor." << endl;
            this->honor += daño/2;
            return;
        }
        cout << "El gladiador no fue capaz de esquivar el ataque." << endl;
        cout << "Pierde toda su adrenalina y honor." << endl;
        this->honor = 0;
        this->adrenalina = 0;
        this->esquivar_activado = false;
        aplicar_adrenalina();
        aplicar_honor();
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
}

void gladiador::recibir_efecto(EFFECTO efecto){
    if (espiritu_activado == true && efecto != POTENCIAR_ALIADO ){
        cout << "El espiritu de Julio Cesar no permite ser afectado por efectos negativos." << endl;
        cout << "El gladiador no recibe el efecto." << endl;
        cantidad_efectos_no_recibidos--;
        if (cantidad_efectos_no_recibidos == 0){
            espiritu_activado = false;
            cout << "Julio Cesar ha dejado de proteger al gladiador." << endl;
            armadura -= 20;
            resistencia_magica -= 20;
            daño_fisico -= 10;
        }
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

void gladiador::ataque_rapido(shared_ptr<personaje> enemigo) {
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
    aumentar_adrenalina(daño);
    return;
}

void gladiador::atacar_con_arma(shared_ptr<personaje> enemigo) {
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
    aumentar_adrenalina(daño.first);
    return;
}

void gladiador::espiritu_de_Julio_Cesar() {
    if (espiritu_usado) {
        cout << "El espíritu de Julio César ya fue invocado." << endl;
        return;
    }

    if (honor < 60 || estamina < 30) {
        cout << "El gladiador no está lo suficientemente digno para invocar al espíritu." << endl;
        return;
    }

    espiritu_activado = true;
    espiritu_usado = true;
    cantidad_efectos_no_recibidos = 0;
    estamina -= 30;

    armadura += 20;
    resistencia_magica += 20;
    daño_fisico += 10;

    cout << "¡El espíritu de Julio César ha poseído al gladiador!" << endl;
    cout << "Ignorará los próximos 2 efectos negativos. ¡El Coliseo enmudece!" << endl;
    return;
}

