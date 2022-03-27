#include "header/menuReserva.hpp"
#include "../common/datatype/header/DTFecha.hpp"

DTFecha ingresarFecha(int tipoMensaje)
{
    if (tipoMensaje == 1)
    {
        cout << "Ingrese la fecha de ingreso con la siguiente forma (dd/mm/yyyy): ";
    }
    else if (tipoMensaje == 0)
    {
        cout << "Ingrese la fecha de salida con la siguiente forma (dd/mm/yyyy): ";
    }
    else
    {
        cout << "Ingrese fecha para buscar reservas a partir de esta con la siguiente forma (dd/mm/yyyy): ";
    }
    DTFecha rtn = DTFecha(1, 1, 1900);
    string str_fecha;
    int dia, mes, anio;

    bool validInput = false;
    while (!validInput)
    {
        try
        {
            cin >> str_fecha;
            dia = stoi(str_fecha.substr(0, 2));
            mes = stoi(str_fecha.substr(3, 2));
            anio = stoi(str_fecha.substr(6));

            rtn = DTFecha(dia, mes, anio);
            validInput = true;
        }
        catch (const std::exception &e)
        {
            cout << "\n\n ----";
            cout << "Error en el formato de la fecha \t";
            std::cerr << e.what() << '\n';
            cout << "Intrese una fecha (dd/mm/yyyy): " << endl;
        }
    }
    return rtn;
}

void registrarReserva(Sistema *systemData)
{
    int codigo;
    int habitacion;
    string email;
    DTFecha checkIn = DTFecha(1, 1, 1900);
    DTFecha checkOut = DTFecha(1, 1, 1900);

    bool validInput = false;
    while (!validInput)
    {
        cout << "Ingrese el email de la nueva Reserva: ";
        cin >> email;
        Huesped *aux = systemData->obtenerHuespedPorEmail(email);
        if (aux == nullptr)
        {
            cout << endl
                 << "El huésped no existe" << endl;
        }
        else
        {
            validInput = true;
            break;
        }
    }

    validInput = false;
    while (!validInput)
    {
        cin.ignore();
        cout << "Ingrese el número de la habitación de la nueva Reserva: ";
        cin >> habitacion;
        Habitacion *aux = systemData->obtenerHabitacionPorID(habitacion);
        if (aux == nullptr)
        {
            cout << endl
                 << "La habitación no existe" << endl;
        }
        else
        {
            validInput = true;
            break;
        }
    }

    checkIn = ingresarFecha(true);
    checkOut = ingresarFecha(false);

    string TipoCliente;
    validInput = false;
    while (!validInput)
    {
        cout << "Ingrese el tipo de Reserva I (Indicidual)/G (Grupal): ";
        cin >> TipoCliente;

        validInput = TipoCliente == "I" || TipoCliente == "G";
        if (!validInput)
        {
            cout << endl
                 << "Ingrese 'I' o 'G'" << endl;
        }
    }

    if (TipoCliente == "I")
    {
        bool pago;

        validInput = false;
        string pagoReserva;
        while (!validInput)
        {
            cout << "El huesped pagó la reserva? S/N: ";
            cin >> pagoReserva;

            validInput = pagoReserva == "S" || pagoReserva == "N";
            pago = pagoReserva == "S";

            if (!validInput)
            {
                cout << endl
                     << "Ingrese 'S' o 'N'" << endl;
            }
        }
        try
        {
            DTReservaIndividual *reserva = new DTReservaIndividual(codigo, checkIn, checkOut, Abierta, 0, habitacion, pago);
            systemData->registrarReserva(email, reserva);

            delete reserva;
        }
        catch (const std::exception &e)
        {
            cout << "\n\n ----";
            cout << "Error al ingresar la Reserva Individual. \t";
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        DTHuesped **listaHuespedes = new DTHuesped *[MAX_HUESPEDES + 1];

        int contador_DT = 0;
        string email_Huesped;
        validInput = false;
        while (!validInput && contador_DT < MAX_HUESPEDES)
        {
            cout << "Ingrese el email del Huésped (Escriba FIN para terminar): ";
            cin >> email_Huesped;
            if (email_Huesped == "FIN")
            {
                validInput = true;
            }
            else
            {
                Huesped *aux = systemData->obtenerHuespedPorEmail(email_Huesped);

                if (aux == nullptr)
                {
                    cout << endl
                         << "El huésped no existe" << endl;
                }
                else
                {
                    listaHuespedes[contador_DT] = new DTHuesped(aux);
                    contador_DT++;
                }
            }
            listaHuespedes[contador_DT] = nullptr;
        }
        try
        {
            DTReservaGrupal *reserva = new DTReservaGrupal(codigo, checkIn, checkOut, Abierta, 0, habitacion, listaHuespedes);
            systemData->registrarReserva(email, reserva);

            for (int i = 0; i < MAX_HUESPEDES && listaHuespedes[i] != nullptr; i++)
            {
                delete listaHuespedes[i];
            };
            delete[] listaHuespedes;
            delete reserva;
        }
        catch (const std::exception &e)
        {
            cout << "\n\n ----";
            cout << "Error al ingresar la Reserva Individual. \t";
            std::cerr << e.what() << '\n';
        }
    }
    cout << std::endl;
    cin.ignore();
    cout << endl
         << endl
         << "Reserva agregada satisfactoriamente" << endl;
    cout << "Presione enter para continuar...";
    cin.ignore(1000, '\n');
}

void obtenerReservas(Sistema *systemData)
{
    int size;
    DTFecha fecha = ingresarFecha(2);
    DTReserva **Reservas = systemData->obtenerReservas(fecha, size);

    system("clear");

    string singular = " Reserva registrada.";
    string plural = " Reservas registradas.";

    cout << "--------Listado de Reservas--------" << endl
         << endl;
    cout << size << (size == 1 ? singular : plural) << endl
         << endl;

    for (int index = 0; index < size; index++)
    {
        if (dynamic_cast<DTReservaGrupal *>(Reservas[index]))
        {
            DTReservaGrupal *aux_reserva = dynamic_cast<DTReservaGrupal *>(Reservas[index]);
            DTReservaGrupal print = DTReservaGrupal(aux_reserva->getCodigo(),
                                                    aux_reserva->getCheckIn(),
                                                    aux_reserva->getCheckOut(),
                                                    aux_reserva->getEstado(),
                                                    aux_reserva->getCosto(),
                                                    aux_reserva->getHabitacion(),
                                                    aux_reserva->getHuespedes());
            print << cout;

            for (int i = 0; i < MAX_HUESPEDES && aux_reserva->getHuespedes()[i] != nullptr; i++)
            {
                delete aux_reserva->getHuespedes()[i];
            };
            delete[] aux_reserva->getHuespedes();
        }
        else
        {
            DTReservaIndividual *aux_reserva = dynamic_cast<DTReservaIndividual *>(Reservas[index]);
            DTReservaIndividual print = DTReservaIndividual(aux_reserva->getCodigo(),
                                                            aux_reserva->getCheckIn(),
                                                            aux_reserva->getCheckOut(),
                                                            aux_reserva->getEstado(),
                                                            aux_reserva->getCosto(),
                                                            aux_reserva->getHabitacion(),
                                                            aux_reserva->getPago());
            print << cout;
        }
    }
    cout << std::endl;
    cin.ignore();
    cout << "Presione enter para continuar...";
    cin.ignore(1000, '\n');

    for (int i = 0; i < size; i++)
    {
        delete Reservas[i];
    }
    delete[] Reservas;
}
