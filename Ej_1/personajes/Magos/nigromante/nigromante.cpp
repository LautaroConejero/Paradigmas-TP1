#include "nigromante.hpp"
#include "../../../Equipo/Equipos.hpp"

nigromante::nigromante():
Magos(10, 25, 80, 80, 30, "Mortalis"),
resurrecciones_restantes(2), activacion_reino(1){}

string nigromante::Get_grupo() const {
    return "Nigromante";
}
string nigromante::get_tipo_mago() const {
    return "Mago muerto";
}

bool nigromante::revivir_compañero(shared_ptr<personaje> aliado, shared_ptr<Equipo> aliados) {
    if (aliado->Esta_vivo()) {
        cout << "El nigromante no puede revivir a un aliado vivo." << endl;
        return false;
    }
    if (mana < 35) {
        cout << "No hay mana suficiente." << endl;
        return false;
    }
    if (resurrecciones_restantes > 0) {
        cout << "El nigromante desentierra de la tumba a " << aliado->Get_nombre() << endl;
        cout << "Vuelve a la vida con 30 de vida." << endl;

        aliado->morir(30);
        aliados->agregar_personaje(aliado);
        resurrecciones_restantes--;
        return true;
    }
    cout << "No quedan resurrecciones." << endl;
    return false;
}

void nigromante::drenaje_vida(shared_ptr<personaje> enemigo) {
    if (mana < 20) {
        cout << "No hay mana suficiente." << endl;
        return;
    }
    int vida_actual = enemigo->Get_vida();
    int vida_drenada = vida_actual * 0.2;
    this->vida += vida_drenada;
    enemigo->recibir_ataque(vida_drenada, MAGICO, true);
    cout << "El nigromante ha drenado " << vida_drenada << " de vida a " << enemigo->Get_nombre() << endl;
    mana -= 20;
    return;
}

void nigromante::invocar() {
    if (mana < 10) {
        cout << "No hay mana suficiente." << endl;
        return;
    }
    if (invocaciones.size() == 3) {
        cout << "No se pueden invocar mas criaturas." << endl;
        return;
    }
    cout << "El nigromante esta invocando a una entidad muerta." << endl;
    cout << "Elija la invocacion." << endl;
    cout << "1. Esqueleto." << endl;
    cout << "2. Zombie." << endl;
    cout << "3. Espectro." << endl;
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 4) {
        cout << "Opcion invalida. Elige una opcion valida." << endl;
        cin >> opcion;
    }
    int gasto_mana = 10;
    switch (opcion) {
        case 2:
            if (mana < 15) {
                cout << "No hay mana suficiente." << endl;
                return;
            }
            gasto_mana = 15;
        case 3:
            if (mana < 20) {
                cout << "No hay mana suficiente." << endl;
                return;
            }
            gasto_mana = 20;
    }
    opcion--;
    INVOCACIONES_MUERTAS invocacion = static_cast<INVOCACIONES_MUERTAS>(opcion);
    invocaciones.push_back(make_pair(invocacion, 5));
    cout << "El nigromante ha invocado a " << invocacion << endl;
    mana -= gasto_mana;
}

void nigromante::atacar_con_invocacion(shared_ptr<personaje> enemigo) {
    if (invocaciones.empty()) {
        cout << "No hay invocaciones disponibles." << endl;
        return;
    }
    int daño = 0;
    for (size_t i = 0; i < invocaciones.size(); i++){
        if (invocaciones[i].first == ESQUELETO || invocaciones[i].first == ESPECTRO) {
            daño += 10;
        } else if (invocaciones[i].first == ZOMBIE) {
            daño += 15;
            int probabilidad_envenanmiento = rand() % 100 + 1;
            if (probabilidad_envenanmiento <= 20) {
                cout << "El zombie ha envenenado a " << enemigo->Get_nombre() << endl;
                enemigo->recibir_efecto(ENVENENAR);
            }
        }
    }
    cout << "El nigromante ha atacado con sus invocaciones." << endl;
    enemigo->recibir_ataque(daño, FISICO, false);
}

