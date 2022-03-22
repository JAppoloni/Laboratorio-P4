#include "header/ReservaIndividual.hpp"
#include <iostream>

// void ReservaIndividual::imprimir()
// {
//     std::cout << " La reserva Individual " << this->getCodigo() << " es para el periodo ";
//     this->getCheckIn().imprimir();
//     std::cout << "-";
//     this->getCheckOut().imprimir();
//     std::cout << " y se reservó ";
//     this->getHabitacionReservada().imprimir();
//     std::cout << " Y su estado es " << this->estado << "a través del Huésped";
//     this->listaHuesped[0].imprimir();
// }

ReservaIndividual::ReservaIndividual(
    int codigo,
    DTFecha checkIn,
    DTFecha checkOut,
    EstadoReserva estado,
    float costo,
    Habitacion *habitacionReservada,
    Huesped *huesped,
    bool pagado) : Reserva(codigo, checkIn, checkOut, estado, habitacionReservada)
{
    this->huesped = huesped;
    this->pagado = pagado;
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

bool ReservaIndividual::getPagado()
{
    return this->pagado;
}

void ReservaIndividual::setPagado(bool pagado)
{
    this->pagado = pagado;
}

ReservaIndividual::~ReservaIndividual() {}
