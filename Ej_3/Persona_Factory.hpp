#include "personaje/personajes.hpp"
#include "armas/armas.hpp"
#include <memory>

enum MAGOS{HECHICERO, CONJURADOR, BRUJO, NIGROMANTE}
enum GUERREROS{BARBARO, PALADIN, CABALLERO, MERCENARIO, GLADIADOR}

enum ARMA_COMBATE{HACHA_SIMPLE, HACHA_DOBLE, ESPADA, LANZA, GARROTE}
enum ITEM_MAGICOS{BASTON, LIBRO_DE_HECHIZOS, POCION, AMULETO}

class PersonajeFactory{
    private:
        vector<shared_ptr<personaje>> personajes_equipados;
        int tamaño_personajes_equipados;

    public:
        PersonajeFactory(int tamaño);

        shared_ptr<personaje> Crear_personajes(int des);
        shared_ptr<personaje> Crear_arma(int des);
        void Equipar_personaje(int opcion);
}
