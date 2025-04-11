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
        int mana_maximo;
        string nombre;
        pair<shared_ptr<arma>, shared_ptr<arma>> armas;
        vector<shared_ptr<EfectoActivo>> efectos;
        bool paralizado = false;
        bool confundido = false;
        bool asustado = false;
        bool quemado = false;
        bool hemorragia = false;
        bool potenciado = false;
        bool protegido = false;
        bool inmortal = false;

    public:
        Magos(int a, int rm, int m, int mm, int dm, string n);
        bool Esta_vivo() const override;
        string Get_nombre() const override;
        virtual string get_tipo_mago() const = 0;
        
        int Get_dano_fisico() const override;
        int Get_dano_magico() const override;
        int Get_vida() const override;
        int Get_vida_maxima() const override;
        void morir(int vida_restante) override;
        int Get_armadura() const override;
        int Get_resistencia_m() const override;

        int Get_mana() const;
        virtual void recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) override;
        
        void equipar_arma(shared_ptr<arma> a) override;
        void eliminar_arma(int posicion) override;
        pair<shared_ptr<arma>,shared_ptr<arma>> Get_armas() override;
        
        void ataque_rapido(shared_ptr<personaje> enemigo) override;
        void atacar_con_arma(shared_ptr<personaje> enemigo) override;
        void recibir_efecto(EFFECTO efecto) override;
        void procesar_efectos() override;
        
};

#endif