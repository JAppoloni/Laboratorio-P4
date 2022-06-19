#include "header/menuConsultaHostal.hpp"

void menuConsultaHostal()
{
    system("clear");
    Fabrica fabrica = Fabrica();
    IControladorHostal *contoraladoraHostal = fabrica.getControladorHostal();
    list<DTHostal *> listaHostales = contoraladoraHostal->obtenerHostales();

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

        cout << "El hostal seleccionado es: " << nombreHostal << endl;

        DTHostal *hostal = contoraladoraHostal->obtenerTodaInformacionDeHostal(nombreHostal);

        cout << DTHostal(*hostal) << endl;

        delete hostal;
        hostal = nullptr;
    }
    presioneParaContinuar();
}
