#include "header/menuAltaHabitacion.hpp"
#include <iostream>
#include <string>

using namespace std;

void menuAltaHabitacion()
{
    IControladorHostal *controlador = Fabrica().getControladorHostal();
    list<DTHostal *> listaHostales = controlador->obtenerHostales();

    if (listaHostales.empty())
    {
        cout << "No hay hostales cargados" << endl;
    }
    else
    {
        int minElem = 1;
        int maxElem = 0;

        cout << "Hostales: " << endl;
        for (auto it : listaHostales)
        {
            maxElem++;
            cout << GRN << maxElem << NC << ". " << it->getNombre() << endl;
        }
        cout << "Ingrese el numero del hostal ( " << RED << minElem << " - " << maxElem << NC << " ) :";

        int numHostal = leerIntIntervalo(minElem, maxElem);
        string nombreHostal;

        for (auto it : listaHostales)
        {
            if (minElem == numHostal)
            {
                nombreHostal = it->getNombre();
            }
            minElem++;
            delete it;
            it = nullptr;
        }
        listaHostales.clear();
        cout << "El hostal seleccionado es: " << nombreHostal;
        controlador->buscarHostal(nombreHostal);

        cout << "Ingrese el numero de la nueva habitacion.";
        int numero = leerIntPositivo();
        cout << "Ingrese la capacidad de la nueva habitacion.";
        int capacidad = leerIntPositivo();
        cout << "Ingrese el costo de la nueva habitacion.";
        float costo = leerFloatPositivo();

        controlador->nuevaHabitacion(numero, capacidad, costo);

        string confirmacion;
        bool seleccionCorrecta = false;
        while (!seleccionCorrecta)
        {
            cout << "Desea confirmar el alta? (S/N)";
            confirmacion = leerString();

            if (confirmacion != "S" && confirmacion != "s" && confirmacion != "N" && confirmacion != "n")
            {
                cout << "Seleccione una de las opciones disponibles." << endl;
            }
            else
            {
                seleccionCorrecta = true;
            }
        }

        if (confirmacion == "S" || confirmacion == "s")
        {
            controlador->crearHabitacion();
            cout << "Habitacion creada correctamente.";
        }
        else
        {
            controlador->liberarMemoria();
            cout << "Alta cancelada correctamente.";
        }
    }
    controlador = nullptr;
    cin.ignore();
    cin.ignore(1000, '\n');
}