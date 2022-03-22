

#include "header/DTReserva.hpp"
#include <iostream>

int DTReserva::getCodigo(){
    return this->codigo;
}

DTFecha DTReserva::getCheckIn(){
    return this->checkIn;
}

DTFecha DTReserva::getCheckOut(){
    return this->checkOut;
}

EstadoReserva DTReserva::getEstado(){
    return this->estado;
}

float DTReserva::getCosto(){
    return this->costo;
}

DTReserva::DTReserva(int codigo, DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float costo, int habitacion) {
  this->codigo = codigo; 
  this->checkIn = CheckIn;
  this->checkOut = CheckOut;
  this->estado = estado;
  this->habitacion = habitacion;
  this->costo = costo;
  
}







