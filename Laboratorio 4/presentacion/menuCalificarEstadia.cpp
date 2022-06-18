#include "header/menuCalificarEstadia.hpp"

DTEstadia* buscarIdEnEstadias(set<DTEstadia*> estadias, string id)
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
    IControladorHostal* controladorHostal = fabrica.getControladorHostal();
    list<DTHostal*> hostales = controladorHostal->obtenerHostales();

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

    while (!seleccionCorrecta) 
    {
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

    IControladorEstadia* controladorEstadia = fabrica.getControladorEstadia();
    controladorEstadia->seleccionarHostal(nombreHostal);
    
    string email;
    cout << "Ingrese el correo del usuario cuya estadia desea comentar." << endl;
    email = leerString();

    set<DTEstadia*> estadias = controladorEstadia->indicarEmail(email);

    if (estadias.empty()) 
    {
        cout << "No existen estadias para el correo seleccionado. Presione enter para continuar." << endl;
        cin.ignore();
        cin.ignore(1000, '\n');
        return;
    }
    
    cout << endl << "Ingrese el ID del hostal a consultar:" << endl;

    for (auto estadia : estadias)
    {
        cout << estadia->getID() << " - " << estadia->getCheckIn() << " al " << *(estadia->getCheckOut()) << endl;
    }

    string idSeleccionado;
    DTEstadia* estadiaSeleccionada;

    seleccionCorrecta = false;
    while (!seleccionCorrecta) 
    {
        cout << endl << "Ingrese el ID del hostal a consultar:" << endl;
        idSeleccionado = leerString();

        estadiaSeleccionada = buscarIdEnEstadias(estadias, idSeleccionado);
        if (estadiaSeleccionada != nullptr)
        {
            seleccionCorrecta = true;
        }
        else
        {
            cout << "No existe una estadia con el ID seleccionado." << endl;
        }
    }

    controladorEstadia->seleccionarEstadia(estadiaSeleccionada);

    int puntaje;
    string puntajeIngresado;
    string comentario;
    cout << "Ingrese el puntaje de la calificacion:" << endl;
    puntajeIngresado = leerString();
    cout << "Ingrese un comentario sobre la estadia:" << endl;
    comentario = leerString();

    try 
    {
        puntaje = stoi(puntajeIngresado);
    }
    catch (const std::exception &e)
    {
        cout << "El puntaje ingresado es invalido. Presione enter para continuar." << endl;
        cin.ignore();
        return;
    }

    controladorEstadia->ingresarCalificacion(puntaje, comentario);

    cout << "Calificacion ingresada satisfactoriamente" << endl;
    cin.ignore();
}
