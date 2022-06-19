#include "header/Sistema.hpp"
#include <iostream>
Sistema::Sistema()
{
    cant_Habitaciones = 0;
    cant_Huespedes = 0;
    cant_Reservas = 0;
    proximoCodigoReserva = 1;
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

Sistema::~Sistema()
{
    // int i = 0;
    // while (i < cant_Huespedes){
    //     delete lstHuespedes[i];
    // };
    // delete lstHuespedes;

    // i = 0;
    // while (i < cant_Habitaciones){
    //     delete lstHabitaciones[i];
    // };
    // delete lstHabitaciones;

    // i = 0;
    // while (i < cant_Reservas){
    //     delete lstReservas;
    // };
    // delete lstReservas;
}

void Sistema::setProximoCodigoReserva(int nuevoCodigo) {
    if (nuevoCodigo < proximoCodigoReserva) {
        throw std::invalid_argument("El codigo debe ser mayor o igual al proximo codigo de reserva");
    }

    for (int index = 0; index < cant_Reservas; index++) {
        if (nuevoCodigo < lstReservas[index]->getCodigo()) {
            throw std::invalid_argument("Existe una reserva con el codigo menor al provisto");
        }
    }

    proximoCodigoReserva = nuevoCodigo;
}

void Sistema::agregarHuesped(std::string nombre, std::string email, bool esFinger)
{
    Huesped *huesped = new Huesped(nombre, email, esFinger);

    if (obtenerHuespedPorEmail(email) != nullptr)
    {
        throw std::invalid_argument("El Huesped ya exsite");
    }

    lstHuespedes[cant_Huespedes] = huesped;
    cant_Huespedes++;
}

DTHuesped **Sistema::obtenerHuespedes(int &cantidad)
{
    cantidad = cant_Huespedes;
    DTHuesped **result = new DTHuesped *[cantidad];

    int index = 0;
    while (index < cantidad)
    {
        result[index] = new DTHuesped(lstHuespedes[index]);
        index++;
    }

    return result;
}

void Sistema::agregarHabitacion(int numero, float precio, int capacidad)
{
    Habitacion *habitacion = new Habitacion(numero, precio, capacidad);
    if (obtenerHabitacionPorID(numero) != nullptr)
        throw std::invalid_argument("La habitación ya existe");

    lstHabitaciones[cant_Habitaciones] = habitacion;
    cant_Habitaciones++;
}

DTHabitacion **Sistema::obtenerHabitaciones(int &cantHabitaciones)
{
    cantHabitaciones = cant_Habitaciones;
    DTHabitacion **result = new DTHabitacion *[cantHabitaciones];

    int index = 0;
    while (index < cantHabitaciones)
    {
        result[index] = new DTHabitacion(lstHabitaciones[index]->getNumero(), lstHabitaciones[index]->getPrecio(), lstHabitaciones[index]->getCapacidad());
        index++;
    }

    return result;
}

DTReserva **Sistema::obtenerReservas(DTFecha fecha, int &cantReservas)
{
    DTReserva **result = new DTReserva *[cant_Reservas + 1];
    cantReservas = 0;

    for (int index = 0; (index < cant_Reservas) && lstReservas[index] != nullptr; index++)
    {
        if (lstReservas[index]->getCheckIn() >= fecha || fecha <= lstReservas[index]->getCheckOut())
        {
            // More Info at: https://stackoverflow.com/a/56977583
            if (dynamic_cast<ReservaGrupal *>(lstReservas[index]))
            {
                ReservaGrupal *aux_reserva = dynamic_cast<ReservaGrupal *>(lstReservas[index]);

                DTHuesped **listaHuesped = new DTHuesped *[MAX_HUESPEDES];
                int i = 0;
                while (i < MAX_HUESPEDES && aux_reserva->getListaHuesped()[i] != nullptr)
                {
                    listaHuesped[i] = new DTHuesped(aux_reserva->getListaHuesped()[i]->getNombre(),
                                                    aux_reserva->getListaHuesped()[i]->getEmail(),
                                                    aux_reserva->getListaHuesped()[i]->getEsFinger());
                    i++;
                };
                listaHuesped[i] = nullptr;

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
                ReservaIndividual *aux_reserva = dynamic_cast<ReservaIndividual *>(lstReservas[index]);

                DTReservaIndividual *myReserva = new DTReservaIndividual(
                    aux_reserva->getCodigo(),
                    aux_reserva->getCheckIn(),
                    aux_reserva->getCheckOut(),
                    aux_reserva->getEstado(),
                    aux_reserva->calcularCosto(),
                    aux_reserva->getHabitacionReservada()->getNumero(),
                    aux_reserva->getPago());

                result[cantReservas] = myReserva;
            };
            cantReservas++;
        };
    };
    result[cantReservas] = nullptr;

    return result;
}

void Sistema::registrarReserva(std::string email, DTReserva *reserva)
{
    // Validar Reserva && SI EXISTE

    if (reserva->getCheckOut() < reserva->getCheckIn())
    {
        throw std::invalid_argument("La fecha de ingreso es mayor a la de salida");
    }

    Habitacion *habitacion = obtenerHabitacionPorID(reserva->getHabitacion());

    if (habitacion == nullptr)
    {
        throw std::invalid_argument("La habitación no existe");
    }

    Huesped *pHuesped = obtenerHuespedPorEmail(email);
    if (pHuesped == nullptr)
    {
        throw std::invalid_argument("No existe ningún cliente con ese e-mail");
    }

    // More Info at: https://stackoverflow.com/a/56977583
    if (dynamic_cast<DTReservaGrupal *>(reserva))
    {
        DTReservaGrupal *aux_reserva = dynamic_cast<DTReservaGrupal *>(reserva);

        Huesped **listaHuesped = new Huesped *[MAX_HUESPEDES];

        listaHuesped[0] = pHuesped;
        int i = 0;
        while ((i < MAX_HUESPEDES) && (aux_reserva->getHuespedes()[i] != nullptr))
        {
            listaHuesped[i + 1] = obtenerHuespedPorEmail(aux_reserva->getHuespedes()[i]->getEmail());
            i++;
        };
        listaHuesped[i + 1] = nullptr;

        ReservaGrupal *myReserva = new ReservaGrupal(
            proximoCodigoReserva,
            aux_reserva->getCheckIn(),
            aux_reserva->getCheckOut(),
            aux_reserva->getEstado(),
            habitacion,
            listaHuesped);

        lstReservas[cant_Reservas] = myReserva;
    }
    else
    {
        DTReservaIndividual *aux_reserva = dynamic_cast<DTReservaIndividual *>(reserva);

        ReservaIndividual *myReserva = new ReservaIndividual(
            proximoCodigoReserva,
            aux_reserva->getCheckIn(),
            aux_reserva->getCheckOut(),
            aux_reserva->getEstado(),
            habitacion,
            pHuesped,
            aux_reserva->getPago());

        lstReservas[cant_Reservas] = myReserva;
    }
    cant_Reservas++;
    proximoCodigoReserva++;
}

Habitacion *Sistema::obtenerHabitacionPorID(int numero)
{
    Habitacion *rtn = nullptr;
    for (int i = 0; i < cant_Habitaciones; i++)
    {
        if (lstHabitaciones[i]->getNumero() == numero)
        {
            rtn = lstHabitaciones[i];
            break;
        }
    }
    return rtn;
}

Huesped *Sistema::obtenerHuespedPorEmail(std::string email)
{
    Huesped *rtn = nullptr;
    for (int i = 0; i < cant_Huespedes; i++)
    {
        if (lstHuespedes[i]->getEmail() == email)
        {
            rtn = lstHuespedes[i];
            break;
        }
    }
    return rtn;
}
