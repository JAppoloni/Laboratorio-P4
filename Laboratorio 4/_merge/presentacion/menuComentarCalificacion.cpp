#include "header/menuComentarCalificacion.hpp"

void menuComentarCalificacion()
{
    IControladorUsuario *controlador = Fabrica().getControladorUsuario();
    set<DTEmpleado *> empleados = controlador->listarEmpleados();

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
        cout << "Ingrese el email del empleado que realiza el comentario ( " << RED << minElem << " - " << maxElem << NC << " ) :";
        int numEmpleado = leerIntIntervalo(minElem, maxElem);
        string email;
        for (auto it : empleados)
        {
            if (minElem == numEmpleado)
            {
                email = it->getEmail();
            }
            minElem++;
            delete it;
            it = nullptr;
        }
        empleados.clear();
        cout << "El empleado seleccionado es: " << email << endl;

        set<DTCalificacion *> calificaciones = controlador->obtenerComentariosSinResponderEmpleado(email);

        if (calificaciones.empty())
        {
            cout << "no hay comentarios sin responder para el empleado elegido" << endl;
        }
        else
        {
            cout << "Comentarios sin responder para el empleado ingresado:" << endl
                 << endl;
            minElem = 1;
            maxElem = 0;
            for (auto calificacion : calificaciones)
            {
                string idReserva = to_string(calificacion->getIDReserva());
                string puntaje = to_string(calificacion->getCalificacion());
                string comentario = calificacion->getComentario();
                string emailHuesped = calificacion->getIDHuesped();

                maxElem++;
                cout << GRN << maxElem << NC << ".  ID Reserva: " << idReserva << " - email del huesped: " << emailHuesped << " - puntaje: " << puntaje << " - comentario: " << comentario << endl;
            }

            cout << "Ingrese el ID del comentario que desea responder ( " << RED << minElem << " - " << maxElem << NC << " ) :";
            int numComentario = leerIntIntervalo(minElem, maxElem);

            int IDReserva = 0;
            string email = "";
            for (auto calificacion : calificaciones)
            {
                if (minElem == numComentario)
                {
                    IDReserva = calificacion->getIDReserva();
                    email = calificacion->getIDHuesped();
                }
                minElem++;
                delete calificacion;
                calificacion = nullptr;
            }
            calificaciones.clear();
            cout << "El comentario seleccionado es: " << IDReserva << " - email del huesped: " << email << endl;

            cout << "Ingrese un comentario en respuesta a la calificacion seleccionada:";
            string respuesta = leerString();

            controlador->responderCalificacion(IDReserva, email, respuesta);

            cout << endl
                 << "Respuesta ingresada correctamente." << endl;
        }
    }
    presioneParaContinuar();
}