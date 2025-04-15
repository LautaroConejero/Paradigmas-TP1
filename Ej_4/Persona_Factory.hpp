#ifndef PERSONA_FACTORY_HPP
#define PERSONA_FACTORY_HPP

//MAGOS
#include "personajes/Magos/nigromante/nigromante.hpp"
#include "personajes/Magos/conjurador/conjurador.hpp"
#include "personajes/Magos/hechizero/hechizero.hpp"
#include "personajes/Magos/brujo/brujo.hpp"

//GUERREROS
#include "personajes/Guerreros/mercenario/mercenario.hpp"
#include "personajes/Guerreros/paladin/paladin.hpp"
#include "personajes/Guerreros/caballero/caballero.hpp"
#include "personajes/Guerreros/gladiador/gladiador.hpp"
#include "personajes/Guerreros/barbaro/barbaro.hpp"

// ARMAS_COMBATE
#include "armas/armas_combate/hacha_simple/hacha_simple.hpp"
#include "armas/armas_combate/hacha_doble/hacha_doble.hpp"
#include "armas/armas_combate/espada/espada.hpp"
#include "armas/armas_combate/lanza/lanza.hpp"
#include "armas/armas_combate/garrote/garrote.hpp"

// ITEMS_MAGICOS
#include "armas/items_magicos/baston/baston.hpp"
#include "armas/items_magicos/libro_de_hechizos/libro.hpp"
#include "armas/items_magicos/pocion/pocion.hpp"
#include "armas/items_magicos/amuleto/amuleto.hpp"



#include <memory>
using namespace std;

enum MAGOS {HECHICERO, CONJURADOR, BRUJO, NIGROMANTE};
enum GUERREROS{BARBARO, PALADIN, CABALLERO, MERCENARIO, GLADIADOR};

enum ARMA_COMBATE{HACHA_SIMPLE, HACHA_DOBLE, ESPADA, LANZA, GARROTE};
enum ITEM_MAGICOS{BASTON, LIBRO_DE_HECHIZOS, POCION, AMULETO};

class PersonajeFactory{
    public:
        static shared_ptr<personaje> Crear_personajes(int des);
        static shared_ptr<arma> Crear_arma(int des);
        static shared_ptr<personaje> Equipar_personaje(int opcion, int cantidad_armas);
};

#endif

