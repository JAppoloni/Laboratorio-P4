#include "header/menuConsultaNotificaciones.hpp"
#include "header/menuEliminarSuscripcion.hpp"

void consultaNotificaciones()
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
        cout << endl << "Seleccione uno de los emails para listar sus notificaciones: ";
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

    set<DTCalificacion *> notif = CU->listarNotificacionesEmpleado(empleadoSeleccionado->getEmail());
    if(!notif.empty())
    {
        cout << "Lista de notificaciones: " << endl;
        for(auto it : notif)
        {
            cout << *it << endl;
        }
    } 
    else
    {
        cout << "El empleado no tiene notificaciones. " << endl;
    }
    for(auto it : notif)
    {
        delete it;
        it = nullptr;
    }
    notif.clear();

    cout << endl;
    cin.ignore();
    presioneParaContinuar();
}