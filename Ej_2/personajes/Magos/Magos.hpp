#ifndef MAGOS_HPP
#define MAGOS_HPP

#include "../../personajes/personajes.hpp"
#include <utility>

class Magos : public personaje {
    protected:
        bool vivo;
        int vida;
        int vida_maxima;
        int armadura;
        int resistencia_magica;
        int daño_fisico;
        int daño_magico;
        int mana;
        int regeneracion_de_mana;
        pair<shared_ptr<arma>, shared_ptr<arma>> armas;
        string nombre;

    public:
        Magos(int v, int a, int rm, int m, string n);
        virtual bool Esta_vivo() override;
        virtual string Get_nombre() override;
        virtual int Get_vida() override;
        virtual int Get_armadura() override;
        virtual int Get_resistencia_m() override;
        virtual int Get_mana();
        virtual void recibir_ataque(int daño) override;
        virtual void equipar_armas(shared_ptr<arma> a) override;
        virtual string Get_armas() override;
        virtual int ataque_rapido() override;
        virtual int atacar_con_arma() override;
        
};

#endif