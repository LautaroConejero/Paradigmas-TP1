#ifndef PERSONA_FACTORY_HPP
#define PERSONA_FACTORY_HPP

//MAGOS
#include "../Ej_1/personajes/Magos/nigromante/nigromante.hpp"
#include "../Ej_1/personajes/Magos/conjurador/conjurador.hpp"
#include "../Ej_1/personajes/Magos/hechizero/hechizero.hpp"
#include "../Ej_1/personajes/Magos/brujo/brujo.hpp"

//GUERREROS
#include "../Ej_1/personajes/Guerreros/mercenario/mercenario.hpp"
#include "../Ej_1/personajes/Guerreros/paladin/paladin.hpp"
#include "../Ej_1/personajes/Guerreros/caballero/caballero.hpp"
#include "../Ej_1/personajes/Guerreros/gladiador/gladiador.hpp"
#include "../Ej_1/personajes/Guerreros/barbaro/barbaro.hpp"

// ARMAS_COMBATE
#include "../Ej_1/armas/armas_combate/hacha_simple/hacha_simple.hpp"
#include "../Ej_1/armas/armas_combate/hacha_doble/hacha_doble.hpp"
#include "../Ej_1/armas/armas_combate/espada/espada.hpp"
#include "../Ej_1/armas/armas_combate/lanza/lanza.hpp"
#include "../Ej_1/armas/armas_combate/garrote/garrote.hpp"

// ITEMS_MAGICOS
#include "../Ej_1/armas/items_magicos/baston/baston.hpp"
#include "../Ej_1/armas/items_magicos/libro_de_hechizos/libro.hpp"
#include "../Ej_1/armas/items_magicos/pocion/pocion.hpp"
#include "../Ej_1/armas/items_magicos/amuleto/amuleto.hpp"

#include <memory>
using namespace std;

enum MAGOS {HECHICERO, CONJURADOR, BRUJO, NIGROMANTE};
enum GUERREROS{BARBARO, PALADIN, CABALLERO, MERCENARIO, GLADIADOR};

enum ARMA_COMBATE{HACHA_SIMPLE, HACHA_DOBLE, ESPADA, LANZA, GARROTE};
enum ITEM_MAGICOS{BASTON, LIBRO_DE_HECHIZOS, POCION, AMULETO};

class PersonajeFactory{
    public:
        static shared_ptr<personaje> Crear_personajes(int des, int tipo);
        static unique_ptr<arma> Crear_arma(int des);
        static shared_ptr<personaje> Equipar_personaje(int opcion, int cantidad_armas, int tipo);
};

#endif

