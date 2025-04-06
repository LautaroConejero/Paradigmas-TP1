#include "Guerreros.hpp"

Guerreros::Guerreros(int v, int a, int rm, int e, string n): 
vida(v), armadura(a), resistencia_magica(rm), estamina(e), nombre(n), vivo(true) {
}

Bool Guerreros::Esta_vivo() {
    return this->vida > 0;
}

string Guerreros::Get_nombre() {
    return this->nombre;
}

int Guerreros::Get_vida() {
    return this->vida;
}

int Guerreros::Get_armadura() {
    return this->armadura;
}

int Guerreros::Get_resistencia_m() {
    return this->resistencia_magica;
}

int Guerreros::Get_estamina() {
    return this->estamina;
}

void Guerreros::recibir_ataque(int daño) {
    this->vida -= daño;
    if (this->vida < 0) {
        this->vida = 0;
        this->vivo = false;
    }
    return;
}

void Guerreros::equipar_armas(shared_ptr<arma> a) {
    if (this->armas.first == nullptr) {
        this->armas.first = a;
    } else if (this->armas.second == nullptr) {
        this->armas.second = a;
    } else {
        cout << "No se pueden equipar mas armas." << endl;
    }
    return;
}

pair<shared_ptr<arma>, shared_ptr<arma>> Guerreros::Get_armas() {
    return this->armas;
}

virtual int Guerreros::ataque_rapido() {
    if (armas.first == nullptr) {
        return daño_fisico;
    }
    else if (armas.second == nullptr) {
        return daño_fisico + armas.first->Get_daño_fisico();
    } else {
        return daño_fisico + armas.first->Get_daño_fisico() + armas.second->Get_daño_fisico();
    }    
    return;

}