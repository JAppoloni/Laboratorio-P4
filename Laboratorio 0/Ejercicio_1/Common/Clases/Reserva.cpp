#include "header/Habitacion.hpp"
#include "header/Reserva.hpp"
#include "../datatype/header/DTFecha.hpp"
#include <iostream>


int Reserva::getCodigo() { 
    return this->codigo; 
}

void Reserva::setCodigo(int codigo) { 
    this->codigo = codigo; 
}

DTFecha Reserva::getCheckIn() { 
    return this->checkIn; 
}

void Reserva::setCheckIn(DTFecha checkIn) { 
    this->checkIn = checkIn; 
}

DTFecha Reserva::getCheckOut() { 
    return this->checkOut; 
}

void Reserva::setCheckOut(DTFecha checkOut) { 
    this->checkOut = checkOut; 
}

EstadoReserva Reserva::getEstado() { 
    return this->estado; 
}

void Reserva::setEstado(EstadoReserva estado) { 
    this->estado = estado; 
}

Habitacion Reserva::getHabitacionReservada() { 
    return this->habitacionReservada; 
}

void Reserva::setHabitacionReservada(Habitacion habitacionReservada) { 
    this->habitacionReservada = habitacionReservada; 
    }

Huesped *Reserva::getlistaHuesped() { 
    return this->listaHuesped; 
}

void Reserva::setlistaHuesped(Huesped listaHuesped[]) {
    for (int i = 0; i < MAX_HUESPEDES; i++) {
        this->listaHuesped[i] = listaHuesped[i];
    }
}

void Reserva::setlistaHuesped(Huesped *listaHuesped)
{
    delete[] this->listaHuesped;
    this->listaHuesped = listaHuesped;
}

void Reserva::imprimir()
{
    std::cout << " La reserva " << this->codigo << " es para el periodo ";
    this->checkIn.imprimir();
    std::cout << "-";
    this->checkOut.imprimir();
    std::cout << " y se reservó ";
    this->habitacionReservada.imprimir();
    std::cout << " Y su estado es " << this->estado;
    std::cout << ". \n ";
    Huesped Null = Huesped().NULL_Huesped();

    for (int i = 0; i < MAX_HUESPEDES && this->listaHuesped[i] != Null; i++)
    {
       this->listaHuesped[i].imprimir();
    }
}
