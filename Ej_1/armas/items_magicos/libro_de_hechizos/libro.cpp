#include "libro.hpp"

libro_de_hechizos::libro_de_hechizos() :
    Item_magicos("Libro de hechizos", 70, 14, 15),
    probabilidad_ignorar_armadura(25) {}

string libro_de_hechizos::Get_calidad() const {
    return "Legendario";
}

pair<int, EFFECTO> libro_de_hechizos::lanzar_hechizo() {
    int daño = daño_magico;
    EFFECTO efecto = NINGUNO;
    // Crítico
    int crit = rand() % 100;
    if (crit < (chance_critico)) {
        std::cout << "Hechizo crítico lanzado" << std::endl;
        daño *= 2;
    }

    // Efecto aleatorio (20% chance)
    int proba_efecto = rand() % 100;
    if (proba_efecto < 20) {
        int e = rand() % 6;
        switch (e) {
            case 0: efecto = QUEMADURA; break;
            case 1: efecto = PARALIZAR; break;
            case 2: efecto = CONFUSION; break;
            case 3: efecto = HEMORRAGIA; break;
            case 4: efecto = MIEDO; break;
        }
    }
    return {daño, efecto};
}

pair<int, TIPO_DAÑO> libro_de_hechizos::Atacar() {
    if (durabilidad <= 0) {
        cout << "El libro de hechizos está desgastado." << endl;
        return {0, MAGICO};
    }

    durabilidad--;

    cout << "El libro de hechizos lanza dos conjuros consecutivos..." << endl;

    // Lanza el primer hechizo
    pair<int, EFFECTO> hechizo1 = lanzar_hechizo();
    int daño1 = hechizo1.first;
    EFFECTO efecto1 = hechizo1.second;

    // Lanza el segundo hechizo
    pair<int, EFFECTO> hechizo2 = lanzar_hechizo();
    int daño2 = hechizo2.first;
    EFFECTO efecto2 = hechizo2.second;

    efecto_arma = efecto1;
    efecto_secundario = efecto2;

    int proba_armadura = rand() % 100;
    if (proba_armadura < probabilidad_ignorar_armadura) {
        ignorar_armadura = true;
        cout << "El hechizo ignora la armadura del enemigo." << endl;
    } else {
        ignorar_armadura = false;
    }

    return {daño1 + daño2, MAGICO};
}
