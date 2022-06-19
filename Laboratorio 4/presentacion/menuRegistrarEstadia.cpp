#include "header/menuRegistrarEstadia.hpp"

DTReserva* buscarReservaPorCodigo(set<DTReserva*> reservas, string codigo)
{
    try
    {
        int codigoInt = stoi(codigo);
        for (auto reserva : reservas)
        {
            if (reserva->getCodigo() == codigoInt)
            {
                return reserva;
            }
        }
    }
    catch (const std::exception& e)
    {
    }
    
    return nullptr;
}

void menuRegistrarEstadia()
{
    system("clear");

    IControladorHostal* controladorHostal = Fabrica().getControladorHostal();
    list<DTHostal*> hostales = controladorHostal->obtenerHostales();

    for (list<DTHostal*>::iterator iter = hostales.begin(); iter != hostales.end(); iter++) 
    {
        cout << (*iter)->getNombre() << endl;
    }

    if (hostales.empty()) 
    {
        cout << "No hay hostales disponibles. Presione enter para continuar." << endl;
        cin.ignore(1000, '\n');
        return;
    }

    string nombreHostal;
    bool seleccionCorrecta = false;
    DTHostal* hostalSeleccionado;

    while (!seleccionCorrecta) {
        cout << endl << "Ingrese el nombre del hostal a consultar:" << endl;
        nombreHostal = leerString();
        hostalSeleccionado = buscarHostal(hostales, nombreHostal);

        if (hostalSeleccionado != nullptr)
        {
            seleccionCorrecta = true;
        }
        else
        {
            cout << "No existe un hostal con el nombre seleccionado." << endl;
        }
    }

    IControladorEstadia* controladorEstadia = Fabrica().getControladorEstadia();
    controladorEstadia->seleccionarHostal(hostalSeleccionado->getNombre());

    cout << "Ingrese el email del huesped correspondiente a la reserva:" << endl;
    string email = leerString();

    set<DTReserva*> reservas = controladorEstadia->obtenerReservaHuesped(email);

    if (reservas.empty())
    {
        cout << "No hay reservas asignadas al usuario con el email seleccionado." << endl;
        cout << "Presione enter para continuar." << endl;
        cin.ignore();

        for (auto hostal : hostales)
        {
            delete hostal;
        }
        hostales.clear();
        return;
    }

    system("clear");

    cout << "Listado de reservas disponibles para el huesped seleccionado:" << endl;
    
    for (auto reserva : reservas)
    {
        cout << reserva->getCodigo() << " - entrada: " << reserva->getCheckIn() << endl;
    }

    seleccionCorrecta = false;
    int codigoSeleccionado;
    while (!seleccionCorrecta)
    {
        cout << "Seleccione el codigo de la reserva a seleccionar:" << endl;
        string codigoIngresado = leerString();
        DTReserva* reservaSeleccionada = buscarReservaPorCodigo(reservas, codigoIngresado);

        if (reservaSeleccionada != nullptr)
        {
            codigoSeleccionado = reservaSeleccionada->getCodigo();
            seleccionCorrecta = true;
        }
        else
        {
            cout << "El codigo ingresado es invalido." << endl;
        }
    }

    controladorEstadia->registrarEstadiaHuesped(codigoSeleccionado);

    cout << "Estadia registrada satisfactoriamente. Presione enter para continuar." << endl;
    cin.ignore();
}
