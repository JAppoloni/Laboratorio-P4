#include "header/menuRegistrarEstadia.hpp"

void menuRegistrarEstadia()
{
    system("clear");

    IControladorHostal *controladorHostal = Fabrica().getControladorHostal();
    list<DTHostal *> hostales = controladorHostal->obtenerHostales();
    controladorHostal = nullptr;

    if (!hostales.empty())
    {
        int minElem = 1;
        int maxElem = 0;
        cout << "Hostales: " << endl;
        for (auto it : hostales)
        {
            maxElem++;
            cout << GRN << maxElem << NC << ". " << it->getNombre() << endl;
        }
        cout << "Ingrese el numero del hostal ( " << RED << minElem << " - " << maxElem << NC << " ) :";

        int numHostal = leerIntIntervalo(minElem, maxElem);
        string nombreHostal;

        for (auto it : hostales)
        {
            if (minElem == numHostal)
            {
                nombreHostal = it->getNombre();
            }
            minElem++;
            delete it;
            it = nullptr;
        }
        hostales.clear();

        cout << "El hostal seleccionado es: " << nombreHostal << endl;

        IControladorEstadia *controladorEstadia = Fabrica().getControladorEstadia();
        controladorEstadia->seleccionarHostal(nombreHostal);

        IControladorUsuario *CU = Fabrica().getControladorUsuario();
        set<DTHuesped *> huespedes = CU->listarHuespedes();
        CU = nullptr;

        if (!huespedes.empty())
        {
            cout << endl
                 << "Email de los huespedes registrados en el sistema: " << endl;

            maxElem = 0;
            minElem = 1;

            for (auto it : huespedes)
            {
                maxElem++;
                cout << GRN << maxElem << NC << ". " << it->getEmail() << endl;
            }
            cout << "Ingrese el numero del huespede ( " << RED << minElem << " - " << maxElem << NC << " ) :";
            int numHuespede = leerIntIntervalo(minElem, maxElem);
            string emailHuesped;
            for (auto it : huespedes)
            {
                if (minElem == numHuespede)
                {
                    emailHuesped = it->getEmail();
                }
                minElem++;
                delete it;
                it = nullptr;
            }
            huespedes.clear();

            set<DTReserva *> reservas = controladorEstadia->obtenerReservaHuesped(emailHuesped);

            if (!reservas.empty())
            {
                minElem = 1;
                maxElem = 0;
                cout << endl
                     << "Reservas: " << endl;
                for (auto it : reservas)
                {
                    maxElem++;
                    cout << GRN << maxElem << NC << ". Codigo: " << it->getCodigo() << " - Fecha Inicio: " << it->getCheckIn().getHora() << " " << it->getCheckIn().getDia() << "/" << it->getCheckIn().getMes() << "/" << it->getCheckIn().getAnio() << " - Fecha Fin: " << it->getCheckOut().getHora() << " " << it->getCheckOut().getDia() << "/" << it->getCheckOut().getMes() << "/" << it->getCheckOut().getAnio() << endl;
                }
                cout << "Ingrese el numero de la reserva ( " << RED << minElem << " - " << maxElem << NC << " ) :";
                int numReserva = leerIntIntervalo(minElem, maxElem);
                int codigoReserva = 0;
                for (auto it : reservas)
                {
                    if (minElem == numReserva)
                    {
                        codigoReserva = it->getCodigo();
                    }
                    minElem++;
                    delete it;
                    it = nullptr;
                }
                reservas.clear();

                controladorEstadia->registrarEstadiaHuesped(codigoReserva);
                cout << endl
                     << "Estadia registrada satisfactoriamente. Presione enter para continuar." << endl;
                
                controladorEstadia = nullptr;

            }
            else
            {
                cout << "No hay reservas asignadas al usuario con el email seleccionado." << endl;
            }
        }
        else
        {
            cout << "No hay huespedes registrados en el sistema." << endl;
        }
    }
    else
    {
        cout << "No hay hostales registrados en el sistema." << endl;
    }
    presioneParaContinuar() ;
}
