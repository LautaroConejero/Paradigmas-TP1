#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#define FISICO_BASICO 5
#define MAGICO_BASICO 0

enum EFFECTO{
    PARALIZAR,
    CONFUSION,
    ENVENENAR,
    MIEDO,
    INMOVILIZAR,
    QUEMADURA,
    POTENCIAR_ALIADO
};

#include <iostream>
#include <string>
#include <memory>
#include "../armas/armas.hpp"
#include <vector>

using namespace std;

class personaje{
    public:
        virtual string Get_grupo() const = 0;
        virtual string Get_nombre() const = 0;
        virtual int Get_vida() const = 0;
        virtual int Get_vida_maxima() const = 0;
        virtual int Get_dano_fisico() const = 0;
        virtual int Get_dano_magico() const = 0;
        virtual int Get_armadura()const = 0;
        virtual int Get_resistencia_m() const = 0;
        virtual bool Esta_vivo() const = 0;
        virtual void morir(int vida_restante) = 0;
        virtual void recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) = 0;
        virtual void recibir_efecto(EFFECTO efecto) = 0;
        virtual void equipar_arma(shared_ptr<arma> a) = 0;
        virtual pair<shared_ptr<arma>,shared_ptr<arma>> Get_armas() = 0;
        virtual void eliminar_arma(int posicion) = 0;
        virtual void ataque_rapido(shared_ptr<personaje> enemigo) = 0;
        virtual void atacar_con_arma(shared_ptr<personaje> enemigo) = 0;
        //virtual void elegir_ataque(shared_ptr<personaje> enemigo) = 0;
        // virtual void usar_habilidad() = 0;



};

#endif