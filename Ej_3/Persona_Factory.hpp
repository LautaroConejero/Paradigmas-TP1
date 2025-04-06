#ifndef PERSONA_FACTORY_HPP
#define PERSONA_FACTORY_HPP

//MAGOS
#include "../Ej_2/personajes/Magos/nigromante/nigromante.hpp"
#include "../Ej_2/personajes/Magos/conjurador/conjurador.hpp"
#include "../Ej_2/personajes/Magos/hechizero/hechizero.hpp"
#include "../Ej_2/personajes/Magos/brujo/brujo.hpp"

//GUERREROS
#include "../Ej_2/personajes/Guerreros/mercenario/mercenario.hpp"
#include "../Ej_2/personajes/Guerreros/paladin/paladin.hpp"
#include "../Ej_2/personajes/Guerreros/caballero/caballero.hpp"
#include "../Ej_2/personajes/Guerreros/gladiador/gladiador.hpp"

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

