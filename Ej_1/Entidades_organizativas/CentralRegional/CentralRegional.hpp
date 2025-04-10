#ifndef CENTRAL_REGIONAL_HPP
#define CENTRAL_REGIONAL_HPP

#include <set>
#include "../Entidades_organizativas.hpp"
#include "../../Empleado/Gerente/Gerente_derivadas/Gerente_Alto.hpp"
#include "../../Empleado/Gerente/Gerente_derivadas/Gerente_Medio.hpp"
#include "../Empresa/Empresa.hpp"


class CentralRegional : public EntidadOrganizativa {
    private:
        int Cant_Empleados;
        vector<GerenteAlto> GerentesAltos;
        vector<GerenteMedio> GerentesMedios;
        set<string> Paises;
        set<Empresa> Empresas;

    public:
        CentralRegional(string nombre);
        int getcontarEmpleados() const;
        vector<GerenteAlto> getGerentesAltos() const;
        vector<GerenteMedio> getGerentesMedios() const;
        vector<string> getEmpNames() const;
        bool agregarGerenteAlto(GerenteAlto gerente);
        bool agregarGerenteMedio(GerenteMedio gerente);
        bool agregarPais(string pais);
        bool agregarEmpresa(Empresa empresa);
        bool eliminarEmpresa(string nombre);
        bool eliminarGerenteAlto(string nombre);
        bool eliminarGerenteMedio(string nombre);
        bool eliminarPais(string pais);
};


#endif