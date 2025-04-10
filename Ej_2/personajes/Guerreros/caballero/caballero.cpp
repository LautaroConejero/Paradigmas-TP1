#include "caballero.hpp"

caballero::caballero(string n):
Guerreros(35, 15, 28, 70, 70, n),
proteccion(false), protegido(nullptr) {}

string caballero::Get_grupo() const {
    return "Caballero";
}

void caballero::juramento_de_proteccion(shared_ptr<personaje> aliado) {
    if (estamina < 20) {
        cout << "No hay suficiente estamina." << endl;
        return;
    }
    if (aliado == nullptr) {
        cout << "No hay aliado para proteger." << endl;
        return;
    }
    if (aliado->Esta_vivo() == false) {
        cout << "El aliado ya no está vivo." << endl;
        return;
    }
    if (protegido != nullptr) {
        cout << "Ya hay un aliado protegido." << endl;
        return;
    }
    estamina -= 20;
    cout << "El caballero " << Get_nombre() << " ha jurado proteger a " << aliado->Get_nombre() << "." << endl;
    aliado->recibir_efecto(PROTECCION);
    proteccion = true;
    protegido = aliado;
    return;
}