#ifndef POCION_HPP
#define POCION_HPP

#include "../item_magicos.hpp"

class pocion : public Item_magicos {
        private:
            bool explosion = false;
            int probabilidad_explotar = 3; // 3% de probabilidad de explotar

    public:
        pocion();
        ~pocion() = default;
        string Get_calidad() const override;
        int explosion_alquimica();
        void exploto();
        int salpicadura_corrosiva();
        pair<int, TIPO_DAÑO> Atacar() override;
};

#endif