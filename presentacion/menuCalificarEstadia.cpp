#include "header/menuCalificarEstadia.hpp"

DTEstadia *buscarIdEnEstadias(set<DTEstadia *> estadias, string id)
{
    try
    {
        for (set<DTEstadia *>::iterator itr = estadias.begin(); itr != estadias.end(); itr++)
        {
            int intID = stoi(id);
            if (intID == (*itr)->getID())
            {
                return *itr;
            }
        }
    }
    catch (const std::exception &e)
    {
    }

    return nullptr;
}

void menuCalificarEstadia()
{
    system("clear");

    Fabrica fabrica = Fabrica();
    IControladorHostal *controladorHostal = fabrica.getControladorHostal();
    list<DTHostal *> hostales = controladorHostal->obtenerHostales();

    if (hostales.empty())
    {
        cout << "No hay hostales disponibles.";
    }
    else
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

        IControladorEstadia *controladorEstadia = fabrica.getControladorEstadia();
        controladorEstadia->seleccionarHostal(nombreHostal);

        cout << endl
             << "Emails de los huespedes en el sitema: " << endl;

        IControladorUsuario *CU = fabrica.getControladorUsuario();
        set<DTHuesped *> huespedes = CU->listarHuespedes();

        if (!huespedes.empty())
        {
            minElem = 1;
            maxElem = 0;

            for (auto it : huespedes)
            {
                maxElem++;
                cout << GRN << maxElem << NC << ". " << it->getEmail() << endl;
            }
            cout << "Ingrese el numero del huesped ( " << RED << minElem << " - " << maxElem << NC << " ) :";
            int numHuesped = leerIntIntervalo(minElem, maxElem);
            string email;
            for (auto it : huespedes)
            {
                if (minElem == numHuesped)
                {
                    email = it->getEmail();
                }
                minElem++;
                delete it;
                it = nullptr;
            }
            huespedes.clear();
            cout << "El huesped seleccionado es: " << email << endl;

            set<DTEstadia *> estadias = controladorEstadia->indicarEmail(email);

            if (estadias.empty())
            {
                cout << "El huesped no tiene estadias Abiertas en el hostal seleccionado" << endl;
            }
            else
            {
                minElem = 1;
                maxElem = 0;
                cout << "Estadias del huesped: " << endl;
                for (auto it : estadias)
                {
                    maxElem++;
                    cout << GRN << maxElem << NC << ".  ID Reserva: " << it->getID() << " - Correo:" << it->getEmail()
                    << " - Fecha Inicio: " << it->getCheckIn().getHora() << " " << it->getCheckIn().getDia() << "/" << it->getCheckIn().getMes() << "/" << it->getCheckIn().getAnio() << endl;
                }

                cout << "Ingrese el numero de la estadia ( " << RED << minElem << " - " << maxElem << NC << " ) :";
                int numEstadia = leerIntIntervalo(minElem, maxElem);
                int IDReserva;

                for (auto it : estadias)
                {
                    if (minElem == numEstadia)
                    {
                        IDReserva = it->getID();
                    }
                    minElem++;
                    delete it;
                    it = nullptr;
                }

                estadias.clear();

                controladorEstadia->seleccionarEstadia(IDReserva);

                cout << "Ingrese el puntaje de la calificacion: ";
                int puntaje = leerIntIntervalo(1, 5);
                cout << "Ingrese un comentario sobre la estadia: ";
                string comentario = leerString();

                controladorEstadia->ingresarCalificacion(puntaje, comentario);
                controladorEstadia->notificarNuevaCalificacion();

                controladorEstadia = nullptr;
                cout << endl;
                cout << "Calificacion ingresada satisfactoriamente" << endl;
            }
        }
        else
        {
            cout << "No hay huespedes en esta opción." << endl;
        }
    }
    controladorHostal = nullptr;
    presioneParaContinuar();
}
