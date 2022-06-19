#include "header/menuSuscribirseANotificacion.hpp"
#include "header/menuEliminarSuscripcion.hpp"

void suscribirseANotificacion()
{
    IControladorUsuario *CU = Fabrica().getControladorUsuario();
    set<DTEmpleado *> empleados = CU->listarEmpleados();

    system("clear");
    cout << "Listado de emails de empleados del sistema: " << endl
         << endl;

    if (empleados.empty())
    {
        cout << "No hay empleados cargados" << endl;
    }
    else
    {
        int minElem = 1;
        int maxElem = 0;

        for (auto it : empleados)
        {
            maxElem++;
            cout << GRN << maxElem << NC << ". " << it->getEmail() << endl;
        }
        cout << "Ingrese el numero del empleado ( " << RED << minElem << " - " << maxElem << NC << " ) :";
        int numEmpleado = leerIntIntervalo(minElem, maxElem);
        string empleadoSeleccionado;
        for (auto it : empleados)
        {
            if (minElem == numEmpleado)
            {
                empleadoSeleccionado = it->getEmail();
            }
            minElem++;
            delete it;
            it = nullptr;
        }
        empleados.clear();
        cout << "El empleado seleccionado es: " << empleadoSeleccionado << endl;
        CU->suscribirseNotificacion(empleadoSeleccionado);
        cout << "Suscripcion agregada con exito" << endl;
    }
    presioneParaContinuar();
}