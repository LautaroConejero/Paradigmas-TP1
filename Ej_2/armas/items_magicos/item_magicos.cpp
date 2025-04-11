#include "item_magicos.hpp"

Item_magicos::Item_magicos(string n, int dm, int d, float c):
nombre(n), durabilidad(d), daño_fisico(0), daño_magico(dm), chance_critico(c){
    int encantamiento = rand() % 6;
    switch(encantamiento) {
        case 0: this->encantamiento = FUEGO; break;
        case 1: this->encantamiento = AGUA; break;
        case 2: this->encantamiento = TIERRA; break;
        case 3: this->encantamiento = AIRE; break;
        case 4: this->encantamiento = ELECTRICIDAD; break;
    }
}

string Item_magicos::Get_nombre() const {
    return this->nombre + " de " + Get_encantamiento();
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
        default: return "Desconocido";
    }
}