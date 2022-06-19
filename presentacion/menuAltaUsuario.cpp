#include "header/menuAltaUsuario.hpp"
#include <iostream>
#include <string>

using namespace std;

DTEmpleado *menuAltaEmpleado(string email, string nombre, string password)
{
    string cargoIngresado;

    cout << "Ingrese el Cargo del Empleado (0 - Administración, 1 -Limpieza, 2 - Recepción, 3 - Infraestructura ):";
    Cargo cargo = (Cargo)leerIntIntervalo(0, 3);

    return new DTEmpleado(nombre, password, email, cargo);
}

DTHuesped *menuAltaHuesped(string email, string nombre, string password)
{
    bool esFinger;
    string seleccionEsFinger;

    bool seleccionCorrecta = false;
    while (!seleccionCorrecta)
    {
        cout << "El huesped asiste a la FIng? (S/N) :";
        seleccionEsFinger = leerString();

        if (seleccionEsFinger != "S" && seleccionEsFinger != "s" && seleccionEsFinger != "N" && seleccionEsFinger != "n")
        {
            cout << "Seleccione una de las opciones disponibles." << endl;
        }
        else
        {
            seleccionCorrecta = true;
        }
    }

    esFinger = (seleccionEsFinger == "S" || seleccionEsFinger == "s");

    return new DTHuesped(nombre, password, email, esFinger);
}

void menuAltaUsuario()
{
    string nombre;
    string email;
    string password;
    string tipoDeUsuario;

    system("clear");
    cout << "Ingrese un nombre:";
    nombre = leerString();

    cout << "Ingrese una direccion de email:";
    email = leerEmail();
    cout << "Ingrese una contraseña:";
    password = leerString();

    bool seleccionCorrecta = false;
    while (!seleccionCorrecta)
    {
        cout << "Ingrese el tipo de usuario a crear: Empleado [E] o Huesped [H]";
        tipoDeUsuario = leerString();

        if (tipoDeUsuario != "E" && tipoDeUsuario != "e" && tipoDeUsuario != "H" && tipoDeUsuario != "h")
        {
            cout << "Seleccione una de las opciones disponibles." << endl;
        }
        else
        {
            seleccionCorrecta = true;
        }
    }

    DTUsuario *dataUsuario;
    if (tipoDeUsuario == "h" || tipoDeUsuario == "H")
    {
        dataUsuario = menuAltaHuesped(email, nombre, password);
    }
    else
    {
        dataUsuario = menuAltaEmpleado(email, nombre, password);
    }

    IControladorUsuario *controlador = Fabrica().getControladorUsuario();
    controlador->ingresarUsuario(dataUsuario);

    while (!controlador->confirmarEmailDisponible())
    {
        cout << "El email seleccionado no se encuentra disponible. Ingrese un nuevo email, o [C] para cancelar:" << endl;
        email = leerEmail();

        if (email == "c" || email == "C")
        {
            controlador->cancelarAlta();
            delete dataUsuario;
            return;
        }
    }

    controlador->reingresarEmail(email);

    string confirmacion;

    seleccionCorrecta = false;
    while (!seleccionCorrecta)
    {
        cout << "Desea confirmar el alta? (S/N)" << endl;
        confirmacion = leerString();

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
        controlador->confirmarAlta();
        cout << "Usuario creado correctamente.";
    }
    else
    {
        controlador->cancelarAlta();
        cout << "Alta cancelada correctamente.";
    }

    cout << endl
         << "Presione enter para continuar." << endl
         << endl;
    cin.ignore();

    if (dataUsuario != nullptr)
    {
        delete dataUsuario;
        dataUsuario = nullptr;
    }
}
