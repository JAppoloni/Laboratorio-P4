#include "header/menuHuesped.hpp"

void agregarHuesped(Sistema *systemData)
{
    string name;
    string email;
    string isFingerInput;
    bool isFinger;

    cout << "Ingrese el nombre del huesped: ";
    cin >> name;
    cout << "Ingrese el email del huesped: ";
    cin >> email;

    bool validInput = false;
    while (!validInput)
    {
        cout << "El huesped asiste a la FIng? S/N: ";
        cin >> isFingerInput;

        validInput = isFingerInput == "S" || isFingerInput == "N";
        isFinger = isFingerInput == "S";

        if (!validInput)
        {
            cout << endl
                 << "Ingrese 'S' o 'N'" << endl;
        }
    }

    try
    {
        systemData->agregarHuesped(name, email, isFinger);
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
         << "Huesped agregado satisfactoriamente" << endl;
    cout << "Presione enter para continuar...";
    cin.ignore(1000, '\n');
}

void obtenerHuespedes(Sistema *systemData)
{
    int size;
    DTHuesped **huespedes = systemData->obtenerHuespedes(size);

    system("clear");

    string singular = " huesped registrado.";
    string plural = " huespedes registrados.";

    cout << "--------Listado de huespedes--------" << endl
         << endl;
    cout << size << (size == 1 ? singular : plural) << endl
         << endl;

    for (int index = 0; index < size; index++)
    {
        cout << *huespedes[index];
    }

    for (int i = 0; i < size; i++)
    {
        delete huespedes[i];
    };
    delete[] huespedes;

    cout << "Presione enter para continuar...";
    cin.ignore(1000, '\n');
}
