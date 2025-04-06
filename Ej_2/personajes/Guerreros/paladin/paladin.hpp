#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "../../Guerreros/Guerreros.hpp"


class paladin : public Guerreros {
    private:
        bool escudo;
        int fe; // aumenta porcentualmente la vida y la estamina
    public:
        paladin(int v, int a, int rm, int e, string n);
        void usar_escudo(shared_ptr<personaje> aliado);
        void aumentar_la_fe();
        void bendecir_arma(); // consume fe
        int golpe_divino();
};

#endif