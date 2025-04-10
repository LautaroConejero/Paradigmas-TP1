#include "item_magicos.hpp"

Item_magicos::Item_magicos(string n, int dm, int d, float c):
nombre(n), durabilidad(d), daño_fisico(0), daño_magico(dm), chance_critico(c)
 {}

string Item_magicos::Get_nombre() const {
    return this->nombre + "de " + Get_encantamiento();
}

int Item_magicos::Get_durabilidad() const {
    return this->durabilidad;
}

int Item_magicos::Get_daño_fisico() const {
    return this->daño_fisico;
}   

int Item_magicos::Get_daño_magico() const {
    return this->daño_magico;
}

float Item_magicos::Get_chance_critico() const {
    return this->chance_critico;
}
string Item_magicos::Get_encantamiento() const {
    switch (encantamiento) {
        case FUEGO: return "Fuego";
        case AGUA: return "Agua";
        case TIERRA: return "Tierra";
        case AIRE: return "Aire";
        case ELECTRICIDAD: return "Electricidad";
        case HIELO: return "Hielo";
        default: return "Desconocido";
    }
}