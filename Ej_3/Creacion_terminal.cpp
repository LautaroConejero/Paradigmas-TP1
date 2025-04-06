#include "Creacion_terminal.hpp"

void Creacion_equipos(int des, int tamaño, vector<shared_ptr<personaje>> &equipo, PersonajeFactory &factory){
    for (int i = 0; i < tamaño; i++){
        shared_ptr<personaje> p = factory.Crear_personajes(des);
        equipo.push_back(p);
    }
    return;
}

void Consola_equipos(){
    srand(time(0));
    cout << "Bienvenido a la creacion de equipos." << endl;
    vector<shared_ptr<personaje>> equipo;

    int tamaño = rand() %5  + 3;
    cout <<"Tu eqipo tiene " << tamaño << " personajes." << endl;
    cout << "Quieres hacer un equipo aleatorio? (1. No, 2. Si)" << endl;
    
    int des;
    cin >> des;
    while (des != 1 && des != 2){
        cout << "Opcion invalida. Elija nuevamente: " << endl;
       
        cin >> des;
    }

    for (int i = 0; i < tamaño; i++){
        int cantidad_armas = rand() % 3;
        cout << "El personaje " << i + 1 << " tiene " << cantidad_armas << " armas." << endl;
        shared_ptr<personaje> p = PersonajeFactory::Equipar_personaje(des, cantidad_armas);
        equipo.push_back(p);
        cout << "Personaje " << i + 1 << " creado." << endl;
    }
    cout << "El equipo ha sido creado." << endl;
    for (int i = 0; i < tamaño; i++){
        cout << "Personaje " << i + 1 << ": " << equipo[i]->Get_nombre() << endl;
        cout << "Vida: " << equipo[i]->Get_vida() << endl;
        cout << "Armadura: " << equipo[i]->Get_armadura() << endl;
        cout << "Resistencia magica: " << equipo[i]->Get_resistencia_m() << endl;
    }
    return;
}