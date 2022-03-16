#include "../../include/ReservaIndividual.h"
#include "../../include/Habitacion.h"
#include "../../include/Reserva.h"
#include "../../include/DTFecha.h"
#include <iostream>


void ReservaIndividual::imprimir()
{
    std::cout << " La reserva Individual " << this->getCodigo() << " es para el periodo ";
    this->getCheckIn().imprimir();
    std::cout << "-";
    this->getCheckOut().imprimir();
    std::cout << " y se reservó ";
    this->getHabitacionReservada().imprimir();
    std::cout << " Y su estado es " << this->getEstado().getEstado();
}

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, Habitacion habitacionReservada, Huesped Huesped, bool pagado)
{
    this->setCodigo(codigo);
    this->setCheckIn(checkIn);
    this->setCheckOut(checkOut);
    this->setEstado(estado);
    this->setHabitacionReservada(habitacionReservada);
    this->listaHuesped[0] = Huesped;
   // this->listaHuesped[1] = NULL; Sugiero agregar un Huesped con codigo  de ID -1 para saber que ese es el valor null ya que todos los ID son mayores a 0;
    this->pagado = pagado;
}

float ReservaIndividual::calcularCosto() { return 0; }
ReservaIndividual::~ReservaIndividual() {}
