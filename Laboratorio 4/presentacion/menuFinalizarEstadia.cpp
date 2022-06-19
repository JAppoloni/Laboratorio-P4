#include "header/menuFinalizarEstadia.hpp"

DTEstadia* buscarEstadiaPorCodigo(set<DTEstadia*> estadias, string codigo)
{
    try
    {
        int codigoInt = stoi(codigo);
        for (auto estadia : estadias)
        {
            if (estadia->getID() == codigoInt)
            {
                return estadia;
            }
        }
    }
    catch (const std::exception& e)
    {
    }
    
    return nullptr;
}

void menuFinalizarEstadia()
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

    set<DTEstadia *> estadiasAbiertas = controladorEstadia->buscarEstadiasAbiertasPorCorreo(email);

    if (estadiasAbiertas.empty()) 
    {
        cout << "No hay estadias abiertas para el correo seleccionado. Presione enter para continuar." << endl;
        cin.ignore();

        for (auto hostal : hostales)
        {
            delete hostal;
        }
        hostales.clear();

        return;
    }

    system("clear");

    cout << "Estadias disponibles para el correo seleccionado:" << endl << endl;

    for (auto estadia : estadiasAbiertas)
    {
        cout << *estadia << endl << endl;
    }

    seleccionCorrecta = false;
    int codigoSeleccionado;
    while (!seleccionCorrecta)
    {
        cout << "Seleccione el codigo de la estadia a seleccionar:" << endl;
        string codigoIngresado = leerString();
        DTEstadia* reservaSeleccionada = buscarEstadiaPorCodigo(estadiasAbiertas, codigoIngresado);

        if (reservaSeleccionada != nullptr)
        {
            codigoSeleccionado = reservaSeleccionada->getID();
            seleccionCorrecta = true;
        }
        else
        {
            cout << "El codigo ingresado es invalido." << endl;
        }
    }

    controladorEstadia->seleccionarUnEstadiaAFinalizar(codigoSeleccionado);
    controladorEstadia->finalizarEstadia();

    cout << "Estadia finalizada satisfactoriamente. Presione enter para continuar." << endl;
    cin.ignore();
}
