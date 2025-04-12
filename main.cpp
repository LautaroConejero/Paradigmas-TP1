#include "Ej_2/Consola_2.hpp"
#include "Ej_3/Creacion_terminal.hpp"
#include "Ej_4/combate.hpp"

int main(){
    cout << "Bienvenido a Trabajo Practico 1." << endl;
    cout << endl;
    while (true){
        cout << endl;
        cout << "Que desea hacer?" << endl;
        cout << "1. Probar la funcionalidad de los personajes" << endl;
        cout << "2. Probar la funcionalidad de la fabrica" << endl;
        cout << "3. Combate." << endl;
        cout << "4. Salir." << endl;
        cout << "Elija una opcion: " << endl;
        int opcion;
        cin >> opcion;
        while (opcion < 1 || opcion > 5) {
            cout << "Opcion invalida. Elija nuevamente: " << endl;
            cin >> opcion;
        }
        switch (opcion) {
            case 1:
                consola_2();
                break;
            case 2:
                Consola_equipos();
                break;
            case 3:
                consola_combate();
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                return 0;
        }
    }
}