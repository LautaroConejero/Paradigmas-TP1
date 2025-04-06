#ifndef COMBATE_HPP
#define COMBATE_HPP

#include "../Ej_2/personajes/personajes.hpp"
#include "../Ej_2/armas/armas.hpp"
#include "../Ej_3/Persona_Factory.hpp"
#include <memory>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

enum DECISION_JUEGO {
    GOLPE_FUERTE = 1,
    GOLPE_RAPIDO,
    DEFENSA_GOLPE
};

int Decision_juego();

int Ganador(DECISION_JUEGO decision_juego, DECISION_JUEGO decision_juego_maquina);

void Accion_juego(int decision, shared_ptr<personaje>& jugador, shared_ptr<personaje>& enemigo);

int consola_combate();

#endif