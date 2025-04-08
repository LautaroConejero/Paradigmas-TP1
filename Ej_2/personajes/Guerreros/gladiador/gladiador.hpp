#ifndef GLADIADOR_HPP
#define GLADIADOR_HPP

#include "../../Guerreros/Guerreros.hpp"

class gladiador : public Guerreros {
    private:
        int honor;
        int adrenalina;
        int capacidad_esquivar;
        bool furia_activada;
    
    public:
        gladiador(string n);
        string Get_grupo() const override;
        void aumentar_adrenalina(int daño_infligido);
        void embestida(shared_ptr<personaje> enemigo);
        void entretener_al_publico();
        void furia_romana();
        void espiritu_de_Julio_Cesar(); // ignora effectos negativos
};

#endif