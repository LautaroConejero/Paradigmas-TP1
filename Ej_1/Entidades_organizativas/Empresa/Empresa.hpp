#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "../Entidades_organizativas.hpp"
#include "../../Departamento/Departamento.hpp"

class Empresa : public EntidadOrganizativa {
    private:
        vector<Departamento> departamentos;
        string direccion;

    public:
        Empresa(string nombre, string direccion);
        Departamento getDepByName(string nombre) const;
        vector<string> getDepNames() const;
        booo agregarDepartamento(Departamento departamento);
        bool eliminarDepartamento(string nombre);
};

#endif