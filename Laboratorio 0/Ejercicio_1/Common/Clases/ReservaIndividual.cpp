#include "header/ReservaIndividual.hpp"
#include "header/Habitacion.hpp"
#include "header/Reserva.hpp"
#include "../datatype/header/DTFecha.hpp"
#include <iostream>

void ReservaIndividual::imprimir()
{
    std::cout << " La reserva Individual " << this->getCodigo() << " es para el periodo ";
    this->getCheckIn().imprimir();
    std::cout << "-";
    this->getCheckOut().imprimir();
    std::cout << " y se reservó ";
    this->getHabitacionReservada().imprimir();
    std::cout << " Y su estado es " << this->estado << "a través del Huésped";
    this->listaHuesped[0].imprimir();
}

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, Habitacion habitacionReservada, Huesped pHuesped, bool pagado)
{
    this->setCodigo(codigo);
    this->setCheckIn(checkIn);
    this->setCheckOut(checkOut);
    this->setEstado(estado);
    this->setHabitacionReservada(habitacionReservada);
    this->listaHuesped = new Huesped[2];
    this->listaHuesped[0] = pHuesped;
    this->listaHuesped[1] = pHuesped.NULL_Huesped();
    this->pagado = pagado;
}

float ReservaIndividual::calcularCosto() { return this->habitacionReservada.getPrecio()*this->checkIn.calcularDias(this->checkOut); }

ReservaIndividual::~ReservaIndividual() {}
