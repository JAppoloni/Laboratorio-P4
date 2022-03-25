

#include "header/DTReserva.hpp"
#include <iostream>

int DTReserva::getCodigo()
{
    return this->codigo;
}

int DTReserva::getHabitacion()
{
    return this->habitacion;
}

DTFecha DTReserva::getCheckIn()
{
    return this->checkIn;
}

DTFecha DTReserva::getCheckOut()
{
    return this->checkOut;
}

EstadoReserva DTReserva::getEstado()
{
    return this->estado;
}

float DTReserva::getCosto()
{
    return this->costo;
}

DTReserva::DTReserva(
    int codigo,
    DTFecha checkIn,
    DTFecha checkOut,
    EstadoReserva estado,float costo,
    int habitacion) : checkIn(checkIn), checkOut(checkOut), estado(estado)
{
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->habitacion = habitacion;
    this->costo=costo;
}

