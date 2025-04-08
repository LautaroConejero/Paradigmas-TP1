#include "Creacion_terminal.hpp"

void Consola_equipos(){
    srand(time(0));
    cout << "Bienvenido a la creacion de equipos." << endl;

    int tamaño = rand() %5  + 3;
    cout <<"Tu eqipo tiene " << tamaño << " personajes." << endl;

    Equipo equipo("Equipo 1", tamaño);

    for (int i = 0; i < tamaño; i++){
        int cantidad_armas = rand() % 3;
        cout << "El personaje " << i + 1 << " tiene " << cantidad_armas << " armas." << endl;
        shared_ptr<personaje> p = PersonajeFactory::Equipar_personaje(1, 0);
        equipo.agregar_personaje(p);
        cout << "Personaje " << i + 1 << " creado." << endl;
        cout << endl;
    }
    cout << "El equipo ha sido creado." << endl;
    equipo.mostrar_personajes();
    cout << endl;

    int tamaño_2 = rand() %5  + 3;
    cout <<"Ahora hacemos un equipo random." << endl;
    cout <<"El equipo random tiene " << tamaño_2 << " personajes." << endl;
    Equipo equipo_2("Equipo 2", tamaño_2);

    for (int i = 0; i < tamaño_2; i++){
        int cantidad_armas = rand() % 3;
        cout << "El personaje " << i + 1 << " tiene " << cantidad_armas << " armas." << endl;
        shared_ptr<personaje> p = PersonajeFactory::Equipar_personaje(2, 0);
        equipo_2.agregar_personaje(p);
        cout << "Personaje " << i + 1 << " creado." << endl;
        cout << endl;
    }

    cout << "El equipo random ha sido creado." << endl;
    equipo_2.mostrar_personajes();
    return;
}