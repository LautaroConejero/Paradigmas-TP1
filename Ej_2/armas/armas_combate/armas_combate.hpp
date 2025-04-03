#include "armas.hpp"

class ArmaCombate : public Arma {
    protected:
        float daño;
        int durabilidad;
        float chance_critico;
    
    public:
        virtual  ataque_cargado();
}