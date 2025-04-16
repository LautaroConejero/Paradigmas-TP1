#ifndef ARMAS_COMBATE_HPP
#define ARMAS_COMBATE_HPP

#include "../armas.hpp"

enum MATERIALES {
    HIERRO,
    ACERO,
    ORO,
    PLATA,
    MADERA,
    PIEDRA
};

class ArmaCombate : public arma {
    protected:
        string nombre;
        int daño_fisico;
        int daño_magico;
        int durabilidad;
        float chance_critico;
        MATERIALES material;
        bool ignorar_armadura = false;
        EFFECTO efecto_arma = NINGUNO;
    
    public:
        ArmaCombate(string n, int df, int d, float c);
        virtual ~ArmaCombate() = default;
        string Get_nombre() const override;
        virtual string Get_tipo() const = 0;
        int Get_durabilidad() const override;
        int Get_daño_fisico() const override;
        int Get_daño_magico() const override;
        float Get_chance_critico() const;
        string Get_material() const;   
};

#endif