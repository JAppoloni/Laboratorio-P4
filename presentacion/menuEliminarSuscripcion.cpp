#include "header/menuEliminarSuscripcion.hpp"

DTEmpleado *consultarEmpladoExiste(set<DTEmpleado *> empleados, string email)
{
    for (set<DTEmpleado *>::iterator itr = empleados.begin(); itr != empleados.end(); itr++)
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
        CU->eliminarSuscripcion(empleadoSeleccionado);
        cout << "Suscripcion eliminada con exito" << endl;
    }
    presioneParaContinuar();
}