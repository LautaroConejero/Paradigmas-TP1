#ifndef NIGROMANTE_HPP
#define NIGROMANTE_HPP

#include "../../Magos/Magos.hpp"


class nigromante : public Magos {
    private:
        int resurrecciones;
        vector<shared_ptr<personaje>> invocaciones;

    public:
        nigromante(int v, int a, int rm, int m, string n);
        bool revivir_compañero();
        void drenaje_vida(shared_ptr<personaje> enemigo);
        void invocar();
        int atacar_con_invocacion();
        void reino_de_los_muertos(shared_ptr<personaje> enemigo);     
};

#endif