#ifndef GLADIADOR_HPP
#define GLADIADOR_HPP

#include "../../Guerreros/Guerreros.hpp"

class gladiador : public Guerreros {
    private:
        int honor;
        int adrenalina;
        int capacidad_esquivar;

        bool esquivar_activado;
        int capacidad_adrenalina;

        int armadura_adrenalina;

        bool espiritu_activado;
        bool espiritu_usado;
        int cantidad_efectos_no_recibidos;
        int daño_honor;
        
    
    public:
        gladiador();
        string Get_grupo() const override;
        string Get_tipo_guerrero() const override;
        void aumentar_adrenalina(int daño_infligido);
        void aplicar_adrenalina(); // aumenta esquivar y armadura
        void embestida(shared_ptr<personaje> enemigo);
        void entretener_al_publico();
        void aplicar_honor(); // aumenta el daño fisico y la armadura, si el honor es mayor a 50
        void recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) override;
        void recibir_efecto(EFFECTO efecto) override;
        void ataque_rapido(shared_ptr<personaje> enemigo) override;
        void atacar_con_arma(shared_ptr<personaje> enemigo) override;
        void espiritu_de_Julio_Cesar(); // ignora effectos negativos
                                        // meterle que pueda atacar extra
};

#endif