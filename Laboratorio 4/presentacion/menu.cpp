#include "header/menu.hpp"

string outputMenu()
{
    string input;

    system("clear");

    cout << "Bienvenido a FingVMB, elija una opcion" << endl
         << endl;

    cout << "0.  Cargar Datos de Prueba" << endl;
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
    cout << "14. Consulta de Estadia" << endl;
    cout << "15. Baja de reserva" << endl;
    cout << "16. Suscribirse a Notificaciones" << endl;
    cout << "17. Consulta de notificaciones" << endl;
    cout << "18. Eliminar Subscripcion" << endl;
    cout << "19. Modificar Fecha del Sistema" << endl;
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
    bool datosCargados = false;

    while (!exit)
    {
        string option = outputMenu();

        if (option == "S" || option == "s")
        {
            exit = true;
            break;
        }

        int intOption;

        try
        {
            intOption = stoi(option);
        }
        catch (exception const &excep)
        {

            intOption = -1;
        }

        switch (intOption)
        {
        case 0:
            cargarDatos(!datosCargados);
            datosCargados = true;
            break;
        case 1:
            menuAltaUsuario();
            break;
        case 2:
            menuAltaHostal();
            break;
        case 3:
            menuAltaHabitacion();
            break;
        case 4:
            notImplementedMessage();
            break;
        case 5:
            notImplementedMessage();
            break;
        case 6:
            menuTopTres();
            break;
        case 7:
            menuRegistrarEstadia();
            break;
        case 8:
            menuFinalizarEstadia();
            break;
        case 9:
            menuCalificarEstadia();
            break;
        case 10:
            menuComentarCalificacion();
            break;
        case 11:
            menuConsultaUsuario();
            break;
        case 12:
            menuConsultaHostal();
            break;
        case 13:
            notImplementedMessage();
            break;
        case 14:
            notImplementedMessage();
            break;
        case 15:
            menuBajaReserva();
            break;
        case 16:
            notImplementedMessage();
            break;
        case 17:
            notImplementedMessage();
            break;
        case 18:
            notImplementedMessage();
            break;
        case 19:
            notImplementedMessage();
            break;
        case 20:
            menuImprimir();
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

    Fabrica fab = Fabrica();
    fab.liberarMemoria();

    system("clear");
    cout << "Hasta luego!" << endl
         << endl;
}
