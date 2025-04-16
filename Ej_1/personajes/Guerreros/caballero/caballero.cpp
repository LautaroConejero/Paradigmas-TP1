#include "caballero.hpp"

caballero::caballero():
Guerreros(55, 35, 90, 90, 28, "Sir Edric") {}

string caballero::Get_grupo() const {
    return "Caballero";
}

string caballero::Get_tipo_guerrero() const {
    return "Guerrero noble";
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