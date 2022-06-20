#include "header/menuTopTres.hpp"

using namespace std;

void menuTopTres()
{
    IControladorHostal *controlador = Fabrica().getControladorHostal();

    list<DTHostal *> topTres = controlador->calcularTopTres(); // Tira segmentation fault

    if (topTres.empty())
    {
        cout << "No hay hostales en el top tres de calificaciones. Presione enter para continuar.";
    }
    else
    {
        int minElem = 1;
        int maxElem = 0;

        cout << "Hostales: " << endl;
        for (auto it : topTres)
        {
            maxElem++;
            cout << GRN << maxElem << NC << ". " << it->getNombre() << " - " << it->getPromedioCalificaciones() << endl;
        }

        cout << "Ingrese el numero del hostal ( " << RED << minElem << " - " << maxElem << NC << " ) o C para cancelar :";

        string opcion = leerString();
        int elecion;
        if (opcion == "c" || opcion == "C")
        {
            elecion = -1;
        }
        else
        {
            try
            {
                elecion = stoi(opcion);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Ingrese un Número: " << '\n';
                elecion = leerIntIntervalo(minElem, maxElem);
            }
        }

        string nombreHostal = "";
        for (auto it : topTres)
        {
            if (minElem == elecion)
            {
                nombreHostal = it->getNombre();
            }
            minElem++;
            delete it;
            it = nullptr;
        }

        if (nombreHostal != "")
        {
            list<DTCalificacion *> calificaciones = controlador->consultarHostal(nombreHostal);
            for (list<DTCalificacion *>::iterator itr = calificaciones.begin(); itr != calificaciones.end(); itr++)
            {
                cout << **itr << endl;
                delete *itr;
            }
        }
    }
    controlador = nullptr;
    presioneParaContinuar();
}
