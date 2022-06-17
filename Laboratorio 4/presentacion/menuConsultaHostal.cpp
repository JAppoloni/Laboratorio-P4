#include "header/menuConsultaHostal.hpp"

void menuConsultaHostal()
{
    system("clear");

    IControladorHostal* controlador = Fabrica().getControladorHostal();
    list<DTHostal*> hostales = controlador->obtenerHostales();

    for (list<DTHostal*>::iterator iter = hostales.begin(); iter != hostales.end(); iter++) 
    {
        cout << (*iter)->getNombre() << endl;
    }

    if (hostales.empty()) 
    {
        cout << "No hay hostales disponibles. Presione enter para continuar.";
        cin.ignore(1000, '\n');
        return;
    }

    string nombreHostal;
    bool seleccionCorrecta = false;

    while (!seleccionCorrecta) {
        cout << endl << "Ingrese el nombre del hostal a consultar:" << endl;
        nombreHostal = leerString();

        if (buscarNombreDeHostal(hostales, nombreHostal))
        {
            seleccionCorrecta = true;
        }
        else
        {
            cout << "No existe un hostal con el nombre seleccionado." << endl;
        }
    }

    cout << "Falta operacion `obtenerTodaLaInformacionDeUnHostal`. Presione enter para continuar." << endl;
    cin.ignore();
    cin.ignore(1000, '\n');
}
