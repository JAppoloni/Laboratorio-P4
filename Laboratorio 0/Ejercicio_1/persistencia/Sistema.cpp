/**
 * NOTA: TODO lo relacionado a la collection fue comentado por problemas con la ispreción y demás metodos de Reserva ya que este no podia saber cuando el puntero de su lista de clietnes era NULL. Por eso el sistema se colgaba. (LST[MAX+1].getNombre <- No Definido y esta fuera del índice)
 *
 */
#include "header/Sistema.hpp"
#include <iostream>
Sistema::Sistema()
{

    lstHuespedes = new Huesped *[MAX_HUESPEDES];
    lstReservas = new Reserva *[MAX_RESERVAS];
    lstHabitaciones = new Habitacion *[MAX_HABITACIONES];
    for (int i = 0; i < MAX_RESERVAS; i++)
    {
        lstHuespedes[i] = nullptr;
        lstHabitaciones[i] = nullptr;
        lstReservas[i] = nullptr;
    }
}

Sistema::~Sistema() {}

void Sistema::agregarHuesped(std::string nombre, std::string email, bool esFinger)
{
    Huesped *huesped = new Huesped(nombre, email, esFinger);

    if (obtenerHuespedPorEmail(email) != nullptr)
    {
        throw "El Huesped ya exsite";
    }

    lstHuespedes[cant_Huespedes] = huesped;
    cant_Huespedes++;
    // huespedes.add(huesped);
}

DTHuesped **Sistema::obtenerHuespedes(int &cantidad)
{
    // cantidad = huespedes.size();
    cantidad = cant_Huespedes;
    DTHuesped **result = new DTHuesped *[MAX_HUESPEDES];

    int index = 0;
    while (index < cantidad)
    {
        // result[index] = new DTHuesped(huespedes.values()[index]);
        result[index] = new DTHuesped(lstHuespedes[index]);
        index++;
    }

    return result;
}

void Sistema::agregarHabitacion(int numero, float precio, int capacidad)
{
    Habitacion *habitacion = new Habitacion(numero, precio, capacidad);
    if (obtenerHabitacionPorID(numero) != nullptr)
        throw "La habitación ya existe";

    // habitaciones.add(habitacion);
    lstHabitaciones[cant_Habitaciones] = habitacion;
    cant_Habitaciones++;
}

DTHabitacion **Sistema::obtenerHabitaciones(int &cantHabitaciones)
{
    // cantHabitaciones = habitaciones.size();
    cantHabitaciones = cant_Habitaciones;

    DTHabitacion **result = new DTHabitacion *[cantHabitaciones];

    int index = 0;
    while (index < cantHabitaciones)
    {
        // result[index] = new DTHabitacion(habitaciones.values()[index]->getNumero(), habitaciones.values()[index]->getPrecio(), habitaciones.values()[index]->getCapacidad());
        result[index] = new DTHabitacion(lstHabitaciones[index]->getNumero(), lstHabitaciones[index]->getPrecio(), lstHabitaciones[index]->getCapacidad());
        index++;
    }

    return result;
}

