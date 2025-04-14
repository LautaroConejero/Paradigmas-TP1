#include "hechizero.hpp"

hechizero::hechizero(): 
Magos(5, 25, 100, 100, 40, "Almeth"),
escudos_magicos(0), escudos_fisicos(0), 
cant_clones(0), clonado(false) {}

string hechizero::Get_grupo() const {
    return "Hechizero";
}

string hechizero::get_tipo_mago() const{
    return "Mago blanco";
}

void hechizero::escudo_magico(){
    if (this->mana >= 10){
        this->mana -= 10;
        this->escudos_magicos += 14;
        cout << "Escudo magico activado." << endl;
    } else {
        cout << "No hay mana suficiente." << endl;
    }
}

void hechizero::escudo_fisico(){
    if (this->mana >= 10){
        this->mana -= 10;
        this->escudos_fisicos += 11;
        cout << "Escudo fisico activado." << endl;
    } else {
        cout << "No hay mana suficiente." << endl;
    }
}

void hechizero::recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) {
    if (protegido) {
        int mitigacion = rand() % 81 + 20; // 20% a 100% de mitigación
        int daño_mitigado = daño * mitigacion / 100; 
        daño -= daño_mitigado;
        cout << Get_nombre() << " está protegido y recibe solo " << daño << " de daño." << endl;
    }

    if (clonado == true){
        int probabilida_fallar = 15*cant_clones;
        int probabilidad = rand() % 100 + 1;
        if (probabilidad <= probabilida_fallar){
            cout << "El hechizero se ha salvado del ataque." << endl;
            cout << "Un clon ha sido destruido." << endl;
            this->cant_clones--;
            if (this->cant_clones == 0){
                this->clonado = false;
            }
            return;
        }
    }

    if (asustado) {
        daño *= 1.3;
        cout << Get_nombre() << " está asustado y recibe daño aumentado." << endl;
    }

    int vida_actual = vida;

    if (ignorar_armadura == true){
        this->vida -= daño;
        cout << "El hechizero ha recibido " << daño << " de daño." << endl;
        return;
    }
    if (tipo == FISICO) {
        if (this->escudos_fisicos > 0){
            this->vida -= daño*(1 - this->armadura/100.0) - this->escudos_fisicos;
            cout << "El escudo a absorbido " << this->escudos_fisicos <<endl;
            this->escudos_fisicos = 0;
        } else {
            this->vida -= daño*(1 - this->armadura/100.0);
        }
    } else if (tipo == MAGICO) {
        if (this->escudos_magicos > 0){
            this->vida -= daño*(1 - this->resistencia_magica/100.0) + this->escudos_magicos;
            cout << "El escudo a absorbido " << this->escudos_magicos <<endl;
            this->escudos_magicos = 0;
        } else {
            this->vida -= daño*(1 - this->resistencia_magica/100.0);
        }
    }
    cout << Get_nombre() << " recibe " << vida_actual - vida << " de daño." << endl;
    
    if (this->vida < 0) {
        this->morir(0);
    }
}

void hechizero::confusion(shared_ptr<personaje> enemigo){
    if (this->mana >= 10){
        this->mana -= 20;
        enemigo->recibir_efecto(CONFUSION);
        cout << "El hechizero ha confundido al enemigo."<< enemigo->Get_nombre() << endl;
    } else {
        cout << "No hay mana suficiente." << endl;
    }
    return;
}

void hechizero::pocion_de_vida(shared_ptr<personaje> aliado){
    if (this->mana >= 15){
        this->mana -= 15;
        aliado->recibir_ataque(-20, FISICO, true);
        cout << "La pocion de vida ha sido activada." << endl;
        cout << "EL aliado " << aliado->Get_nombre() << " ha recuperado 20 de vida." << endl;
    } else {
        cout << "No hay mana suficiente." << endl;
    }
    return;
}

void hechizero::clonar(){
    if (this->mana >= 20){
        this->mana -= 20;
        this->cant_clones++;
        this->clonado = true;
        cout << "El hechizero " << this->Get_nombre() << " ha sido clonado." << endl;
        cout << "Ahora mismo hay " << cant_clones << " clones." << endl;
    }
    else {
        cout << "No hay mana suficiente." << endl;
    }
    return;
}

void hechizero::potenciar_aliado(shared_ptr<personaje> aliado){
    if (this->mana >= 15){
        this->mana -= 15;
        aliado->recibir_efecto(POTENCIAR_ALIADO);
        cout << "El hechizero ha potenciado al aliado."<< aliado->Get_nombre() << endl;
        cout << "El aliado ha recibido un bono de ataque adaptable." << endl;
    }
    else {
        cout << "No hay mana suficiente." << endl;
    }
    return;
}

void hechizero::restablecer_mana(){
    this ->mana += 30;
    cout << "El hechizero " << this->Get_nombre() << " ha recuperado 30 de mana." << endl;
    return;
}

void hechizero::rayo_arcano(shared_ptr<personaje> enemigo){
    if (this->mana >= 20){
        this->mana -= 40;
        cout << "El hechizero " << this->Get_nombre() << " ha lanzado un rayo arcano." << endl;
        int critico = 0;
        if (rand() % 100 < 7)
        {
            critico = 1;
            cout << "El rayo arcano ha sido mas fuerte de lo esperado!" << endl;
            cout << "Su daño ha sido aumentado." << endl;
        }
        int daño_arcano = 38 + critico*12;
        cout << "El hechizero ha hecho " << daño_arcano << " de daño." << endl;
        enemigo->recibir_ataque(daño_arcano, MAGICO, false);

    }
}