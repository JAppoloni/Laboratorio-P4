#include "header/menuAltaHostal.hpp"

using namespace std;

void menuAltaHostal() 
{
    string nombre;
    string direccion;
    string telefono;

    cout << "Ingrese un nombre: ";
    nombre = leerString();
    cout << "Ingrese una direccion: ";
    direccion = leerString();
    cout << "Ingrese un telefono: ";
    telefono = leerString();

    DTHostal dataHostal = DTHostal(nombre, direccion, telefono);
    IControladorHostal* controlador = Fabrica().getControladorHostal();

    try
    {
        controlador->agregarHostal(dataHostal);
        cout << "Hostal agregado existosamente. ";
    }
    catch (exception const &excep)
    {
        cout << "Error: Ya existe un hostal con el nombre seleccionado. ";
    }

    cout << "Presione enter para continuar." << endl;
    cin.ignore();
    cin.ignore(1000, '\n');
}
