#ifndef NIGROMANTE_HPP
#define NIGROMANTE_HPP

enum INVOCACIONES_MUERTAS{
    ESQUELETO,
    ZOMBIE,
    ESPECTRO,
};

#include "../../Magos/Magos.hpp"
class Equipo;

class nigromante : public Magos {
    private:
        int resurrecciones_restantes;
        vector<pair<INVOCACIONES_MUERTAS, int>> invocaciones;
        int activacion_reino;

    public:
        nigromante(string n);
        string Get_grupo() const override;
        bool revivir_compañero(shared_ptr<personaje> aliado, Equipo aliados);
        void drenaje_vida(shared_ptr<personaje> enemigo);
        void invocar();
        void atacar_con_invocacion(shared_ptr<personaje> enemigo);
        void recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) override;
        void reino_de_los_muertos(shared_ptr<personaje> enemigo);     
};

#endif