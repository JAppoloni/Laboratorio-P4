#include "header/Sistema.hpp"
#include <iostream>

Sistema *Sistema::_sistema = nullptr;

Sistema::Sistema() {}

Sistema::~Sistema() {}

void Sistema::agregarHuesped(std::string nombre, std::string email, bool esFinger)
{
    Huesped *huesped = new Huesped(nombre, email, esFinger);

    if (ObtenerHuespedXEmail(email) != nullptr)
        throw "El Huesped ya exsite";

    huespedes.add(huesped);
}

DTHuesped **Sistema::obtenerHuespedes(int &cantidad)
{
    cantidad = huespedes.size();

    DTHuesped **result = new DTHuesped *[cantidad];

    int index = 0;
    while (index < cantidad)
    {
        result[index] = new DTHuesped(huespedes.values()[index]);
        index++;
    }

    return result;
}

Sistema *Sistema::GetInstance()
{
    if (_sistema == NULL)
    {
        _sistema = new Sistema();
    }
    return _sistema;
}

void Sistema::agregarHabitacion(int numero, float precio, int capacidad)
{
    Habitacion *habitacion = new Habitacion(numero, precio, capacidad);
    if (ObtenerHabitacionXID(numero) != nullptr)
        throw "La habitación ya exsite";

    habitaciones.add(habitacion);
}

DTHabitacion **Sistema::obtenerHabitaciones(int &cantHabitaciones)
{
    cantHabitaciones = habitaciones.size();

    DTHabitacion **result = new DTHabitacion *[cantHabitaciones];

    int index = 0;
    while (index < cantHabitaciones)
    {
        result[index] = new DTHabitacion(habitaciones.values()[index]->getNumero(), habitaciones.values()[index]->getPrecio(), habitaciones.values()[index]->getCapacidad());
        index++;
    }

    return result;
}

DTReserva **Sistema::obtenerReservas(DTFecha fecha, int &cantReservas)
{
    cantReservas = reservas.size();
    DTReserva **result = new DTReserva *[cantReservas];
    int index = 0;
    int elems_add = 0;
    while (index < cantReservas)
    {
        if (dtreservas.values()[index]->getCheckIn() >= fecha || fecha <= dtreservas.values()[index]->getCheckOut())
        {
            result[elems_add] = dtreservas.values()[elems_add];
            elems_add++;
        }
    }
    return result;
}

void Sistema::registrarReserva(std::string email, DTReserva *reserva)
{
    // Validar Reserva
    if (reserva->getCodigo() < 0)
        throw "Codigo Invalido";
    if (reserva->getCheckOut() < reserva->getCheckIn())
        throw "La fecha de Ingreso es mayor a la de salida";
    Habitacion *hab = ObtenerHabitacionXID(reserva->getHabitacion());
    if (hab == NULL)
        throw "La Habitación no existe";

    Huesped *pHuesped = ObtenerHuespedXEmail(email);
    if (pHuesped == NULL)
        throw "No Existe ningún Cliente con ese E-mail";

    if (dynamic_cast</*const*/ DTReservaGrupal *>(reserva)) // More Info at: https://stackoverflow.com/a/56977583
    {
        DTReservaGrupal *aux_reserva = dynamic_cast<DTReservaGrupal *>(reserva);

        Huesped **listaHuesped = new Huesped *[huespedes.size()];

        listaHuesped[0] = pHuesped;
        for (int i = 1; i < huespedes.size() && aux_reserva->getHuespedes() != NULL; i++)
        {
            listaHuesped[i] = ObtenerHuespedXDT(aux_reserva->getHuespedes()[i]);
        }

        ReservaGrupal *myReserva = new ReservaGrupal(aux_reserva->getCodigo(),
                                                     aux_reserva->getCheckIn(),
                                                     aux_reserva->getCheckOut(),
                                                     aux_reserva->getEstado(),
                                                     hab,
                                                     listaHuesped);
        reservas.add(myReserva);
    }
    else
    {
        DTReservaIndividual *aux_reserva = dynamic_cast<DTReservaIndividual *>(reserva);

        ReservaIndividual *myReserva = new ReservaIndividual(aux_reserva->getCodigo(),
                                                             aux_reserva->getCheckIn(),
                                                             aux_reserva->getCheckOut(),
                                                             aux_reserva->getEstado(),
                                                             aux_reserva->getCosto(),
                                                             hab,
                                                             pHuesped,
                                                             aux_reserva->getEstado());

        reservas.add(myReserva);
    }
    dtreservas.add(reserva);
}

Habitacion *Sistema::ObtenerHabitacionXID(int ID)
{
    Habitacion *rtn = NULL;
    for (int i = 0; i < habitaciones.size(); i++)
    {
        if (habitaciones.values()[i]->getNumero() == ID)
        {
            rtn = habitaciones.values()[i];
            break;
        }
    }
    return rtn;
}

Huesped *Sistema::ObtenerHuespedXDT(DTHuesped *pDTHuesped)
{
    Huesped *rtn = NULL;
    for (int i = 0; i < huespedes.size(); i++)
    {
        if (huespedes.values()[i]->getEmail() == pDTHuesped->getEmail() && huespedes.values()[i]->getNombre() == pDTHuesped->getNombre() && huespedes.values()[i]->getEsFinger() == pDTHuesped->getEsFinger())
        {
            rtn = huespedes.values()[i];
            break;
        }
    }
    return rtn;
}

Huesped *Sistema::ObtenerHuespedXEmail(std::string email)
{
    Huesped *rtn = NULL;
    for (int i = 0; i < huespedes.size(); i++)
    {
        if (huespedes.values()[i]->getEmail() == email)
        {
            rtn = huespedes.values()[i];
            break;
        }
    }
    return rtn;
}
