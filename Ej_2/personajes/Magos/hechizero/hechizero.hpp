#ifndef HECHIZERO_HPP
#define HECHIZERO_HPP

#include "../../Magos/Magos.hpp"


class hechizero : public Magos {
    private:
        int escudos_magicos;
        int escudos_fisicos;
        vector<shared_ptr<personaje>> clones;



    public:
        hechizero(int v, int a, int rm, int m, string n);
        void confunsion(shared_ptr<personaje> enemigo);
        void escudo_magico();
        void escudo_fisico();
        void restablecer_mana();
        void pocion_de_vida(shared_ptr<personaje> aliado);
        void clonar();
        void potenciar_aliado(shared_ptr<personaje> aliado);
        int rayo_arcano();



};




#endif