#include "header/menuComentarCalificacion.hpp"

DTCalificacion* buscarCalificacion(set<DTCalificacion*> cals, string idReserva, string email)
{
    try 
    {
        for (set<DTCalificacion *>::iterator itr = cals.begin(); itr != cals.end(); itr++) 
        {
            int intID = stoi(idReserva);
            if (intID == (*itr)->getIDReserva() && email == (*itr)->getIDHuesped())
            {
                return *itr;
            }
        }
    } 
    catch (const std::exception &e) 
    {
    }

    return nullptr;
}

void menuComentarCalificacion()
{
    string email;
    cout << "Ingrese el mail del empleado que realiza el comentario:" << endl;
    email = leerString();

    IControladorUsuario* controlador = Fabrica().getControladorUsuario();
    set<DTCalificacion*> calificaciones = controlador->obtenerComentariosSinResponderEmpleado(email);

    cout << "Comentarios sin responder para el usuario ingresado:" << endl;
    for (auto calificacion : calificaciones)
    {
        string idReserva = to_string(calificacion->getIDReserva());
        string puntaje = to_string(calificacion->getCalificacion());
        string comentario = calificacion->getComentario();
        string emailHuesped = calificacion->getIDHuesped();

        cout << idReserva << " - " << emailHuesped << " - " << puntaje << " - " << comentario << endl;
    }

    cout << endl;

    string idReservaIngresado;
    string emailIngresado;
    bool seleccionCorrecta = false;
    while (!seleccionCorrecta) 
    {
        cout << endl << "Ingrese el ID de la reserva de la estadia a calificar:" << endl;
        idReservaIngresado = leerString();
        cout << endl << "Ingrese el email del huesped de la estadia a calificar:" << endl;
        emailIngresado = leerString();

        DTCalificacion* calificacionIngresada = buscarCalificacion(calificaciones, idReservaIngresado, emailIngresado);
        if (calificacionIngresada != nullptr)
        {
            seleccionCorrecta = true;
        }
        else
        {
            cout << "No existe una calificacion con los datos ingresados." << endl;
        }
    }

    cout << "Ingrese un comentario en respuesta a la calificacion seleccionada:" << endl;
    string respuesta = leerString();

    Fabrica().getControladorUsuario()->responderCalificacion(stoi(idReservaIngresado), emailIngresado, respuesta);

    cout << "Respuesta ingresada correctamente. Presione enter para continuar." << endl;
    cin.ignore();
}
