#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "../../Guerreros/Guerreros.hpp"


class paladin : public Guerreros {
    private:
        bool escudo;
        int fe; 
        int vida_fe; 
        int estamina_fe; 
        int daño_fe;
    public:
        paladin(string n);
        string Get_grupo() const override;
        int Get_vida() const override;
        void usar_escudo();
        void aumentar_la_fe(int daño_infligido); 
        void aplicar_fe();
        void atacar_con_arma(shared_ptr<personaje> enemigo) override;
        void ataque_rapido(shared_ptr<personaje> enemigo) override; 
        void recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) override;
        void bendecir_armas(); // consume fe
        void golpe_divino(shared_ptr<personaje> enemigo); // consume fe
};

#endif