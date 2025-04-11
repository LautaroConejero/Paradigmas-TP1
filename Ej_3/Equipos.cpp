#include "Equipos.hpp"


Equipo::Equipo(string nombre_equipo, int cantidad_personajes) : nombre_equipo(nombre_equipo), cantidad_personajes(cantidad_personajes) {
}

void Equipo::agregar_personaje(shared_ptr<personaje> p) {
    if (static_cast<int>(personajes.size()) < cantidad_personajes) {
        personajes.push_back(p);
        personajes_vivos.push_back(p);
    } else {
        cout << "No se puede agregar mas personajes al equipo." << endl;
    }
}

void Equipo::eliminar_muettos() {
    if (!personajes_vivos.empty()) {
        for (size_t i = 0; i < personajes_vivos.size(); i++){
            if (personajes_vivos[i]->Esta_vivo() == false){
                personajes_vivos.erase(personajes_vivos.begin() + i);
                cout << "El personaje " << personajes_vivos[i]->Get_nombre()<< " ha sido eliminado,"<<endl;
                break;
            }
        }
    } else {
        cout << "No hubo bajas en el equipo." << endl;
    }
}

void Equipo::mostrar_personajes() {
    for (int i = 0; i < cantidad_personajes; i++){
        cout << endl;
        cout << "Personaje: " << i + 1 << ": " << personajes[i]->Get_nombre() <<" (" << personajes[i]->Get_grupo() << ")"<<endl;
        cout << "Sus armas son: " << endl;
        if (personajes[i]->Get_armas().first != nullptr){
            cout << "Arma 1: " << personajes[i]->Get_armas().first->Get_nombre() << endl;
        }
        if (personajes[i]->Get_armas().second != nullptr){
            cout << "Arma 2: " << personajes[i]->Get_armas().second->Get_nombre() << endl;
        }
    }
}

int Equipo::verificar_vivos() {
    int vivos = 0;
    for (int i = 0; i < cantidad_personajes; i++){
        if (personajes[i]->Esta_vivo() == true){
            vivos++;
        }
    }
    return vivos;
}

vector<shared_ptr<personaje>> Equipo::devolver_personajes() {
    return personajes;
}

vector<shared_ptr<personaje>> Equipo::devolver_vivos() {
    return personajes_vivos;
}
