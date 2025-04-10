#include "combate.hpp"

int Decision_juego(){
    cout << endl;
    cout << "Momento de elegir el movimento" << endl;
    cout << "1. Golpe fuerte" << endl;
    cout << "2. Golpe rapido" << endl;
    cout << "3. Defensa y golpe" << endl;
    cout << "Elija el movimiento: ";
    int decision;
    cin >> decision;
    while (decision != 1 && decision != 2 && decision != 3){
        cout << "Opcion invalida. Elija nuevamente: " << endl;
        cin >> decision;
    }
    return decision;
}

int Ganador(DECISION_JUEGO decision_juego, DECISION_JUEGO decision_juego_maquina){
    switch (decision_juego) {
        case GOLPE_FUERTE:
            if (decision_juego_maquina == GOLPE_FUERTE) {
                return -1; // Empate
            }
            else if (decision_juego_maquina == GOLPE_RAPIDO) {
                return 1; // Ganaste
            }
            else {
                return 0; // Perdiste
            }
        case GOLPE_RAPIDO:
            if (decision_juego_maquina == GOLPE_FUERTE) {
                return -1;
            } else if (decision_juego_maquina == GOLPE_RAPIDO) {
                return 0;
            } else {
                return 1;
            }
        case DEFENSA_GOLPE:
            if (decision_juego_maquina == GOLPE_FUERTE) {
                return 1;
            } else if (decision_juego_maquina == GOLPE_RAPIDO) {
                return -1;
            } else {
                return 0;
            }
    }
    return 0;
}

void Accion_juego(int decision, shared_ptr<personaje>& jugador, shared_ptr<personaje>& enemigo){
    int decision_maquina = rand() % 3 + 1;
    DECISION_JUEGO decision_juego = static_cast<DECISION_JUEGO>(decision);
    DECISION_JUEGO decision_juego_maquina = static_cast<DECISION_JUEGO>(decision_maquina);
    int resultado = Ganador(decision_juego, decision_juego_maquina);
    cout << "El enemigo ha elegido: " << decision_maquina << endl;
    cout << endl;
    switch (resultado) {
        case -1:
            cout << "Empataste el turno!" << endl;
            break;
        case 0:
            cout << "Perdiste el turno!" << endl;
            jugador->recibir_ataque(10, FISICO, true);
            cout << "El enemigo con "<< enemigo->Get_nombre() << " ha atacado!" << endl;
            cout << "El enemigo te ataco con ";
            if (enemigo->Get_armas().first == nullptr){
                cout << "los puños";
                cout << " y le hizo 10 de daño!" << endl;
            }
                else {
                    cout << enemigo->Get_armas().first->Get_nombre() << endl;
    
                    if (enemigo->Get_armas().second != nullptr){
                        cout << " y con " << enemigo->Get_armas().second->Get_nombre() << endl;
                    }
                    cout << " y le hizo 10 de daño!" << endl;
                }

            cout << endl;
            cout << "Tu vida es: " << jugador->Get_vida() << endl;
            cout << "La vida del enemigo es: " << enemigo->Get_vida() << endl;
            break;
        case 1:
            cout << "Ganaste el turno!" << endl;
            enemigo->recibir_ataque(10, FISICO, true);
            cout << "Tu " << jugador->Get_nombre() << " ha atacado!" << endl;
            
            cout << "Ataco con ";

            if (jugador->Get_armas().first == nullptr){
                cout << "los puños";
                cout << " y le hizo 10 de daño!" << endl;
            } else {
                cout <<jugador->Get_armas().first->Get_nombre() << endl;
    
                if (jugador->Get_armas().second != nullptr){
                    cout << " y con " << jugador->Get_armas().second->Get_nombre() << endl;
                }
                cout << " y le hizo 10 de daño!" << endl;
            }
            cout << "Tu vida es: " << jugador->Get_vida() << endl;
            cout << "La vida del enemigo es: " << enemigo->Get_vida() << endl;
            break;
    }
    return;
}

int consola_combate(){
    srand(time(0)); // Inicializa la semilla para la generación de números aleatorios
    cout << "Bienvenido al juego de combate!" << endl;

    cout << "Quieres elegir tu personaje?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int decision;
    cin >> decision;
    while (decision != 1 && decision != 2){
        cout << "Opcion invalida. Elija nuevamente: " << endl;
        cin >> decision;
    }
    
    cout << "quieres elegir las cantidad de armas?" << endl;
    cout << "Nota: la maquina tendra las mismas cantidad de armas." << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int decision_armas;
    cin >> decision_armas;
    while (decision_armas != 1 && decision_armas != 2){
        cout << "Opcion invalida. Elija nuevamente: " << endl;
        cin >> decision_armas;
    }
    int cantidad_armas;
    if (decision_armas == 1){
        cout << "Cuantas armas quieres? El maximo es 2." << endl;
        cin >> cantidad_armas;
        while (cantidad_armas < 0 || cantidad_armas > 2){
            cout << "Opcion invalida. Elija nuevamente: " << endl;
            cin >> cantidad_armas;
        }
    } else {
        cantidad_armas = rand() % 3; // Genera un número aleatorio entre 1 y 5
    }

    shared_ptr<personaje> jugador = PersonajeFactory::Equipar_personaje(decision, cantidad_armas);
    shared_ptr<personaje> enemigo = PersonajeFactory::Equipar_personaje(2, cantidad_armas);
    cout << "Tu personaje es: " << jugador->Get_nombre() << endl;
    cout << "El enemigo es: " << enemigo->Get_nombre() << endl;

    while (jugador->Esta_vivo() && enemigo->Esta_vivo()){
        int decision = Decision_juego();
        Accion_juego(decision, jugador, enemigo);

        if (!jugador->Esta_vivo()){
            cout << "Perdiste el combate!" << endl;
            cout << "El " << enemigo->Get_nombre() << " enemigo se ha quedado con " << enemigo->Get_vida() << endl;
        } else if (!enemigo->Esta_vivo()){
            cout << "Ganaste el combate!" << endl;
            cout << "Tu " << jugador->Get_nombre() << " se ha quedado con " << jugador->Get_vida() << endl;
        }
    }

    return 0;
}