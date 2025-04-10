#include "Empresa.hpp"

Empresa::Empresa(string nombre, string ubicacion) : 
    EntidadOrganizativa(nombre), direccion(ubicacion) {
}

Departamento Empresa::getDepByName(string nombre) const {
    for (size_t i = 0; i < departamentos.size(); ++i) {
        if (departamentos[i].nombre == nombre) {
            return departamentos[i];
        }
    }
    throw runtime_error("Departamento no encontrado: " + nombre);
}

vector<string> Empresa::getDepNames() const {
    vector<string> depNames;
    for (size_t i = 0; i < departamentos.size(); ++i) {
        depNames.push_back(departamentos[i].nombre);
    }
    return depNames;
}

bool Empresa::agregarDepartamento(Departamento departamento) {
    if (getDepByName(departamento.nombre).nombre == departamento.nombre) {
        cout << "El departamento ya existe." << endl;
        return false;
    }
    departamentos.push_back(departamento);
    cout << "El departamento " << departamento.nombre << " ha sido agregado." << endl;
    return true;
}

bool Empresa::eliminarDepartamento(string nombre) {
    for (size_t i = 0; i < departamentos.size(); ++i) {
        if (departamentos[i].nombre == nombre) {
            departamentos.erase(departamentos.begin() + i);
            cout << "El departamento " << nombre << " ha sido eliminado." << endl;
            return true;
        }
    }
    cout << "El departamento no existe." << endl;
    return false;
}