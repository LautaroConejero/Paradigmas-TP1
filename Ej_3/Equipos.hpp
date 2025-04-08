#ifndef EQUIPOS_HPP
#define EQUIPOS_HPP

#include "Persona_Factory.hpp"

class Equipo {
    private:
        string nombre_equipo;
        vector<shared_ptr<personaje>> personajes;
        vector<shared_ptr<personaje>> personajes_vivos;
        int cantidad_personajes;
    
    public:
        Equipo(string nombre_equipo, int cantidad_personajes);
        void agregar_personaje(shared_ptr<personaje> p);
        void eliminar_muettos();
        void mostrar_personajes();
        int verificar_vivos();
        vector<shared_ptr<personaje>> devolver_personajes();
        vector<shared_ptr<personaje>> devolver_vivos();
};

#endif