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

    IControladorUsuario * CU = Fabrica().getControladorUsuario();
    set<DTHuesped*> huespedes = CU->listarHuespedes();
    cout << endl << "Email de los huespedes registrados en el sistema: " << endl;
    for(auto it : huespedes)
    {
        cout << it->getEmail() << endl;
    }

    cout << endl << "Ingrese el email del huesped correspondiente a la reserva:" << endl;
    string email = leerString();

    set<DTEstadia *> estadiasAbiertas = controladorEstadia->buscarEstadiasAbiertasPorCorreo(email);

    if (estadiasAbiertas.empty()) 
    {
        cout << "No hay estadias abiertas para el huesped seleccionado en el hostal seleccionado. Presione enter para continuar." << endl;
        cin.ignore();

        for (auto hostal : hostales)
        {
            delete hostal;
        }
        hostales.clear();

        return;
    }

    system("clear");

    cout << "Estadias disponibles para el husped seleccionado en el hostal:" << endl << endl;

    for (auto estadia : estadiasAbiertas)
    {
        cout << *estadia << endl << endl;
    }

    seleccionCorrecta = false;
    int codigoSeleccionado;
    while (!seleccionCorrecta)
    {
        cout << "Seleccione el codigo de la estadia a finalizar:" << endl;
        string codigoIngresado = leerString();
        DTEstadia* estadiaSeleccionada = buscarEstadiaPorCodigo(estadiasAbiertas, codigoIngresado);

        if (estadiaSeleccionada != nullptr)
        {
            codigoSeleccionado = estadiaSeleccionada->getID();
            seleccionCorrecta = true;
        }
        else
        {
            cout << "El codigo ingresado es invalido." << endl;
        }
    }

    controladorEstadia->seleccionarUnEstadiaAFinalizar(codigoSeleccionado);
    controladorEstadia->finalizarEstadia();

    for (auto hostal : hostales)
    {
        delete hostal;
    }
    hostales.clear();

    for (auto estadia : estadiasAbiertas)
    {
        delete estadia;
    }
    estadiasAbiertas.clear();

    cout << endl << "Estadia finalizada satisfactoriamente. Presione enter para continuar." << endl;
    cin.ignore();
}
