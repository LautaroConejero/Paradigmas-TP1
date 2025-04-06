#ifndef CABALLERO_HPP
#define CABALLERO_HPP

#include "../../Guerreros/Guerreros.hpp"

class caballero : public Guerreros {
    private:
        bool proteccion;
        shared_ptr<personaje> protegido;

    public:
        caballero(int v, int a, int rm, int e, string n);
        void juramento_de_proteccion(shared_ptr<personaje> aliado);
        




};

#endif