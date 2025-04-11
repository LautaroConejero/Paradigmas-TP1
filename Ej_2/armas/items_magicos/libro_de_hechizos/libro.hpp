#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "../item_magicos.hpp"

class libro_de_hechizos : public Item_magicos {
    private:
        int probabilidad_ignorar_armadura;
        EFFECTO efecto_secundario = NINGUNO;
    public:
        libro_de_hechizos();
        pair<int, EFFECTO> lanzar_hechizo();
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif