#include "CentralRegional.hpp"

CentralRegional::CentralRegional(string nombre) : 
    EntidadOrganizativa(nombre), Cant_Empleados(0) {
}

int CentralRegional::getcontarEmpleados() const {
    return Cant_Empleados;
}

vector<GerenteAlto> CentralRegional::getGerentesAltos() const {
    return GerentesAltos;
}

vector<GerenteMedio> CentralRegional::getGerentesMedios() const {
    return GerentesMedios;
}

vector<string> CentralRegional::getEmpNames() const {
    vector<string> empNames;
    for (const auto& e : Empresas) {
        empNames.push_back(e.nombre);
    }
    return empNames;
}

bool CentralRegional::agregarGerenteAlto(GerenteAlto gerente) {
    if (GerentesAltos.size() == 5) {
        cout << "No se pueden agregar más gerentes altos." << endl;
        return false;
    }
    GerentesAltos.push_back(gerente);
    Cant_Empleados++;
    return true;
}

bool CentralRegional::agregarGerenteMedio(GerenteMedio gerente) {
    if (GerentesMedios.size() == 20) {
        cout << "No se pueden agregar más gerentes medios." << endl;
        return false;
    }
    GerentesMedios.push_back(gerente);
    Cant_Empleados++;
    return true;
}

bool CentralRegional::agregarEmpresa(Empresa empresa) {
    for (const auto& e : Empresas) {
        if (e.nombre == empresa.nombre) {
            cout << "La empresa ya existe." << endl;
            return false;
        }
    }
    Empresas.insert(empresa);
    return true;
}

bool CentralRegional::agregarPais(string pais) {
    for (const auto& p : Paises) {
        if (p == pais) {
            cout << "El país ya existe." << endl;
            return false;
        }
    }
    Paises.insert(pais);
    return true;
}

bool CentralRegional::eliminarEmpresa(string nombre) {
    for (auto it = Empresas.begin(); it != Empresas.end(); ++it) {
        if (it->nombre == nombre) {
            Empresas.erase(it);
            return true;
        }
    }
    cout << "La empresa no existe." << endl;
    return false;
}

bool CentralRegional::eliminarGerenteAlto(string nombre) {
    for (auto it = GerentesAltos.begin(); it != GerentesAltos.end(); ++it) {
        if (it->Get_nombre() == nombre) {
            GerentesAltos.erase(it);
            return true;
        }
    }
    cout << "El gerente alto no existe." << endl;
    return false;
}

bool CentralRegional::eliminarGerenteMedio(string nombre) {
    for (auto it = GerentesMedios.begin(); it != GerentesMedios.end(); ++it) {
        if (it->Get_nombre() == nombre) {
            GerentesMedios.erase(it);
            return true;
        }
    }
    cout << "El gerente medio no existe." << endl;
    return false;
}
