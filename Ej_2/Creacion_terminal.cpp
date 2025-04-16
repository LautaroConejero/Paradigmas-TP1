#include "Creacion_terminal.hpp"

void Consola_equipos(){
    srand(time(0));
    cout << "Bienvenido a la creacion de equipos." << endl;

    cout << "Cual equipo quieres crear?" << endl;
    cout << "1. Magos" << endl;
    cout << "2. Guerreros" << endl;

    int decision;
    cin >> decision;
    while (decision != 1 && decision != 2){
        cout << "Opcion invalida. Elija nuevamente: " << endl;
        cin >> decision;
    }

    int tamaño = rand() %5  + 3;
    cout <<"El primer equipo equipo tiene " << tamaño << " personajes." << endl;
    string nombre_equipo = (decision == 1) ? "Equipo Magos" : "Equipo Guerreros";
    Equipo equipo(nombre_equipo, tamaño);

    for (int i = 0; i < tamaño; i++){
        int cantidad_armas = rand() % 3;
        cout << "El personaje " << i + 1 << " tiene " << cantidad_armas << " armas." << endl;
        shared_ptr<personaje> p = PersonajeFactory::Equipar_personaje(1, cantidad_armas, decision);
        equipo.agregar_personaje(p);
        cout << "Personaje " << i + 1 << " creado." << endl;
        cout << endl;
    }
    cout << "El equipo ha sido creado." << endl;
    equipo.mostrar_personajes();
    cout << endl;

    int tamaño_2 = rand() %5  + 3;
    cout <<"Ahora hacemos el equipo random." << endl;
    cout <<"El equipo random tiene " << tamaño_2 << " personajes." << endl;
    string nombre_equipo_2 = (decision == 1) ? "Equipo Guerreros" : "Equipo Magos";
    Equipo equipo_2(nombre_equipo_2, tamaño_2);

    for (int i = 0; i < tamaño_2; i++){
        int cantidad_armas = rand() % 3;
        int decision_2 = (decision == 1) ? 2 : 1;
        shared_ptr<personaje> p = PersonajeFactory::Equipar_personaje(2, cantidad_armas, decision_2);
        equipo_2.agregar_personaje(p);
        cout << "Personaje " << i + 1 << " creado." << endl;
        cout << endl;
    }

    cout << "El equipo random ha sido creado." << endl;
    equipo_2.mostrar_personajes();
    return;
}
