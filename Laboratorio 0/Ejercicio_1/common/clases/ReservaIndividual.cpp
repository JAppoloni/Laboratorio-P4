#include "header/ReservaIndividual.hpp"
#include <iostream>

ReservaIndividual::ReservaIndividual(
    int codigo,
    DTFecha checkIn,
    DTFecha checkOut,
    EstadoReserva estado,
    Habitacion *habitacionReservada,
    Huesped *huesped,
    bool pago) : Reserva(codigo, checkIn, checkOut, estado, habitacionReservada)
{
    this->huesped = huesped;
    this->pago = pago;
    this->habitacionReservada = habitacionReservada;
}

float ReservaIndividual::calcularCosto()
{
    return this->habitacionReservada->getPrecio() * this->checkIn.calcularDias(this->checkOut);
}

Huesped *ReservaIndividual::getHuesped()
{
    return this->huesped;
}
void ReservaIndividual::setHuesped(Huesped *huesped)
{
    this->huesped = huesped;
}

bool ReservaIndividual::getPago()
{
    return this->pago;
}

void ReservaIndividual::setPago(bool pago)
{
    this->pago = pago;
}

ReservaIndividual::~ReservaIndividual() {}
