#ifndef BASTON_HPP
#define BASTON_HPP

#include "../item_magicos.hpp"

class baston : public Item_magicos {
    public:
        baston();
        string Get_calidad() const override;
        int rafaga_magica();
        int canalizacion_elemental();
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif