#ifndef AMULETO_HPP
#define AMULETO_HPP

#include "../item_magicos.hpp"

class amuleto : public Item_magicos {
    public:
        amuleto();
        int pulso_arcano();
        int estallido_canalizado();
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif