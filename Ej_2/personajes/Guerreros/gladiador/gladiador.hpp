#ifndef GLADIADOR_HPP
#define GLADIADOR_HPP

#include "../../Guerreros/Guerreros.hpp"

class gladiador : public Guerreros {
    private:
        int honor;
        int adrenalina;
        int capacidad_esquivar;
    
    public:
        gladiador(int v, int a, int rm, int e, string n);
        void aumentar_adrenalina(int daño_infligido);
        void embestida();

        void entretener_al_publico();
        void furia_romana();
        void espiritu_de_Julio_Cesar(); // ignora effectos negativos
};

#endif