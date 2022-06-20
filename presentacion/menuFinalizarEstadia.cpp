#include "header/menuFinalizarEstadia.hpp"

void menuFinalizarEstadia()
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
            cout << "Ingrese el numero del huespede correspondiente a la reserva ( " << RED << minElem << " - " << maxElem << NC << " ) :";
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

            set<DTEstadia *> estadias = controladorEstadia->buscarEstadiasAbiertasPorCorreo(emailHuesped);

            if (!estadias.empty())
            {
                minElem = 1;
                maxElem = 0;

                for (auto it : estadias)
                {
                    maxElem++;
                    cout << GRN << maxElem << NC << ".  ID Reserva: " << it->getID() << " - Correo:" << it->getEmail()
                         << " - Fecha Inicio: " << it->getCheckIn().getHora() << " " << it->getCheckIn().getDia() << "/" << it->getCheckIn().getMes() << "/" << it->getCheckIn().getAnio() << endl;
                }
                cout << "Ingrese el numero de la estadia ( " << RED << minElem << " - " << maxElem << NC << " ) :";
                int numEstadia = leerIntIntervalo(minElem, maxElem);

                int idReserva;

                for (auto it : estadias)
                {
                    if (minElem == numEstadia)
                    {
                        idReserva = it->getID();
                        cout << "La estadia seleccionada tiene el ID Reserva: " << it->getID() << " - Correo:" << it->getEmail()
                             << " - Fecha Inicio: " << it->getCheckIn().getHora() << " " << it->getCheckIn().getDia() << "/" << it->getCheckIn().getMes() << "/" << it->getCheckIn().getAnio() << endl;
                    }
                    delete it;
                    it = nullptr;
                    minElem++;
                }
                estadias.clear();

                controladorEstadia->seleccionarUnEstadiaAFinalizar(idReserva);
                controladorEstadia->finalizarEstadia();
                cout << "Estadia finalizada satisfactoriamente. Presione enter para continuar." << endl;
                controladorEstadia = nullptr;
            }
            else
            {
                cout << "No hay estadias abiertas para el huesped seleccionado en el hostal seleccionado. Presione enter para continuar. " << endl;
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
    cin.ignore();
}
