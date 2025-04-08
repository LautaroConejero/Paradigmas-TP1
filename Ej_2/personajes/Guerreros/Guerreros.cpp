#include "Guerreros.hpp"

Guerreros::Guerreros(int a, int rm, int e, int em, int df, string n):
vivo(true), vida(100), vida_maxima(100), 
armadura(a), resistencia_magica(rm),
daño_fisico(df), daño_magico(MAGICO_BASICO), 
estamina(e), estamina_maxima(em),
nombre(n) {}
bool Guerreros::Esta_vivo() const {
    return this->vida > 0;
}

string Guerreros::Get_nombre() const {
    return this->nombre;
}

int Guerreros::Get_vida() const {
    return this->vida;
}
int Guerreros::Get_vida_maxima() const {
    return this->vida_maxima;
}

void Guerreros::morir(int vida_restante) {
    this->vida = vida_restante;
    if (this->vivo == true){
        this->vivo = false;
    }
    else {
        this->vivo = true;
    }
    return;
}

int Guerreros::Get_dano_fisico() const {
    return this->daño_fisico;
}

int Guerreros::Get_dano_magico() const {
    return this->daño_magico;
}

int Guerreros::Get_armadura() const {
    return this->armadura;
}

int Guerreros::Get_resistencia_m() const {
    return this->resistencia_magica;
}

int Guerreros::Get_estamina() const {
    return this->estamina;
}

void Guerreros::recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) {
    if (ignorar_armadura == true) {
        this->vida -= daño;
        return;
    }
    if (tipo == FISICO) {
        this->vida -= daño*(1 - this->armadura/100.0);
    } else if (tipo == MAGICO) {
        this->vida -= daño*(1 - this->resistencia_magica/100.0);
    }
    if (this->vida <= 0) {
        this->vida = 0;
        this->vivo = false;
    }
    return;
}

void Guerreros::equipar_arma(shared_ptr<arma> a) {
    if (this->armas.first == nullptr) {
        this->armas.first = a;
    } else if (this->armas.second == nullptr) {
        this->armas.second = a;
    } else {
        cout << "No se pueden equipar mas armas." << endl;
    }
    return;
}

void Guerreros::eliminar_arma(int posicion) {
    if (posicion == 1) {
        this->armas.first = this->armas.second;
    }
    this->armas.second = nullptr;
    return;
}

pair<shared_ptr<arma>, shared_ptr<arma>> Guerreros::Get_armas() {
    return this->armas;
}

void Guerreros::ataque_rapido(shared_ptr<personaje> enemigo) {
    int daño;
    if (armas.first == nullptr) {
        daño = daño_fisico;
    }
    else if (armas.second == nullptr) {
        daño = daño_fisico + armas.first->Get_daño_fisico();
    } else {
        daño = daño_fisico + armas.first->Get_daño_fisico() + armas.second->Get_daño_fisico();
    }
    enemigo->recibir_ataque(daño, FISICO, false);
    return;
}

void Guerreros::atacar_con_arma(shared_ptr<personaje> enemigo) {
    cout << "Con que arma quieres atacar?" << endl;
    if (armas.first != nullptr) {
        cout << "1. " << armas.first->Get_nombre() << endl;
    }
    if (armas.second != nullptr) {
        cout << "2. " << armas.second->Get_nombre() << endl;
    }
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 2) {
        cout << "Opcion invalida. Elige una opcion valida." << endl;
        cin >> opcion;
    }
    pair<int, TIPO_DAÑO> daño;
    if (opcion == 1) {
        daño = armas.first->Elegir_ataque();
    } else if (opcion == 2) {
        daño = armas.second->Elegir_ataque();
    }
    if (daño.second == FISICO) {
        daño.first += this->daño_fisico;
    }
    else{
        daño.first += this->daño_magico;
    }
    enemigo->recibir_ataque(daño.first, daño.second, false);
    return;
}


void Guerreros::recibir_efecto(EFFECTO efecto) {
    switch (efecto) {
        case PARALIZAR:
            this->vida = 0;
            break;
        case CONFUSION:
            this->vida = 0;
            break;
        case ENVENENAR:
            this->vida -= 10;
            break;
        case MIEDO:
            this->vida = 0;
            break;
        case INMOVILIZAR:
            this->vida = 0;
            break;
        case QUEMADURA:
            this->vida -= 10;
            break;
        case POTENCIAR_ALIADO:
            this->vida += 10;
            break;
    }
    return;
}