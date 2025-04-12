#ifndef CONJURADOR_HPP
#define CONJURADOR_HPP

#include "../../Magos/Magos.hpp"


enum INVOCAIONES_ANIMALES{
    LOBO,
    OSO,
    AGUILA,
    SERPIENTE
};

struct InvocacionAnimal {
    INVOCAIONES_ANIMALES tipo;
    int vida;
    int daño_fisico;
    float prob_efecto;
    EFFECTO efecto_asociado;
    bool usada = false;
    
};

class conjurador : public Magos {
    private:
        int invocaciones_maximas;
        vector<shared_ptr<InvocacionAnimal>> invocaciones_vivas;
    
    public:
        conjurador();
        string Get_grupo() const override;
        string get_tipo_mago() const override;
        void invocar_animal();
        void ataque_con_invocacion(shared_ptr<personaje> enemigo);
        void recibir_ataque(int daño, TIPO_DAÑO tipo, bool ignorar_armadura) override;
        void paralisis(shared_ptr<personaje> enemigo);
        void efecto_aleatorio(shared_ptr<personaje> enemigo);
        bool invocacion_maxima(shared_ptr<personaje> enemigo);


};


#endif