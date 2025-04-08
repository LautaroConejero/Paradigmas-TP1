#ifndef BRUJO_HPP
#define BRUJO_HPP
#include "../../Magos/Magos.hpp"


enum MALDICIONES{
    INMOVILIZACION,
    ENVENENAMIENTO,
    HEMORRAGIA,
    MALA_SUERTE
};

class brujo : public Magos {
    private:
        bool estado_frenesi; // puede seguir peleando aunque haya perdido toda su vida

    public:
        brujo(string n);
        string Get_grupo() const override;
        void maldecir_enemigo(shared_ptr<personaje> enemigo);
        void control_mental(vector<shared_ptr<personaje>> enemigos);
        void estado_de_frenesi();
        void pacto_demoniaco();
};

#endif