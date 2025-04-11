#ifndef BRUJO_HPP
#define BRUJO_HPP
#include "../../Magos/Magos.hpp"


class Equipo; 

class brujo : public Magos {
    private:
        bool estado_frenesi; // puede seguir peleando aunque haya perdido toda su vida
        bool demonio_invocado; // puede invocar un demonio para que lo ayude en la batalla
        bool pacto_usado; // Si ya hizo un pacto demoníaco
        int rondas_pacto; // Cuantas rondas quedan para que el pacto termine
    public:
        brujo(string n);
        string Get_grupo() const override;
        string get_tipo_mago() const override;
        void maldecir_enemigo(shared_ptr<personaje> enemigo);
        void control_mental(shared_ptr<Equipo> enemigos, shared_ptr<personaje> enemigo);
        void estado_de_frenesi();
        void recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) override;
        void ataque_rapido(shared_ptr<personaje> enemigo) override;
        void atacar_con_arma(shared_ptr<personaje> enemigo) override;
        void pacto_demoniaco();
        void procesar_efectos() override;
};

#endif