#include "header/menuTopTres.hpp"

using namespace std;

bool buscarNombreEnTopTres(list<DTHostal*> hostales, string nombre)
{
    for (list<DTHostal *>::iterator itr = hostales.begin(); itr != hostales.end(); itr++) 
    {
        if ((*itr)->getNombre() == nombre)
        {
            return true;
        }
    }

    return false;
}

void menuTopTres()
{
    IControladorHostal* controlador = Fabrica().getControladorHostal();

    list<DTHostal*> topTres = controlador->calcularTopTres(); // Tira segmentation fault

    if (topTres.empty()) 
    {
        cout << "No hay hostales en el top tres de calificaciones. Presione enter para continuar.";
        cin.ignore(1000, '\n');
    }

    system("clear");

    for (list<DTHostal*>::iterator itr = topTres.begin(); itr != topTres.end(); itr++)
    {
        cout << (*itr)->getNombre() << " - " << (*itr)->getPromedioCalificaciones() << endl;
    }

    string nombreHostal;
    bool seleccionCorrecta = false;

    while (!seleccionCorrecta) 
    {
        cout << "Ingrese el nombre de uno de los hostales para obtener sus datos, o [C] para cancelar:" << endl;
        cin >> nombreHostal;

        if (nombreHostal == "c" || nombreHostal == "C")
        {
            return;
        }

        if (buscarNombreEnTopTres(topTres, nombreHostal))
        {
            list<DTCalificacion*> calificaciones = controlador->consultarHostal(nombreHostal);
            for (list<DTCalificacion*>::iterator itr = calificaciones.begin(); itr != calificaciones.end(); itr++)
            {
                cout << "calificacion" << endl;
                delete (*itr);
            }
        }
        else
        {
            cout << "No existe un hostal con el nombre seleccionado." << endl;
        }
    }

    for (list<DTHostal*>::iterator itr = topTres.begin(); itr != topTres.end(); itr++)
    {
        delete (*itr);
    }
}
