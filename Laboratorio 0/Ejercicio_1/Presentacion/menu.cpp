#include "header/menu.hpp"
#include "header/menuHuesped.hpp"
#include "header/menuHabitacion.hpp"
#include <iostream>
#include <string>

using namespace std;

char outputMenu() {
    char input;

    system("clear");

    cout << "Bienvenido a FingVMB, elija una opcion" << endl << endl;

    cout << "1. Agregar Huesped" << endl;
    cout << "2. Agregar Habitacion" << endl;
    cout << "3. Obtener Huespedes" << endl;
    cout << "4. Obtener Habitaciones" << endl;
    cout << "5. Registrar Reserva" << endl;
    cout << "6. Obtener Reservas" << endl;
    cout << "7. Salir" << endl << endl;

    cin.get(input);
    cin.ignore(1000, '\n');
    cout << endl;

    return input;
}

void notImplementedMessage() {
    cout << "Opcion no implementada" << endl;
    cout << "Presione enter para continuar...";
    cin.ignore(1000, '\n');
}

void mainMenu(Sistema* systemData) {
    bool exit = false;

    while(!exit) {
        char option = outputMenu();

        switch (option) {
            case '1':
                agregarHuesped(systemData);
                break;
            case '2':
                agregarHabitacion(systemData);
                break;
            case '3':
                obtenerHuespedes(systemData);
                break;
            case '4':
                obtenerHabitaciones(systemData);
                break;
            case '5':
                notImplementedMessage();
                break;
            case '6':
                notImplementedMessage();
                break;
            case '7':
                system("clear");
                cout << "Hasta luego!" << endl << endl;
                exit = true;
                break;
            default:
                system("clear");
                cout << "Seleccione una de las opciones disponibles." << endl << endl;
                cout << "Presione enter para continuar...";
                cin.ignore(1000, '\n');
                break;
        }
    }
}
