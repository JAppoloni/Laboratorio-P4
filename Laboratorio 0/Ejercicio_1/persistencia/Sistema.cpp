#include "header/Sistema.hpp"
#include <iostream>

Sistema::Sistema() {}

Sistema::~Sistema() {}

void Sistema::agregarHuesped(std::string nombre, std::string email, bool esFinger)
{
    Huesped *huesped = new Huesped(nombre, email, esFinger);

    if (obtenerHuespedPorEmail(email) != nullptr)
    {
        throw "El Huesped ya exsite";
    }

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

void Sistema::agregarHabitacion(int numero, float precio, int capacidad)
{
    Habitacion *habitacion = new Habitacion(numero, precio, capacidad);
    if (obtenerHabitacionPorID(numero) != nullptr)
        throw "La habitación ya existe";

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
    DTReserva **result = new DTReserva *[reservas.size()];
    cantReservas = 0;

    for (int index = 0; (index < reservas.size()) && reservas.values()[index] != nullptr; index++)
    { //! -- VER PORQUE PUEDE CAMBIAR ###################### v
        if (reservas.values()[index]->getCheckIn() >= fecha || fecha <= reservas.values()[index]->getCheckOut())
        {
            // More Info at: https://stackoverflow.com/a/56977583
            if (dynamic_cast<ReservaGrupal *>(reservas.values()[index]))
            {
                ReservaGrupal *aux_reserva = dynamic_cast<ReservaGrupal *>(reservas.values()[index]);
                DTHuesped **listaHuesped = new DTHuesped *[huespedes.size()];

                for (int i = 0; i < huespedes.size() && aux_reserva->getListaHuesped()[i] != nullptr; i++)
                {
                    listaHuesped[cantReservas] = new DTHuesped(aux_reserva->getListaHuesped()[i]->getNombre(),
                                                               aux_reserva->getListaHuesped()[i]->getEmail(),
                                                               aux_reserva->getListaHuesped()[i]->getEsFinger());
                }

                DTReservaGrupal *myReserva = new DTReservaGrupal(
                    aux_reserva->getCodigo(),
                    aux_reserva->getCheckIn(),
                    aux_reserva->getCheckOut(),
                    aux_reserva->getEstado(),
                    aux_reserva->calcularCosto(),
                    aux_reserva->getHabitacionReservada()->getNumero(),
                    listaHuesped);

                result[cantReservas] = myReserva;
            }
            else
            {
                ReservaIndividual *aux_reserva = dynamic_cast<ReservaIndividual *>(reservas.values()[index]);

                DTReservaIndividual *myReserva = new DTReservaIndividual(
                    aux_reserva->getCodigo(),
                    aux_reserva->getCheckIn(),
                    aux_reserva->getCheckOut(),
                    aux_reserva->getEstado(),
                    aux_reserva->calcularCosto(),
                    aux_reserva->getHabitacionReservada()->getNumero(),
                    aux_reserva->getPagado());
                result[cantReservas] = myReserva;
            }
            cantReservas++;
        }
        index++;
    };
    for (int index = cantReservas; index < reservas.size(); index++)
       { result[index] = nullptr;}

    return result;
}

void Sistema::registrarReserva(std::string email, DTReserva *reserva)
{
    // Validar Reserva
    if (reserva->getCodigo() < 0)
    {
        throw "Codigo Invalido";
    }

    if (reserva->getCheckOut() < reserva->getCheckIn())
    {
        throw "La fecha de Ingreso es mayor a la de salida";
    }

    Habitacion *habitacion = obtenerHabitacionPorID(reserva->getHabitacion());

    if (habitacion == nullptr)
    {
        throw "La Habitación no existe";
    }

    Huesped *pHuesped = obtenerHuespedPorEmail(email);
    if (pHuesped == nullptr)
    {
        throw "No Existe ningún Cliente con ese E-mail";
    }

    // More Info at: https://stackoverflow.com/a/56977583
    if (dynamic_cast<DTReservaGrupal *>(reserva))
    {
        DTReservaGrupal *aux_reserva = dynamic_cast<DTReservaGrupal *>(reserva);

        Huesped **listaHuesped = new Huesped *[huespedes.size()];

        listaHuesped[0] = pHuesped;
        for (int i = 0; i < huespedes.size() && aux_reserva->getHuespedes()[i] != nullptr; i++)
        {
            listaHuesped[i + 1] = obtenerHuespedPorDT(aux_reserva->getHuespedes()[i]);
        }

        ReservaGrupal *myReserva = new ReservaGrupal(
            aux_reserva->getCodigo(),
            aux_reserva->getCheckIn(),
            aux_reserva->getCheckOut(),
            aux_reserva->getEstado(),
            habitacion,
            listaHuesped);
        reservas.add(myReserva);
    }
    else
    {
        DTReservaIndividual *aux_reserva = dynamic_cast<DTReservaIndividual *>(reserva);

        ReservaIndividual *myReserva = new ReservaIndividual(
            aux_reserva->getCodigo(),
            aux_reserva->getCheckIn(),
            aux_reserva->getCheckOut(),
            aux_reserva->getEstado(),
            aux_reserva->getCosto(),
            habitacion,
            pHuesped,
            aux_reserva->getEstado());

        reservas.add(myReserva);
    }
}

Habitacion *Sistema::obtenerHabitacionPorID(int numero)
{
    Habitacion *rtn = nullptr;
    for (int i = 0; i < habitaciones.size(); i++)
    {
        if (habitaciones.values()[i]->getNumero() == numero)
        {
            rtn = habitaciones.values()[i];
            break;
        }
    }
    return rtn;
}

Huesped *Sistema::obtenerHuespedPorDT(DTHuesped *pDTHuesped)
{
    Huesped *rtn = nullptr;
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

Huesped *Sistema::obtenerHuespedPorEmail(std::string email)
{
    Huesped *rtn = nullptr;
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
