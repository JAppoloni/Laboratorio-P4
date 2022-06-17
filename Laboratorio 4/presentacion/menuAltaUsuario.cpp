#include "header/menuAltaUsuario.hpp"
#include <iostream>
#include <string>

using namespace std;

DTEmpleado* menuAltaEmpleado(string email, string nombre, string password)
{
    Cargo cargo;
    string cargoIngresado;
    bool seleccionCorrecta = false;
    while (!seleccionCorrecta)
    {
        cout << "Ingrese el tipo de cargo del empleado (administracion, limpieza, recepcion, infraestructura):" << endl;
        cin >> cargoIngresado;

        if (
            cargoIngresado != "administracion" 
            && cargoIngresado != "limpieza" 
            && cargoIngresado != "recepcion" 
            && cargoIngresado != "infraestructura")
        {
            cout << "Seleccione una de las opciones disponibles." << endl;
        }
        else 
        {
            seleccionCorrecta = true;
        }
    }

    if (cargoIngresado == "administracion")
    {
        cargo = administracion;
    }
    else if (cargoIngresado == "limpieza") 
    {
        cargo = limpieza;
    }
    else if (cargoIngresado == "recepcion") 
    {
        cargo = recepcion;
    }
    else
    {
        cargo = infraestructura;
    }

    return new DTEmpleado(nombre, password, email, cargo);
}

DTHuesped* menuAltaHuesped(string email, string nombre, string password)
{
    bool esFinger;
    string seleccionEsFinger;

    bool seleccionCorrecta = false;
    while (!seleccionCorrecta)
    {
        cout << "El huesped asiste a la FIng? (S/N)" << endl;
        cin >> seleccionEsFinger;

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
    cout << "Ingrese un nombre:" << endl;
    cin >> nombre;
    cout << "Ingrese una direccion de email:" << endl;
    cin >> email;
    cout << "Ingrese una contraseña:" << endl;
    cin >> password;
    
    bool seleccionCorrecta = false;
    while (!seleccionCorrecta)
    {
        cout << "Ingrese el tipo de usuario a crear: Empleado [E] o Huesped [H]" << endl;
        cin >> tipoDeUsuario;

        if (tipoDeUsuario != "E" && tipoDeUsuario != "e" && tipoDeUsuario != "H" && tipoDeUsuario != "h")
        {
            cout << "Seleccione una de las opciones disponibles." << endl;
        }
        else 
        {
            seleccionCorrecta = true;
        }
    }
    
    DTUsuario* dataUsuario;
    if (tipoDeUsuario == "h" || tipoDeUsuario == "H")
    {
        dataUsuario = menuAltaHuesped(email, nombre, password);
    }
    else
    {
        dataUsuario = menuAltaEmpleado(email, nombre, password);
    }

    IControladorUsuario* controlador = Fabrica().getControladorUsuario();
    controlador->ingresarUsuario(dataUsuario);

    while (!controlador->confirmarEmailDisponible()) 
    {
        cout << "El email seleccionado no se encuentra disponible. Ingrese un nuevo email, o [C] para cancelar:" << endl;
        cin >> email;

        if (email == "c" || email == "C")
        {
            controlador->cancelarAlta();
            return;
        }
    }

    controlador->reingresarEmail(email);

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
        controlador->confirmarAlta();
        cout << "Usuario creado correctamente.";
        
    } else {
        controlador->cancelarAlta();
        cout << "Alta cancelada correctamente.";
    }

    cout << endl << "Presione enter para continuar." << endl << endl;
    cin.ignore();
    cin.ignore(1000, '\n');
}
