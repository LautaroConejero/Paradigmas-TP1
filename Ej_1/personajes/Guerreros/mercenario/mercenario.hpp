#ifndef MERCENARIO_HPP
#define MERCENARIO_HPP

#include "../Guerreros.hpp"

class Equipo;
struct Marca {
    shared_ptr<personaje> enemigo;
    int rondas_restantes = 2;
    string marca_tipo;
};
class mercenario : public Guerreros {
    private:
        int oro_total;
        float critico_oro;
        unique_ptr<arma> arma_robada = nullptr;
        vector<Marca> marcas_activas;
    public:
        mercenario();
        string Get_grupo() const override;
        string Get_tipo_guerrero() const override;
        void robar_arma(shared_ptr<personaje> enemigo);
        void robar_oro(shared_ptr<personaje> enemigo);
        void aplicar_oro();
        void ataque_rapido(shared_ptr<personaje> enemigo) override;
        void atacar_con_arma(shared_ptr<personaje> enemigo) override;
        void marcar_enemigo(shared_ptr<personaje> enemigo, string marca_tipo);
        void procesar_marcas();
        void aplicar_marcas(Marca marca);
        void contratar_sicario(shared_ptr<personaje> enemigo);
        void asesinar_aliado(shared_ptr<Equipo> aliados);
        void cañonazo(shared_ptr<personaje> enemigo);
    
};
#endif