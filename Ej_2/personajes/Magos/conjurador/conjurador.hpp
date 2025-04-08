#ifndef CONJURADOR_HPP
#define CONJURADOR_HPP

#include "../../Magos/Magos.hpp"


enum INVOCAIONES_ANIMALES{
    LOBO,
    OSO,
    AGUILA,
    SERPIENTE
};

class conjurador : public Magos {
    private:
        int invocaciones_maximas;
        vector<shared_ptr<arma>> invocaciones_vivas;
    
    public:
        conjurador(string n);
        string Get_grupo() const override;
        void invocar_animal();
        int ataque_con_invocacion();
        void paralisis(shared_ptr<personaje> enemigo);
        int llamado_de_la_naturaleza();
        int invocacion_maxima();


};


#endif