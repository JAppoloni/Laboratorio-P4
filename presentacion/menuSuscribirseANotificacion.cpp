#include "header/menuSuscribirseANotificacion.hpp"
#include "header/menuEliminarSuscripcion.hpp"

void suscribirseANotificacion()
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
        cout << endl << "Seleccione uno de los emails para suscribirse a notificaciones: ";
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

    CU->suscribirseNotificacion(empleadoSeleccionado->getEmail());

    cout << "Suscripcion agregada con exito" << endl;
    cin.ignore();
    presioneParaContinuar();
}