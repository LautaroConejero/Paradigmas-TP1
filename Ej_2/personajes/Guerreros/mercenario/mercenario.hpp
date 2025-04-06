#ifndef MERCENARIO_HPP
#define MERCENARIO_HPP

#include "../../Guerreros/Guerreros.hpp"

class mercenario : public Guerreros {
    private:
        shared_ptr<arma> arma_robada;
        int oro_total;
        bool sicario;
        bool cañon;

    public:
        mercenario(int v, int a, int rm, int e, string n);
        void robar_arma(shared_ptr<personaje> enemigo);
        void robar_oro(shared_ptr<personaje> enemigo);
        void contratar_sicario();
        void ataque_con_sicario(vector<shared_ptr<personaje>> enemigos);
        void asesinar_aliado(shared_ptr<personaje> aliado);

        void cañonazo();
        int ataque_con_cañonazo();
    

};
#endif