DTReserva **Sistema::obtenerReservas(DTFecha fecha, int &cantReservas)
{
    // DTReserva **result = new DTReserva *[reservas.size()];
    DTReserva **result = new DTReserva *[MAX_RESERVAS];
    cantReservas = 0;

    // for (int index = 0; (index < reservas.size()) && reservas.values()[index] != nullptr; index++)
    for (int index = 0; (index < cant_Reservas) && lstReservas[index] != nullptr; index++)
    { //! -- VER PORQUE PUEDE CAMBIAR ###################### v
        // if (reservas.values()[index]->getCheckIn() >= fecha || fecha <= reservas.values()[index]->getCheckOut())
        if (lstReservas[index]->getCheckIn() >= fecha || fecha <= lstReservas[index]->getCheckOut())
        {
            // More Info at: https://stackoverflow.com/a/56977583
            // if (dynamic_cast<ReservaGrupal *>(reservas.values()[index]))
            if (dynamic_cast<ReservaGrupal *>(lstReservas[index]))

            {
                // ReservaGrupal *aux_reserva = dynamic_cast<ReservaGrupal *>(reservas.values()[index]);
                ReservaGrupal *aux_reserva = dynamic_cast<ReservaGrupal *>(lstReservas[index]);

                // DTHuesped **listaHuesped = new DTHuesped *[huespedes.size()];
                DTHuesped **listaHuesped = new DTHuesped *[MAX_HUESPEDES];

                // for (int i = 0; i < huespedes.size() && aux_reserva->getListaHuesped()[i] != nullptr; i++)
                for (int i = 0; i < cant_Huespedes && aux_reserva->getListaHuesped()[i] != nullptr; i++)
                {
                    listaHuesped[i] = new DTHuesped(aux_reserva->getListaHuesped()[i]->getNombre(),
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
                // ReservaIndividual *aux_reserva = dynamic_cast<ReservaIndividual *>(reservas.values()[index]);
                ReservaIndividual *aux_reserva = dynamic_cast<ReservaIndividual *>(lstReservas[index]);

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
    };

    return result;
}

void Sistema::registrarReserva(std::string email, DTReserva *reserva)
{
    // Validar Reserva && SI EXISTE
    if ((reserva->getCodigo() < 0) && (obtenerReservaPorID(reserva->getCodigo()) != nullptr))
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

        // Huesped **listaHuesped = new Huesped *[huespedes.size()];
        Huesped **listaHuesped = new Huesped *[MAX_HUESPEDES];

        listaHuesped[0] = pHuesped;
        for (int i = 0; i < cant_Huespedes && (i < MAX_HUESPEDES -1) && (aux_reserva->getHuespedes()[i] != nullptr); i++)
        {
            listaHuesped[i+1] = obtenerHuespedPorDT(aux_reserva->getHuespedes()[i]);
        }

        ReservaGrupal *myReserva = new ReservaGrupal(
            aux_reserva->getCodigo(),
            aux_reserva->getCheckIn(),
            aux_reserva->getCheckOut(),
            aux_reserva->getEstado(),
            habitacion,
            listaHuesped);
        // reservas.add(myReserva);
        lstReservas[cant_Reservas] = myReserva;
    }
    else
    {
        DTReservaIndividual *aux_reserva = dynamic_cast<DTReservaIndividual *>(reserva);

        ReservaIndividual *myReserva = new ReservaIndividual(
            aux_reserva->getCodigo(),
            aux_reserva->getCheckIn(),
            aux_reserva->getCheckOut(),
            aux_reserva->getEstado(),
            habitacion,
            pHuesped,
            aux_reserva->getPagado());

        // reservas.add(myReserva);
        lstReservas[cant_Reservas] = myReserva;
    }
    cant_Reservas++;
}

Habitacion *Sistema::obtenerHabitacionPorID(int numero)
{
    Habitacion *rtn = nullptr;
    // for (int i = 0; i < habitaciones.size(); i++)
    for (int i = 0; i < cant_Habitaciones; i++)
    {
        // if (habitaciones.values()[i]->getNumero() == numero)
        if (lstHabitaciones[i]->getNumero() == numero)
        {
            // rtn = habitaciones.values()[i];
            rtn = lstHabitaciones[i];
            break;
        }
    }
    return rtn;
}

Huesped *Sistema::obtenerHuespedPorDT(DTHuesped *pDTHuesped)
{
    Huesped *rtn = nullptr;
    // for (int i = 0; i < huespedes.size(); i++)
    for (int i = 0; i < cant_Huespedes; i++)
    {
        // if (huespedes.values()[i]->getEmail() == pDTHuesped->getEmail() && huespedes.values()[i]->getNombre() == pDTHuesped->getNombre() && huespedes.values()[i]->getEsFinger() == pDTHuesped->getEsFinger())
        if (lstHuespedes[i]->getEmail() == pDTHuesped->getEmail() && lstHuespedes[i]->getNombre() == pDTHuesped->getNombre() && lstHuespedes[i]->getEsFinger() == pDTHuesped->getEsFinger())

        {
            // rtn = huespedes.values()[i];
            rtn = lstHuespedes[i];
            break;
        }
    }
    return rtn;
}

Huesped *Sistema::obtenerHuespedPorEmail(std::string email)
{
    Huesped *rtn = nullptr;
    // for (int i = 0; i < huespedes.size(); i++)
    for (int i = 0; i < cant_Huespedes; i++)
    {
        // if (huespedes.values()[i]->getEmail() == email)
        if (lstHuespedes[i]->getEmail() == email)
        {
            // rtn = huespedes.values()[i];
            rtn = lstHuespedes[i];
            break;
        }
    }
    return rtn;
}

Reserva *Sistema::obtenerReservaPorID(int ID)
{
    Reserva *rtn = nullptr;
    // for (int i = 0; i < huespedes.size(); i++)
    for (int i = 0; i < cant_Reservas; i++)
    {
        // if (huespedes.values()[i]->getEmail() == email)
        if (lstReservas[i]->getCodigo() == ID)
        {
            // rtn = huespedes.values()[i];
            rtn = lstReservas[i];
            break;
        }
    }
    return rtn;
}
