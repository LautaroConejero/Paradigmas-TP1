#ifndef HECHIZERO_HPP
#define HECHIZERO_HPP

#include "../../Magos/Magos.hpp"


class hechizero : public Magos {
    private:
        int escudos_magicos;
        int escudos_fisicos;
        int cant_clones;
        bool clonado;



    public:
        hechizero();
        string Get_grupo() const override;
        string get_tipo_mago() const override;
        void confusion(shared_ptr<personaje> enemigo);
        void escudo_magico();
        void escudo_fisico();
        void recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) override;
        void restablecer_mana();
        void pocion_de_vida(shared_ptr<personaje> aliado);
        void clonar();
        void potenciar_aliado(shared_ptr<personaje> aliado);
        void rayo_arcano(shared_ptr<personaje> enemigo);



};




#endif