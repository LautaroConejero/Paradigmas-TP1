#ifndef ENTIDADES_ORGANIZATIVAS_HPP
#define ENTIDADES_ORGANIZATIVAS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class EntidadOrganizativa {
    protected:
    vector<unique_ptr<EntidadOrganizativa>> entidades;

    public:
    string nombre;
    EntidadOrganizativa(string nom);
    int ContarSubentidades();
};


#endif