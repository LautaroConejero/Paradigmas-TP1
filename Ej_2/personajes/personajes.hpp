#include <iostream>
#include <string>
#include <memory>
using namespace std;

class personaje{
    public:
        virtual string Get_nombre() = 0;
        virtual int Get_vida() = 0;
        virtual int Get_armadura() = 0;
        virtual int Get_resistencia_m() - 0;
        virtual int Get_estamina() = 0;
        virtual void recibir_ataque(int daño) = 0;
        virtual void equipar_armas(shared_ptr<arma> a) = 0;
        virtual pair<shared_ptr<arma>, shared_ptr<arma>> Get_armas() = 0;
        virtual Esta_vivo() = 0;

};