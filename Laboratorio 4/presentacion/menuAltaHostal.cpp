#include "header/menuAltaHostal.hpp"
#include <iostream>
#include <string>

using namespace std;

void menuAltaHostal() 
{
    string nombre;
    string direccion;
    string telefono;

    cout << "Ingrese un nombre:" << endl;
    cin >> nombre;
    cout << "Ingrese una direccion:" << endl;
    cin >> direccion;
    cout << "Ingrese un telefono:" << endl;
    cin >> telefono;

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
