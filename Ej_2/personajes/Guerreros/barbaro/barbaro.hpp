#ifndef BARBARO_HPP
#define BARBARO_HPP

#include "../../Guerreros/Guerreros.hpp"

class barbaro : public Guerreros {
    private:
        bool berserker;
        int furia;
    
    public:
        barbaro(string n);
        string Get_grupo() const override;
        void aumentar_furia(int daño_infligido); // aumenta la furia al recibir daño o infligir daño
        bool olfato_de_caza(shared_ptr<personaje> enemigo); // aumenta el daño de ataque y la probabilidad de critico, si el enemigo bajo de vida
        void rompe_huesos(shared_ptr<personaje> enemigo); // ignora la armadura y hace daño adicional, consuma furia
        void grito_de_batalla(); // posibilidad de asustar a los enemigos y potenciar daño, si un barbaro en el otro equipo y no se asusta, devuelve el grito
        void modo_berserker(); // inmune a la muerte por 3 turnos, se activa si con una furia necesaria y vida minima requerida
};

#endif