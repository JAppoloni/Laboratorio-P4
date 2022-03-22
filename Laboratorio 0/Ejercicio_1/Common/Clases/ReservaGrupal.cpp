#include "header/ReservaGrupal.hpp"
#include <iostream>

// void ReservaGrupal::imprimir()
// {
//     std::cout << " La reserva Grupal " << this->getCodigo() << " es para el periodo ";
//     this->getCheckIn().imprimir();
//     std::cout << "-";
//     this->getCheckOut().imprimir();
//     std::cout << " y se reservó ";
//     this->getHabitacionReservada().imprimir();
//     std::cout << " Y su estado es " << this->estado;
//     std::cout << ". \n ";
//     Huesped Null = Huesped().NULL_Huesped();

//     for (int i = 0; i < MAX_HUESPEDES && this->listaHuesped[i] != Null; i++)
//     {
//         this->listaHuesped[i].imprimir();
//     }
// }

ReservaGrupal::ReservaGrupal(
    int codigo, 
    DTFecha checkIn, 
    DTFecha checkOut, 
    EstadoReserva estado, 
    Habitacion habitacionReservada, 
    Huesped* huesped
): Reserva(codigo, checkIn, checkOut, estado, habitacionReservada) {
    this->listaHuesped = huesped;
}

float ReservaGrupal::calcularCosto() {
    int cantFingers = 0;

    // Broken
    for (int i = 0; (i < MAX_HUESPEDES) && (cantFingers < 2) && (true); i++) {
        if (this->listaHuesped[i].getEsFinger() == true) {
            cantFingers++;
        }
    }

    int rtn = this->habitacionReservada.getPrecio() * this->checkIn.calcularDias(this->checkOut);

    return (cantFingers == 2) ? rtn * 0.7 : rtn;
}

Huesped* ReservaGrupal::getListaHuesped() { 
    return this->listaHuesped; 
}

void ReservaGrupal::setListaHuesped(Huesped* listaHuesped) {
    delete[] this->listaHuesped;
    this->listaHuesped = listaHuesped;
}

ReservaGrupal::~ReservaGrupal() {}
