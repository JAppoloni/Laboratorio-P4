#include "header/menu.hpp"
#include "header/menuCargarDatos.hpp"
#include <iostream>
#include <string>

using namespace std;

string outputMenu()
{
    string input;

    system("clear");

    cout << "Bienvenido a FingVMB, elija una opcion" << endl
         << endl;

    cout << "0.  Cargar datos de prueba" << endl;
    cout << "1.  Alta de Usuario" << endl;
    cout << "2.  Alta de Hostal" << endl;
    cout << "3.  Alta de Habitacion" << endl;
    cout << "4.  Asignar empleado a hostal" << endl;
    cout << "5.  Realizar Reserva" << endl;
    cout << "6.  Consultar top 3 de hostales" << endl;
    cout << "7.  Registrar Estadia" << endl;
    cout << "8.  Finalizar Estadia" << endl;
    cout << "9.  Calificar Estadia" << endl;
    cout << "10. Comentar Calificacion" << endl;
    cout << "11. Consulta de Usuario" << endl;
    cout << "12. Consulta de Hostal" << endl;
    cout << "13. Consulta de Reserva" << endl;
    cout << "13. Consulta de Estadia" << endl;
    cout << "14. Baja de reserva" << endl;
    cout << "S.  Salir" << endl
         << endl;

    cin >> input;
    cin.ignore(1000, '\n');
    cout << endl;

    return input;
}

void notImplementedMessage()
{
    cout << "Opcion no implementada" << endl;
    cout << "Presione enter para continuar...";
    cin.ignore(1000, '\n');
}

void mainMenu()
{
    bool exit = false;
    bool primeraVez = true;

    while (!exit)
    {
        string option = outputMenu();
        int intOption;

        try
        {
            intOption = stoi(option);
        }
        catch (exception const &excep)
        {
            if (option == "S" || option == "s")
            {
                exit = true;
                break;
            }
            else
            {
                intOption = -1;
            }
        }

        switch (intOption)
        {
        case 0:
            cargarDatos(primeraVez);
            primeraVez = false;
            break;
        case 1:
            notImplementedMessage();
            break;
        case 2:
            notImplementedMessage();
            break;
        case 3:
            notImplementedMessage();
            break;
        case 4:
            notImplementedMessage();
            break;
        case 5:
            notImplementedMessage();
            break;
        case 6:
            notImplementedMessage();
            break;
        case 7:
            notImplementedMessage();
            break;
        case 8:
            notImplementedMessage();
            break;
        case 9:
            notImplementedMessage();
            break;
        case 10:
            notImplementedMessage();
            break;
        case 11:
            notImplementedMessage();
            break;
        case 12:
            notImplementedMessage();
            break;
        case 13:
            notImplementedMessage();
            break;
        case 14:
            notImplementedMessage();
            break;
        default:
            system("clear");
            cout << "Seleccione una de las opciones disponibles." << endl
                 << endl;
            cout << "Presione enter para continuar...";
            cin.ignore(1000, '\n');
            break;
        }
    }

    system("clear");
    cout << "Hasta luego!" << endl
         << endl;
}
