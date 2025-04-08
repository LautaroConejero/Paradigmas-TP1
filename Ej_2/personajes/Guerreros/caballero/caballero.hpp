#ifndef CABALLERO_HPP
#define CABALLERO_HPP

#include "../../Guerreros/Guerreros.hpp"

class caballero : public Guerreros {
    private:
        bool proteccion;
        shared_ptr<personaje> protegido;

    public:
        caballero(string n);
        string Get_grupo() const override;
        void juramento_de_proteccion(shared_ptr<personaje> aliado);
        




};

#endif