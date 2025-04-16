#include "mercenario.hpp"
#include "../../../Equipo/Equipos.hpp"

mercenario::mercenario(): 
Guerreros(15,10,80,80,30,"Kael") {
}

string mercenario::Get_grupo() const {
    return "Mercenario";
}

string mercenario::Get_tipo_guerrero() const {
    return "Guerrero inmoral";
}

void mercenario::robar_arma(shared_ptr<personaje> enemigo) {
    if (estamina < 40){
        cout << "No hay suficiente estamina." << endl;
        return;
    }
    if (this->arma_robada == nullptr) {
        if (enemigo->Get_armas().first != nullptr) {
            if (enemigo->Get_armas().second == nullptr) {
                cout << "El mercenario le ha robado" << this->arma_robada->Get_nombre() << " al enemigo." << endl;
                this->arma_robada= move(enemigo->Get_armas().first);
                enemigo->eliminar_arma(1);
            }
            cout << "Elija el arma que quieras robar." << endl;
            cout << "1. " << this->arma_robada->Get_nombre() << endl;
            cout << "2. " << enemigo->Get_armas().second->Get_nombre() << endl;
            int opcion;
            cin >> opcion;
            while (opcion < 1 || opcion > 2) {
                cout << "Opcion invalida. Elige una opcion valida." << endl;
                cin >> opcion;
            }
            if (opcion == 1) {
                enemigo->eliminar_arma(1);
            } else if (opcion == 2) {
                enemigo->eliminar_arma(2);
            }
        }
    } else {
        cout << "El mercenario ya tiene un arma robada." << endl;
    }
    estamina -= 40;
    cout << "El mercenario ha robado el arma " << this->arma_robada->Get_nombre() << " al enemigo." << endl;
    return;
}

void mercenario::robar_oro(shared_ptr<personaje> enemigo) {
    if (estamina < 10){
        cout << "No hay suficiente estamina." << endl;
        return;
    }
    cout << "El mercenario le esta robando oro a " << enemigo->Get_nombre() << endl;
    cout << "Veremos como la suerte le sonríe." << endl;
    int oro_robado = rand() % 201 + 100;
    cout << "El mercenario ha robado " << oro_robado << " de oro." << endl;
    this->oro_total += oro_robado;
    return;
}

void mercenario::aplicar_oro() {
    critico_oro = oro_total * 0.038;
    return;
}

void mercenario::ataque_rapido(shared_ptr<personaje> enemigo) {
    if (paralizado) {
        cout << Get_nombre() << " está paralizado y no puede atacar este turno." << endl;
        return;
    }

    if (confundido) {
        int prob = rand() % 100;
        if (prob < 35) {
            recibir_ataque(daño_fisico + daño_magico, FISICO, false);
            cout << Get_nombre() << " se ha atacado a sí mismo por confusión." << endl;
            return;
        }
    }

    int daño;
    if (armas.first == nullptr) {
        daño = daño_fisico;
    }
    else if (armas.second == nullptr) {
        daño = daño_fisico + armas.first->Get_daño_fisico();
    } else {
        daño = daño_fisico + armas.first->Get_daño_fisico() + armas.second->Get_daño_fisico();
    }

    if (quemado) {
        daño *= 0.8;
        cout << Get_nombre() << " está quemado y su daño fue reducido." << endl;
    }

    int daño_critico = 0;
    if (rand() % 100 < critico_oro) {
        daño_critico = daño;
        cout << "El mercenario ha hecho un golpe critico gracias a su oro" << endl;
    }
    enemigo->recibir_ataque(daño + daño_critico, FISICO, false);
    return;
}

void mercenario::atacar_con_arma(shared_ptr<personaje> enemigo) {

    if (paralizado) {
        cout << Get_nombre() << " está paralizado y no puede atacar este turno." << endl;
        return;
    }

    if (confundido) {
        int prob = rand() % 100;
        if (prob < 35) {
            recibir_ataque(daño_fisico + daño_magico, FISICO, false);
            cout << Get_nombre() << " se ha atacado a sí mismo por confusión." << endl;
            return;
        }
    }

    if (armas.first == nullptr && armas.second == nullptr) {
        cout << Get_nombre() << " no tiene armas equipadas." << endl;
        return;
    }

    cout << "Con que arma quieres atacar?" << endl;
    if (armas.first != nullptr) {
        cout << "1. " << armas.first->Get_nombre() << endl;
    }
    if (armas.second != nullptr) {
        cout << "2. " << armas.second->Get_nombre() << endl;
    }
    if (arma_robada != nullptr) {
        cout << "3. " << arma_robada->Get_nombre() << endl;
    }
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 3) {
        cout << "Opcion invalida. Elige una opcion valida." << endl;
        cin >> opcion;
    }
    pair<int, TIPO_DAÑO> daño;
    switch (opcion) {
        case 1:
            daño = armas.first->Atacar();
            break;
        case 2:
            daño = armas.second->Atacar();
            break;
        case 3:
            daño = arma_robada->Atacar();
            break;
    }
    if (daño.second == FISICO) {
        daño.first += this->daño_fisico;
    }
    else{
        daño.first += this->daño_magico;
    }

    if (quemado) {
        daño.first *= 0.8;
        cout << Get_nombre() << " está quemado y su daño fue reducido." << endl;
    }

    int daño_critico = 0;
    if (rand() % 100 < critico_oro) {
        daño_critico = daño.first;
        cout << "El mercenario ha hecho un golpe critico gracias a su oro" << endl;
    }
    enemigo->recibir_ataque(daño.first + daño_critico, daño.second, false);
    return;
}


