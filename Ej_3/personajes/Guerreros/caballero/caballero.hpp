#ifndef CABALLERO_HPP
#define CABALLERO_HPP

#include "../../Guerreros/Guerreros.hpp"

class caballero : public Guerreros {
    private:

    public:
        caballero();
        string Get_grupo() const override;
        string Get_tipo_guerrero() const override;
        void juramento_de_proteccion(shared_ptr<personaje> aliado);
};

#endif