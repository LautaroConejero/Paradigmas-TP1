#include "armas_combate.hpp"

ArmaCombate::ArmaCombate(string n, int df, int d, float c):
nombre(n), daño_fisico(df), daño_magico(0), durabilidad(d), chance_critico(c){
    int material = rand() % 6;
    MATERIALES mat = static_cast<MATERIALES>(material);
    this->material = mat;
    switch (mat) {
        case HIERRO:
        this->daño_fisico += 8;
        break;
        case ACERO:
        this->daño_fisico += 10;
        break;
        case ORO:
        this->daño_fisico += 5;
        break;
        case PLATA:
        this->daño_fisico += 3;
        break;
        case MADERA:
        this->daño_fisico += 1;
        break;
        case PIEDRA:
        this->daño_fisico += 2;
        break;
    } 
}

string ArmaCombate::Get_nombre() const {
    return this->nombre + " de " + Get_material();;
}

int ArmaCombate::Get_durabilidad() const {
    return this->durabilidad;
}

int ArmaCombate::Get_daño_fisico() const {
    return this->daño_fisico;
}   

int ArmaCombate::Get_daño_magico() const {
    return this->daño_magico;
}

float ArmaCombate::Get_chance_critico() const {
    return this->chance_critico;
}

string ArmaCombate::Get_material() const {
    switch(material) {
        case HIERRO: return "Hierro";
        case ACERO: return "Acero";
        case ORO: return "Oro";
        case PLATA: return "Plata";
        case MADERA: return "Madera";
        case PIEDRA: return "Piedra";
        default: return "Desconocido";
    }
}
