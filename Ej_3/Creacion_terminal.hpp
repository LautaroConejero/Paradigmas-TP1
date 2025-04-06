#ifndef CREACION_TERMINAL_HPP
#define CREACION_TERMINAL_HPP

#include "Persona_Factory.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>
using namespace std;



void Creacion_equipos(int des, int tamaño, vector<shared_ptr<personaje>> &equipo, PersonajeFactory &factory);
void Consola_equipos();

#endif