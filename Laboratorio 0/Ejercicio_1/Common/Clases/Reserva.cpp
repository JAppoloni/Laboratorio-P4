#include "header/Reserva.hpp"
#include <iostream>

Reserva::Reserva(
    int codigo,
    DTFecha checkIn,
    DTFecha checkOut,
    EstadoReserva estado,
    Habitacion *habitacionReservada
): checkIn(checkIn), checkOut(checkOut), habitacionReservada(habitacionReservada) {
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->habitacionReservada = habitacionReservada;
}

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

Habitacion* Reserva::getHabitacionReservada() { 
    return this->habitacionReservada; 
}

void Reserva::setHabitacionReservada(Habitacion *habitacionReservada) { 
    this->habitacionReservada = habitacionReservada; 
}

// void Reserva::imprimir()
// {
//     std::cout << " La reserva " << this->codigo << " es para el periodo ";
//     this->checkIn.imprimir();
//     std::cout << "-";
//     this->checkOut.imprimir();
//     std::cout << " y se reservó ";
//     this->habitacionReservada.imprimir();
//     std::cout << " Y su estado es " << this->estado;
//     std::cout << ". \n ";
//     Huesped Null = Huesped().NULL_Huesped();

//     for (int i = 0; i < MAX_HUESPEDES && this->listaHuesped[i] != Null; i++)
//     {
//        this->listaHuesped[i].imprimir();
//     }
// }
