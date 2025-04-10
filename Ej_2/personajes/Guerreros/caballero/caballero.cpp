#include "caballero.hpp"

caballero::caballero(string n):
Guerreros(55, 35, 28, 90, 90, n) {}

string caballero::Get_grupo() const {
    return "Caballero";
}

void caballero::juramento_de_proteccion(shared_ptr<personaje> aliado) {
    if (estamina < 20) {
        cout << "No hay suficiente estamina." << endl;
        return;
    }
    if (aliado->Esta_vivo() == false) {
        cout << "El aliado ya no está vivo." << endl;
        return;
    }
    estamina -= 20;
    cout << "El caballero " << Get_nombre() << " ha jurado proteger a " << aliado->Get_nombre() << "." << endl;
    aliado->recibir_efecto(PROTECCION);
    return;
}