void nigromante::recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) {
    if (protegido) {
        int mitigacion = rand() % 81 + 20; // 20% a 100% de mitigación
        int daño_mitigado = daño * mitigacion / 100; 
        daño -= daño_mitigado;
        cout << Get_nombre() << " está protegido y recibe solo " << daño << " de daño." << endl;
    }

    if (!invocaciones.empty()) {
        for (size_t i = 0; i < invocaciones.size(); i++){
            if (invocaciones[i].second < daño){
                cout << "La invocacion ha absorbido el ataque." << endl;
                cout << "La invocacion ha sido destruida." << endl;
                daño -= invocaciones[i].second;
                invocaciones.erase(invocaciones.begin() + i);
                i--;
            } else {
                cout << "La invocacion ha absorbido el ataque." << endl;
                cout << "La invocacion ha sobrevivido." << endl;
                invocaciones[i].second -= daño;
                return;
            }
        }
    }
    
    if (asustado) {
        daño *= 1.3;
        cout << Get_nombre() << " está asustado y recibe daño aumentado." << endl;
    }

    int vida_actual = vida;
    if (ignorar_armadura) {
        vida -= daño;
    } else {
        if (tipo == FISICO) {
            vida -= daño * (1 - armadura / 100.0);
        } else if (tipo == MAGICO) {
            vida -= daño * (1 - resistencia_magica / 100.0);
        }
    }
    cout << Get_nombre() << " recibe " << vida_actual - vida << " de daño." << endl;

    if (vida <= 0) {
        vida = 0;
        vivo = false;
        cout << Get_nombre() << " ha muerto." << endl;
    }
}
void nigromante::reino_de_los_muertos(shared_ptr<personaje> enemigo) {
    if (mana < 65){
        cout << "No hay maná suficiente." << endl;
        return;
    }
    if (activacion_reino == 0) {
        cout << "No quedan reinos de los muertos." << endl;
        return;
    }

    mana -= 65;
    activacion_reino--;

    cout << "El nigromante " << Get_nombre() << " ha absorbido el cuerpo de " << enemigo->Get_nombre() << "." << endl;
    cout << "Pelearán por dos rondas en el Reino de los Muertos..." << endl << endl;

    // Guardar estado original
    int vida_max_original = this->vida_maxima;
    int armadura_original = this->armadura;
    int resistencia_original = this->resistencia_magica;
    int daño_magico_original = this->daño_magico;

    // Absorción de estadísticas (20%)
    int vida_absorbida = enemigo->Get_vida_maxima() * 0.2;
    int armadura_absorbida = enemigo->Get_armadura() * 0.2;
    int resistencia_absorbida = enemigo->Get_resistencia_m() * 0.2;
    int poder_absorbido = 0;

    if (daño_fisico == 0){
        poder_absorbido = enemigo->Get_dano_fisico() * 0.2;
    } else {
        poder_absorbido = enemigo->Get_dano_magico() * 0.2;
    }

    this->vida += vida_absorbida;
    this->vida_maxima += vida_absorbida;
    this->armadura += armadura_absorbida;
    this->resistencia_magica += resistencia_absorbida;
    this->daño_magico += poder_absorbido;
    this->mana = mana_maximo * 0.5; // Restaura el 50% del maná máximo

    cout << "El nigromante absorbe 20 porceiento de las estadísticas del enemigo." << endl;
    cout << "Si sobrevive, conservará el poder robado." << endl << endl;

    // Simulación de las dos rondas
    for (int i = 0; i < 2; i++) {
        cout << "──── Ronda " << i + 1 << " ────" << endl;

        if (!this->Esta_vivo() || !enemigo->Esta_vivo()) break;

        this->drenaje_vida(enemigo);
        if (enemigo->Esta_vivo()) {
            enemigo->atacar(shared_from_this());
        }

        cout << endl;
    }

    // Si el nigromante muere, pierde todo lo robado
    if (!this->Esta_vivo()) {
        cout << "El nigromante ha sido derrotado en el Reino de los Muertos..." << endl;
    } 
    else if (!enemigo->Esta_vivo()) {
        cout << "El nigromante ha derrotado a " << enemigo->Get_nombre() << " en el Reino de los Muertos." << endl;
        cout << "Conserva el poder robado." << endl;
        

    } else {
        cout << "El nigromante pierde todo el poder robado." << endl;
        this->armadura = armadura_original;
        this->resistencia_magica = resistencia_original;
        this->daño_magico = daño_magico_original;
        this->vida_maxima = vida_max_original;
        if (this->vida - vida_absorbida < 0){
            this->vida = 1;
        } else {
            this->vida -= vida_absorbida;
        }
    }

    cout << endl;
    cout << "──── Fin del Reino de los Muertos ────" << endl;
    return;
}
