#include "Magos.hpp"

Magos::Magos(int v, int a, int rm, int m, string n):
vida(v), armadura(a), resistencia_magica(rm), mana(m), nombre(n), vivo(true) {
}

Bool Magos::Esta_vivo() {
    return this->vida > 0;
}

string Magos::Get_nombre() {
    return this->nombre;
}

int Magos::Get_vida() {
    return this->vida;
}

int Magos::Get_armadura() {
    return this->armadura;
}

int Magos::Get_resistencia_m() {
    return this->resistencia_magica;
}

int Magos::Get_mana() {
    return this->mana;
}

void Magos::recibir_ataque(int daño) {
    this->vida -= daño;
    if (this->vida < 0) {
        this->vida = 0;
        this->vivo = false;
    }
    return;
}

void Magos::equipar_armas(shared_ptr<arma> a) {
    if (this->armas.first == nullptr) {
        this->armas.first = a;
    } else if (this->armas.second == nullptr) {
        this->armas.second = a;
    } else {
        cout << "No se pueden equipar mas armas." << endl;
    }
    return;
}

pair<shared_ptr<arma>, shared_ptr<arma>> Magos::Get_armas() {
    return this->armas;
}

virtual int Magos::ataque_rapido() {
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