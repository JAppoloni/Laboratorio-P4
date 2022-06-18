#include "header/menuEliminarSuscripcion.hpp"

DTEmpleado* consultarEmpladoExiste(set<DTEmpleado*> empleados, string email) 
{
    for (set<DTEmpleado*>::iterator itr = empleados.begin(); itr != empleados.end(); itr++) 
    {
        if ((*itr)->getEmail() == email)
        {
            return (*itr);
        }
    }

    return nullptr;
}

void eliminarSuscripcion()
{
    IControladorUsuario * CU = Fabrica().getControladorUsuario();
    set<DTEmpleado*> empleados = CU->listarEmpleados();

    system("clear");
    cout << "Listado de emails de empleados del sistema: " << endl << endl;

    for (auto itr : empleados) 
    {
        cout << itr->getEmail() << endl; 
    }

    DTEmpleado* empleadoSeleccionado;
    bool seleccionCorrecta = false;
    while (!seleccionCorrecta) 
    {
        string emailIngresado;
        cout << endl << "Seleccione uno de los emails para emliminar suscripcion: ";
        cin >> emailIngresado;

        empleadoSeleccionado = consultarEmpladoExiste(empleados, emailIngresado);
        if (empleadoSeleccionado != nullptr) 
        {
            seleccionCorrecta = true;
        }
        else
        {
            cout << "El email ingresado no corresponde a un empleado del sistema." << endl;
        }
    }

    CU->eliminarSuscripcion(empleadoSeleccionado->getEmail());

    cout << "Suscripcion eliminada con exito" << endl;
    cin.ignore();
    presioneParaContinuar();
}