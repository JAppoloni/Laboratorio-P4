#include "header/ReservaGrupal.hpp"
#include "header/Habitacion.hpp"
#include "header/Reserva.hpp"
#include "../datatype/header/DTFecha.hpp"
#include <iostream>

void ReservaGrupal::imprimir() {
    std::cout << " La reserva Grupal " << this->getCodigo() << " es para el periodo ";
    this->getCheckIn().imprimir();
    std::cout << "-";
    this->getCheckOut().imprimir();
    std::cout << " y se reservó ";
    this->getHabitacionReservada().imprimir();
    std::cout << " Y su estado es " << this->getEstado().getEstado();
}

ReservaGrupal::ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, Habitacion habitacionReservada, Huesped* Huesped) {
    this->setCodigo(codigo);
    this->setCheckIn(checkIn);
    this->setCheckOut(checkOut);
    this->setEstado(estado);
    this->setHabitacionReservada(habitacionReservada);
    this->setlistaHuesped(Huesped);
}

float ReservaGrupal::calcularCosto() { return 0; }
ReservaGrupal::~ReservaGrupal(){}
