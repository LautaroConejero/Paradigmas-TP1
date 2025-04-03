#include "personajes.hpp"
#include <utility>

class Guerreros : personaje {
    protected:
    bool vivo;
    int vida;
    int armadura;
    int resistencia_magica;
    int daño_fisico;
    int daño_magico;
    int estamina;
    pair<shared_ptr<arma>, shared_ptr<arma>> armas;
    string nombre;

    public:

    Guerreros(int v, int a, int rm, int e, string n);
    virtual bool Esta_vivo() override;
    virtual string Get_nombre() override;
    virtual int Get_vida() override;
    virtual int Get_armadura() override;
    virtual int Get_resistencia_m() override;
    virtual int Get_estamina() override;
    virtual void recibir_ataque() override;
    virtual void equipar_armas(shared_ptr<arma> a) override;
    virtual pair<shared_ptr<arma>, shared_ptr<arma>> Get_armas() override;

};