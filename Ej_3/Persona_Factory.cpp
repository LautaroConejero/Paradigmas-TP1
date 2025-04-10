#include "Persona_Factory.hpp"
#include <cstdlib>
#include <ctime>

shared_ptr<personaje> PersonajeFactory::Crear_personajes(int des){
    // random
    int personaje_tipo;
    int tipo;
    if (des == 2){
        tipo = rand() % 2 + 1;
        if (tipo == 1){
            personaje_tipo = rand() % 4;
        }
        else{
            personaje_tipo = rand() % 5;
        }
    }
    else {
        cout << "Elija la categoria de personaje: " << endl;
        cout << "1. Magos" << endl;
        cout << "2. Guerreros" << endl;
        cin >> tipo;
        while (tipo != 1 && tipo != 2){
            cout << "Opcion invalida. Elija nuevamente: " << endl;
            cin >> tipo;
        }
        if (tipo == 1){
            cout << "Elija el tipo de personaje: " << endl;
            cout << "0. Hechicero" << endl;
            cout << "1. Conjurador" << endl;
            cout << "2. Brujo" << endl;
            cout << "3. Nigromante" << endl;
            cin >> personaje_tipo;
            while (personaje_tipo < 0 || personaje_tipo > 3){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> personaje_tipo;
            }
        }
        else {
            cout << "Elija el tipo de personaje: " << endl;
            cout << "0. Barbaro" << endl;
            cout << "1. Paladin" << endl;
            cout << "2. Caballero" << endl;
            cout << "3. Mercenario" << endl;
            cout << "4. Gladiador" << endl;
            cin >> personaje_tipo;
            while (personaje_tipo < 0 || personaje_tipo > 4){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> personaje_tipo;
            }  
        }
    }
    switch (tipo){
        case 1:
            personaje_tipo = static_cast<MAGOS>(personaje_tipo);
            switch(personaje_tipo){
                case HECHICERO:
                    return make_shared<hechizero>("Lauti");
                    break;
                case CONJURADOR:
                    return make_shared<conjurador>("Lauti");
                    break;
                case BRUJO:
                    return make_shared<brujo>("Lauti");
                    break;
                case NIGROMANTE:
                    return make_shared<nigromante>("Lauti");
                    break;
            }
            break;
        case 2:
            personaje_tipo = static_cast<GUERREROS>(personaje_tipo);
            switch(personaje_tipo){
                case BARBARO:
                    return make_shared<barbaro>("Lauti");
                    break;
                case PALADIN:
                    return make_shared<paladin>("Lauti");
                    break;
                case CABALLERO:
                    return make_shared<caballero>("Lauti");
                    break;
                case MERCENARIO:
                    return make_shared<mercenario>("Lauti");
                    break;
                case GLADIADOR:
                    return make_shared<gladiador>("Lauti");
                    break;
            }
            break;
    }
    return nullptr;
}

shared_ptr<arma> PersonajeFactory::Crear_arma(int des){
    // random
    int tipo;
    int arma_tipo;
    if (des == 2){
        tipo = rand() % 2 + 1;
        if (des == 2){
            tipo = rand() % 2 + 1;
            if (tipo == 1){
                arma_tipo = rand() % 5;
            }
            else{
                arma_tipo = rand() % 4;
            }
        }
    }
    else{
        cout << "Elija la categoria de arma: " << endl;
        cout << "1. Armas de combate" << endl;
        cout << "2. Items magicos" << endl;
        cin >> tipo;
        while (tipo != 1 && tipo != 2){
            cout << "Opcion invalida. Elija nuevamente: " << endl;
            cin >> tipo;
        }

        if (tipo == 1){
            cout << "Elija el tipo de arma: " << endl;
            cout << "0. Hacha simple" << endl;
            cout << "1. Hacha doble" << endl;
            cout << "2. Espada" << endl;
            cout << "3. Lanza" << endl;
            cout << "4. Garrote" << endl;
            cin >> arma_tipo;
            while (arma_tipo < 1 || arma_tipo > 5){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> arma_tipo;
            }
        }
        else {
            cout << "Elija el tipo de item magico: " << endl;
            cout << "0. Baston" << endl;
            cout << "1. Libro de hechizos" << endl;
            cout << "2. Pocion" << endl;
            cout << "3. Amuleto" << endl;
            cin >> arma_tipo;
            while (arma_tipo < 1 || arma_tipo > 4){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> arma_tipo;
            }
        }
    } 
    switch(tipo){
        case 1:
            arma_tipo = static_cast<ARMA_COMBATE>(arma_tipo);
            
            switch(arma_tipo){
                case HACHA_SIMPLE:
                    return make_shared<hacha_simple>();
                    break;
                case HACHA_DOBLE:
                    return make_shared<hacha_doble>();
                    break;
                case ESPADA:
                    return make_shared<espada>();
                    break;
                case LANZA:
                    return make_shared<lanza>();
                    break;
                case GARROTE:
                    return make_shared<garrote>();
                    break; 
            }
            break;
        case 2:
            arma_tipo = static_cast<ITEM_MAGICOS>(arma_tipo);
            switch(arma_tipo){
                case BASTON:
                    return make_shared<baston>();
                    break;
                case LIBRO_DE_HECHIZOS:
                    return make_shared<libro_de_hechizos>();
                    break;
                case POCION:
                    return make_shared<pocion>();
                    break; 
                case AMULETO:
                    return make_shared<amuleto>();
                    break; 
            }
    }
    return nullptr;
}
shared_ptr<personaje> PersonajeFactory::Equipar_personaje(int opcion, int cantidad_armas){
    shared_ptr<personaje> personaje = Crear_personajes(opcion);

    cout << "Tu " << personaje->Get_nombre() << " tiene " << cantidad_armas << " armas." << endl;
    for (int i = 0; i < cantidad_armas; i++){
        shared_ptr<arma> arma = Crear_arma(opcion);
        personaje->equipar_arma(arma);
    }
    return personaje;
}