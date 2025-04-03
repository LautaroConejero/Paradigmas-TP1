#include "Persona_Factory.cpp"
#include <cstdlib>
#include <ctime>

PersonajeFactory::PersonajeFactory(int tamaño)
tamaño_personajes_equipados(){}

shared_ptr<personaje> PersonajeFactory::Crear_personajes(int des){
    // random
    if (des == 2){
        int tipo = rand() % 2;
        switch (tipo){
            case 0:
                MAGOS personaje_tipo = rand() % 4;
                switch(personaje_tipo){
                    case HECHICERO:
                        return make_shared<Hechizero>();
                        break;
                    case CONJURADOR:
                        return make_shared<Conjurador>();
                        break;
                    case BRUJO:
                        return make_shared<Brujo>();
                        break;
                    case NIGROMANTE:
                        return make_shared<Nigromante>();
                        break;
                }
            case 1:
                GUERREROS personaje_tipo = rand() % 5;
                switch(personaje_tipo){
                    case BARBARO:
                        return make_shared<Barbaro>();
                        break;
                    case PALADIN:
                        return make_shared<Paladin>();
                        break;
                    case CABALLERO:
                        return make_shared<Caballero>();
                        break;
                    case MERCENARIO:
                        return make_shared<Mercenario>();
                        break;
                    case GLADIADOR:
                        return make_shared<Gladiador>();
                        break;
                }
        }
    }
    else {
        cout << "Elija la categoria de personaje: " << endl;
        cout << "1. Magos" << endl;
        cout << "2. Guerreros" << endl;
        int opcion;
        cin >> opcion;
        while (opcion != 1 && opcion != 2){
            cout << "Opcion invalida. Elija nuevamente: " << endl;
            cin >> opcion;
        }
        if (opcion == 1){
            cout << "Elija el tipo de personaje: " << endl;
            cout << "0. Hechicero" << endl;
            cout << "1. Conjurador" << endl;
            cout << "2. Brujo" << endl;
            cout << "3. Nigromante" << endl;
            MAGOS tipo_personaje;
            cin >> tipo_personaje;
            while (tipo_personaje < 1 || tipo_personaje > 4){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> tipo_personaje;
            }
            switch(tipo_personaje){
                case HECHICERO:
                    return make_shared<Hechizero>();
                    break;
                case CONJURADOR:
                    return make_shared<Conjurador>();
                    break;
                case BRUJO:
                    return make_shared<Brujo>();
                    break;
                case NIGROMANTE:
                    return make_shared<Nigromante>();
                    break;
            }
        }
        else {
            cout << "Elija el tipo de personaje: " << endl;
            cout << "0. Barbaro" << endl;
            cout << "1. Paladin" << endl;
            cout << "2. Caballero" << endl;
            cout << "3. Mercenario" << endl;
            cout << "4. Gladiador" << endl;
            Guerrero tipo_personaje;
            cin >> tipo_personaje;
            while (tipo_personaje < 1 || tipo_personaje > 5){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> tipo_personaje;
            }
            switch(tipo_personaje){
                case BARBARO:
                    return make_shared<Barbaro>();
                    break;
                case PALADIN:
                    return make_shared<Paladin>();
                    break;
                case CABALLERO:
                    return make_shared<Caballero>();
                    break;
                case MERCENARIO:
                    return make_shared<Mercenario>();
                    break;
                case GLADIADOR:
                    return make_shared<Gladiador>();
                    break; 
            }
        }
    }
}

shared_ptr<arma> PersonajeFactory::Crear_arma(int des){
    // random
    if (des == 2){
        int tipo = rand() % 2;
        switch (tipo){
            case 0:
                ARMA_COMBATE arma_tipo = rand() % 5;
                switch(arma_tipo){
                    case HACHA_SIMPLE:
                        return make_shared<Hacha_simple>();
                        break;
                    case HACHA_DOBLE:
                        return make_shared<Hacha_doble>();
                        break;
                    case ESPADA:
                        return make_shared<Espada>();
                        break;
                    case LANZA:
                        return make_shared<Lanza>();
                        break;
                    case GARROTE:
                        return make_shared<Garrrote>();
                        break;
                }
            case 1:
                ITEM_MAGICOS item_tipo = rand() % 4;
                switch(item_tipo){
                    case BASTON:
                        return make_shared<Baston>();
                        break;
                    case LIBRO_DE_HECHIZOS:
                        return make_shared<Libro_de_hechizos>();
                        break;
                    case POCION:
                        return make_shared<Pocion>();
                        break;
                    case AMULETO:
                        return make_shared<Amuleto>();
                        break;
                }
        }
    }
    else{
        cout << "Elija la categoria de arma: " << endl;
        cout << "1. Armas de combate" << endl;
        cout << "2. Items magicos" << endl;
        int opcion;
        cin >> opcion;
        while (opcion != 1 && opcion != 2){
            cout << "Opcion invalida. Elija nuevamente: " << endl;
            cin >> opcion;
        }
        if (opcion == 1){
            cout << "Elija el tipo de arma: " << endl;
            cout << "0. Hacha simple" << endl;
            cout << "1. Hacha doble" << endl;
            cout << "2. Espada" << endl;
            cout << "3. Lanza" << endl;
            cout << "4. Garrote" << endl;
            ARMA_COMBATE tipo_arma;
            cin >> tipo_arma;
            while (tipo_arma < 1 || tipo_arma > 5){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> tipo_arma;
            }
            switch(tipo_arma){
                case HACHA_SIMPLE:
                    return make_shared<Hacha_simple>();
                    break;
                case HACHA_DOBLE:
                    return make_shared<Hacha_doble>();
                    break;
                case ESPADA:
                    return make_shared<Espada>();
                    break;
                case LANZA:
                    return make_shared<Lanza>();
                    break;
                case GARROTE:
                    return make_shared<Garrrote>();
                    break; 
            }
        }
        else {
            cout << "Elija el tipo de item magico: " << endl;
            cout << "0. Baston" << endl;
            cout << "1. Libro de hechizos" << endl;
            cout << "2. Pocion" << endl;
            cout << "3. Amuleto" << endl;
            ITEM_MAGICOS tipo_item_magico;
            cin >> tipo_item_magico;
            while (tipo_item_magico < 1 || tipo_item_magico > 4){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> tipo_item_magico;
            }
            switch(tipo_item_magico){
                case BASTON:
                    return make_shared<Baston>();
                    break;
                case LIBRO_DE_HECHIZOS:
                    return make_shared<Libro_de_hechizos>();
                    break;
                case POCION:
                    return make_shared<Pocion>();
                    break; 
                case AMULETO:
                    return make_shared<Amuleto>();
                    break; 
            }
        }
    }
}
void PersonajeFactory::Equipar_personaje(int opcion){
    shared_ptr<personaje> personaje = Crear_personajes(opcion);

    int cantidad_armas = rand() % 3;
    cout << "Tu " << personaje->Get_nombre() << " tiene " << cantidad_armas << " armas." << endl;
    for (int i = 0; i < cantidad_armas; i++){
        shared_ptr<arma> arma = Crear_arma(opcion);
        personaje->equipar_armas(arma);
    }
    personajes_equipados.push_back(personaje);
    return;
}