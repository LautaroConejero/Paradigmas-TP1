#include "Ej_3/Creacion_terminal.hpp"
#include "Ej_4/combate.hpp"

int main(){
    cout << "Bienvenido a Trabajo Practico 1." << endl;
    cout << endl;
    while (true){
        cout << "Que desea hacer?" << endl;
        cout << "2. Probar la funcionalidad de los personajes" << endl;
        cout << "3. Probar la funcionalidad de la fabrica" << endl;
        cout << "4. Combate." << endl;
        cout << "5. Salir." << endl;
        cout << "Elija una opcion: " << endl;
        int opcion;
        cin >> opcion;
        while (opcion < 1 || opcion > 5) {
            cout << "Opcion invalida. Elija nuevamente: " << endl;
            cin >> opcion;
        }
        switch (opcion) {
            case 2:
                break;
            case 3:
                Consola_equipos();
                break;
            case 4:
                consola_combate();
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                return 0;
        }
    }
}