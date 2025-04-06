#include "Persona_Factory.hpp"
#include <cstdlib>
#include <ctime>

shared_ptr<personaje> PersonajeFactory::Crear_personajes(int des){
    // random
    if (des == 2){
        int tipo = rand() % 2;
        int personaje_tipo;
        switch (tipo){
            case 0:
                personaje_tipo = rand() % 4;
                personaje_tipo = static_cast<MAGOS>(personaje_tipo);
                // switch(personaje_tipo){
                //     case HECHICERO:
                //         return make_shared<Hechizero>();
                //         break;
                //     case CONJURADOR:
                //         return make_shared<Conjurador>();
                //         break;
                //     case BRUJO:
                //         return make_shared<Brujo>();
                //         break;
                //     case NIGROMANTE:
                //         return make_shared<Nigromante>();
                //         break;
                // }
                break;
            case 1:
                personaje_tipo = rand() % 5;
                personaje_tipo = static_cast<GUERREROS>(personaje_tipo);
                // switch(personaje_tipo){
                //     case BARBARO:
                //         return make_shared<Barbaro>();
                //         break;
                //     case PALADIN:
                //         return make_shared<Paladin>();
                //         break;
                //     case CABALLERO:
                //         return make_shared<Caballero>();
                //         break;
                //     case MERCENARIO:
                //         return make_shared<Mercenario>();
                //         break;
                //     case GLADIADOR:
                //         return make_shared<Gladiador>();
                //         break;
                // }
                break;
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
        int tipo_personaje;
        if (opcion == 1){
            cout << "Elija el tipo de personaje: " << endl;
            cout << "0. Hechicero" << endl;
            cout << "1. Conjurador" << endl;
            cout << "2. Brujo" << endl;
            cout << "3. Nigromante" << endl;
            cin >> tipo_personaje;
            while (tipo_personaje < 1 || tipo_personaje > 4){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> tipo_personaje;
            }
            tipo_personaje = static_cast<MAGOS>(tipo_personaje);
            // switch(tipo_personaje){
            //     case HECHICERO:
            //         return make_shared<Hechizero>();
            //         break;
            //     case CONJURADOR:
            //         return make_shared<Conjurador>();
            //         break;
            //     case BRUJO:
            //         return make_shared<Brujo>();
            //         break;
            //     case NIGROMANTE:
            //         return make_shared<Nigromante>();
            //         break;
            // }
        }
        else {
            cout << "Elija el tipo de personaje: " << endl;
            cout << "0. Barbaro" << endl;
            cout << "1. Paladin" << endl;
            cout << "2. Caballero" << endl;
            cout << "3. Mercenario" << endl;
            cout << "4. Gladiador" << endl;
            cin >> tipo_personaje;
            while (tipo_personaje < 1 || tipo_personaje > 5){
                cout << "Opcion invalida. Elija nuevamente: " << endl;
                cin >> tipo_personaje;
            }
            tipo_personaje = static_cast<GUERREROS>(tipo_personaje);
            // switch(tipo_personaje){
            //     case BARBARO:
            //         return make_shared<Barbaro>();
            //         break;
            //     case PALADIN:
            //         return make_shared<Paladin>();
            //         break;
            //     case CABALLERO:
            //         return make_shared<Caballero>();
            //         break;
            //     case MERCENARIO:
            //         return make_shared<Mercenario>();
            //         break;
            //     case GLADIADOR:
            //         return make_shared<Gladiador>();
            //         break;
            // } 
         }
    }
    return nullptr; 
}

shared_ptr<arma> PersonajeFactory::Crear_arma(int des){
    // random
    if (des == 2){
        int tipo = rand() % 2;
        int arma_tipo;
        switch (tipo){
            case 0:
                arma_tipo = rand() % 5;
                arma_tipo = static_cast<ARMA_COMBATE>(arma_tipo);
                // switch(arma_tipo){
                //     case HACHA_SIMPLE:
                //         return make_shared<Hacha_simple>();
                //         break;
                //     case HACHA_DOBLE:
                //         return make_shared<Hacha_doble>();
                //         break;
                //     case ESPADA:
                //         return make_shared<Espada>();
                //         break;
                //     case LANZA:
                //         return make_shared<Lanza>();
                //         break;
                //     case GARROTE:
                //         return make_shared<Garrrote>();
                //         break;
                // }
                break;
            case 1:
                arma_tipo = rand() % 4;
                arma_tipo = static_cast<ITEM_MAGICOS>(arma_tipo);
                // switch(arma_tipo){
                //     case BASTON:
                //         return make_shared<Baston>();
                //         break;
                //     case LIBRO_DE_HECHIZOS:
                //         return make_shared<Libro_de_hechizos>();
                //         break;
                //     case POCION:
                //         return make_shared<Pocion>();
                //         break;
                //     case AMULETO:
                //         return make_shared<Amuleto>();
                //         break;
                // }
                break;
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
        int arma_tipo;

        if (opcion == 1){
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

            arma_tipo = static_cast<ARMA_COMBATE>(arma_tipo);
            
            // switch(arma_tipo){
            //     case HACHA_SIMPLE:
            //         return make_shared<Hacha_simple>();
            //         break;
            //     case HACHA_DOBLE:
            //         return make_shared<Hacha_doble>();
            //         break;
            //     case ESPADA:
            //         return make_shared<Espada>();
            //         break;
            //     case LANZA:
            //         return make_shared<Lanza>();
            //         break;
            //     case GARROTE:
            //         return make_shared<Garrrote>();
            //         break; 
            // }
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

            arma_tipo = static_cast<ITEM_MAGICOS>(arma_tipo);
            // switch(arma_tipo){
            //     case BASTON:
            //         return make_shared<Baston>();
            //         break;
            //     case LIBRO_DE_HECHIZOS:
            //         return make_shared<Libro_de_hechizos>();
            //         break;
            //     case POCION:
            //         return make_shared<Pocion>();
            //         break; 
            //     case AMULETO:
            //         return make_shared<Amuleto>();
            //         break; 
            // }
        }
    }
    return nullptr;
}
shared_ptr<personaje> PersonajeFactory::Equipar_personaje(int opcion, int cantidad_armas){
    shared_ptr<personaje> personaje = Crear_personajes(opcion);

    cout << "Tu " << personaje->Get_nombre() << " tiene " << cantidad_armas << " armas." << endl;
    for (int i = 0; i < cantidad_armas; i++){
        shared_ptr<arma> arma = Crear_arma(opcion);
        personaje->equipar_armas(arma);
    }
    return personaje;
}