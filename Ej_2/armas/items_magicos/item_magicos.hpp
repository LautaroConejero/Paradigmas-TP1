#ifndef ITEM_MAGICOS_HPP
#define ITEM_MAGICOS_HPP

#include "../armas.hpp"

enum ENCANTAMIENTO{
    FUEGO,
    AGUA,
    TIERRA,
    AIRE,
    ELECTRICIDAD,
    HIELO
};

class Item_magicos : public arma {
    protected:
        string nombre;
        int durabilidad;
        int daño_fisico;
        int daño_magico;
        float chance_critico;
        ENCANTAMIENTO encantamiento;
    
    public:
        Item_magicos(string n, int d, int dm, float c);
        string Get_nombre() const override;
        int Get_durabilidad() const override;
        int Get_daño_fisico() const override;
        int Get_daño_magico() const override;
        float Get_chance_critico() const;
        string Get_encantamiento() const;
};

#endif