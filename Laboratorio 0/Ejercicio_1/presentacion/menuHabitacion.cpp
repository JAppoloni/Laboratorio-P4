#include "header/menuHabitacion.hpp"

void agregarHabitacion(Sistema *systemData)
{
    int numero;
    float precio;
    int capacidad;

    cout << "Ingrese el numero de la nueva habitacion: ";
    cin >> numero;
    cout << "Ingrese el precio de la nueva habitacion: ";
    cin >> precio;
    cout << "Ingrese la capacidad de la nueva habitacion: ";
    cin >> capacidad;

    cin.ignore();

    try
    {
        systemData->agregarHabitacion(numero, precio, capacidad);
    }
    catch (const std::exception &e)
    {
        cout << "\n Se produjo el siguiente error: \t";
        std::cerr << e.what() << '\n';
    }
    cout<< std::endl;
    cin.ignore();
    cout << endl
         << endl
         << "Habitacion agregada satisfactoriamente" << endl;
    cout << "Presione enter para continuar...";
    cin.ignore(1000, '\n');
}

void obtenerHabitaciones(Sistema *systemData)
{
    int size;
    DTHabitacion **habitaciones = systemData->obtenerHabitaciones(size);

    system("clear");

    string singular = " habitacion registrada.";
    string plural = " habitaciones registradas.";

    cout << "--------Listado de habitaciones--------" << endl
         << endl;
    cout << size << (size == 1 ? singular : plural) << endl
         << endl;

    for (int index = 0; index < size; index++)
    {
        cout << *habitaciones[index];
    }

    delete[] habitaciones;

    cout << "Presione enter para continuar...";
    cin.ignore(1000, '\n');
}
