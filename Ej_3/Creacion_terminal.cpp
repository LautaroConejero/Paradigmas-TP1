#include "Persona_Factory.hpp"
#include "Creacion_terminal.hpp"

void Consola_equipos(){
    srand(time(0))
    int tamaño = rand() %5  + 3;
    cout <<"Tu eqipo tiene " << tamaño << " personajes." << endl;
    PersonajeFactory equipo(tamaño);
    cout << "Quieres hacer un equipo aleatorio? (1. No, 2. Si)" << endl;
    int des;
    cin >> des;
    while (des != 1 && des != 2){
        cout << "Opcion invalida. Elija nuevamente: " << endl;
       
        cin >> des;
    }
    for (int i = 0; i < tamaño; i++){
            equipo.Equipar_personaje(des);
            cout << "Personaje " << i + 1 << " creado." << endl;
    }

    cout << "El equipo ha sido creado." << endl;
    for (int i = 0; i < tamaño; i++){
        cout << "Personaje " << i + 1 << ": " << equipo.Get_personaje(i)->Get_nombre() << endl;
        cout << "Vida: " << equipo.Get_personaje(i)->Get_vida() << endl;
        cout << "Armadura: " << equipo.Get_personaje(i)->Get_armadura() << endl;
        cout << "Resistencia magica: " << equipo.Get_personaje(i)->Get_resistencia_m() << endl;
        cout << "Estamina: " << equipo.Get_personaje(i)->Get_estamina() << endl;
    }
    return;
}