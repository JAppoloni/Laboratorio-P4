#include "header/menuAltaHabitacion.hpp"
#include <iostream>
#include <string>

using namespace std;

void menuAltaHabitacion() 
{
    IControladorHostal* controlador = Fabrica().getControladorHostal();
    list<DTHostal*> hostales = controlador->obtenerHostales();

    if (hostales.empty()) 
    {
        cout << "No hay hostales disponibles. Presione enter para continuar.";
        cin.ignore(1000, '\n');
        return;
    }

    for (list<DTHostal *>::iterator itr = hostales.begin(); itr != hostales.end(); itr++) 
    {
        cout << (*itr)->getNombre() << endl;
    }

    string nombreHostal;
    bool seleccionCorrecta = false;

    while (!seleccionCorrecta) {
        cout << endl << "Ingrese el nombre del hostal al que se agregara la nueva habitacion:" << endl;
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

    controlador->buscarHostal(nombreHostal);

    int numero;
    int capacidad;
    float costo;

    bool ingresoCorrecto = false;
    while (!ingresoCorrecto)
    {
        string numeroIngresado;
        string capacidadIngresado;
        string costoIngresado;

        cout << "Ingrese el numero de la nueva habitacion." << endl;
        cin >> numeroIngresado;
        cout << "Ingrese la capacidad de la nueva habitacion." << endl;
        cin >> capacidadIngresado;
        cout << "Ingrese el costo de la nueva habitacion." << endl;
        cin >> costoIngresado;

        try 
        {
            numero = stoi(numeroIngresado);
            capacidad = stoi(capacidadIngresado);
            costo = stof(costoIngresado);
            ingresoCorrecto = true;
        }
        catch (exception const &excep)
        {
            cout << "Los datos fueron ingresados en un formato no valido. Presione enter para continuar." << endl;
            cin.ignore();
            cin.ignore(1000, '\n');
        }
    }

    controlador->nuevaHabitacion(numero, capacidad, costo);

    string confirmacion;
    seleccionCorrecta = false;
    while (!seleccionCorrecta)
    {
        cout << "Desea confirmar el alta? (S/N)" << endl;
        cin >> confirmacion;

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
        
    } else {
        controlador->liberarMemoria();
        cout << "Alta cancelada correctamente.";
    }

    cin.ignore();
    cin.ignore(1000, '\n');
}