void mercenario::contratar_sicario(shared_ptr<personaje> enemigo) {
    if (estamina < 35){
        cout << "No hay suficiente estamina." << endl;
        return;
    }
    if (oro_total < 600) {
        cout << "No hay suficiente oro." << endl;
        return;
    }
    cout << "El mercenario ha contratado un sicario." << endl;
    cout << "El sicario estara persiguiendo a " << enemigo->Get_nombre() << endl;
    marcar_enemigo(enemigo, "sicario");
    aplicar_oro();
    return;
}

void mercenario::asesinar_aliado(shared_ptr<Equipo> aliados) {
    if (aliados->verificar_vivos() == 1) {
        cout << "La jugada no salio como se esperaba..." << endl;
        cout << "No hay aliados vivos." << endl;
        cout << "El mercenario decide poner fin a su vida." << endl;
        morir(0);
        return;
    }
    cout << "Elija al aliado que estas dispuesto a asesinar." << endl;
    int opcion;
    vector<shared_ptr<personaje>> aliados_vivos = aliados->devolver_vivos();
    for (size_t i = 0; i < aliados_vivos.size(); i++){
        cout << i + 1 << ". " << aliados_vivos[i]->Get_nombre() << endl;
    }
    cin >> opcion;
    while (opcion < 1 || opcion > static_cast<int>(aliados_vivos.size())){
        cout << "Opcion invalida. Elija nuevamente: " << endl;
        cin >> opcion;
    }
    this->oro_total += 700;
    aplicar_oro();

    this->vida += aliados_vivos[opcion - 1]->Get_vida() * 0.5;
    this->daño_fisico += aliados_vivos[opcion - 1]->Get_dano_fisico() * 0.5;

    cout << "El mercenario ha sacrificado a " << aliados_vivos[opcion - 1]->Get_nombre() << endl;
    cout << "Gracias a su sacrificio, el mercenario ha ganado 700 de oro." << endl;
    cout << "El mercenario ha robado mitad de su vida, estamina y daño fisico." << endl;
    aliados_vivos[opcion - 1]->morir(0);
    return;
}

void mercenario::cañonazo(shared_ptr<personaje> enemigo) {
    if (estamina < 50){
        cout << "No hay suficiente estamina." << endl;
        return;
    }
    if (oro_total < 800) {
        cout << "No hay suficiente oro." << endl;
        return;
    }
    cout << "El mercenario ha iniciado un disparo de cañon a " << enemigo->Get_nombre() << endl;
    cout << "El cañon disparara en 2 rondas." << endl;
    marcar_enemigo(enemigo, "cañonazo");

    estamina -= 50;
    oro_total -= 800;
    return;
}

void mercenario::marcar_enemigo(shared_ptr<personaje> enemigo, string marca_tipo) {
    Marca marca;
    marca.enemigo = enemigo;
    marca.marca_tipo = marca_tipo;
    marcas_activas.push_back(marca);
    return;
}

void mercenario::procesar_marcas() {
    for (size_t i = 0; i < marcas_activas.size(); i++){
        marcas_activas[i].rondas_restantes--;

        if (marcas_activas[i].rondas_restantes == 0){
            aplicar_marcas(marcas_activas[i]);
            marcas_activas.erase(marcas_activas.begin() + i);
            i--;
        }
    }
    return;
}

void mercenario::aplicar_marcas(Marca marca){
    if (marca.enemigo->Esta_vivo() == false){
        cout << "El enemigo ya no esta vivo." << endl;
        return;
    }
    if (marca.marca_tipo == "sicario"){
        if((marca.enemigo->Get_vida()*100)/marca.enemigo->Get_vida_maxima() <= 15){ // si el muchacho tiene menos de 15% de vida
            marca.enemigo->morir(0);
            cout << "El sicario ha asesinado a " << marca.enemigo->Get_nombre() << endl;
            return;
        }
    }
    else if (marca.marca_tipo == "cañonazo"){
        cout << "El cañonazo ha impactado a " << marca.enemigo->Get_nombre() << endl;
        marca.enemigo->recibir_ataque(65, FISICO, false);
        return;
    }
    cout << "Le pifiaste de marca." << endl;
    return;
}