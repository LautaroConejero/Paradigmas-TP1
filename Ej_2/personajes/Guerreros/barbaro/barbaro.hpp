#ifndef BARBARO_HPP
#define BARBARO_HPP

#include "../../Guerreros/Guerreros.hpp"
class Equipo;
class barbaro : public Guerreros {
    private:
        int furia;
        int bonus_daño_furia = 0;
    
    public:
        barbaro(string n);
        string Get_grupo() const override;
        string Get_tipo_guerrero() const override;
        void aumentar_furia(int daño_infligido); // aumenta la furia al recibir daño o infligir daño
        void recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) override;
        void ataque_rapido(shared_ptr<personaje> enemigo) override;
        void atacar_con_arma(shared_ptr<personaje> enemigo) override;
        void aplicar_bonuses_por_furia(); 
        bool olfato_de_caza(shared_ptr<personaje> enemigo); // aumenta el daño de ataque si el enemigo bajo de vida
        void rompe_huesos(shared_ptr<personaje> enemigo); // ignora la armadura y hace daño adicional, consuma furia
        void grito_de_batalla(shared_ptr<Equipo> enemigos); // posibilidad de asustar a los enemigos y potenciar daño, si un barbaro en el otro equipo y no se asusta
        void recibir_efecto(EFFECTO efecto) override;
        void modo_berserker(); // inmune a la muerte por 3 turnos, se activa si con una furia necesaria y vida minima requerida
};

#endif