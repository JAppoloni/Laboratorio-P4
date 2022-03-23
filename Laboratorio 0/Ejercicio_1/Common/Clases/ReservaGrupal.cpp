#include "header/ReservaGrupal.hpp"
#include <iostream>

ReservaGrupal::ReservaGrupal(
    int codigo, 
    DTFecha checkIn, 
    DTFecha checkOut, 
    EstadoReserva estado, 
    Habitacion* habitacionReservada, 
    Huesped** huesped
): Reserva(codigo, checkIn, checkOut, estado, habitacionReservada) {
    this->listaHuesped = huesped;
}

float ReservaGrupal::calcularCosto() {
    int cantFingers = 0;

    // Broken   --//Puede romper???
    for (int i = 0; (i < MAX_HUESPEDES) && (cantFingers < 2) && (this->listaHuesped[i]!=nullptr); i++) {
        if ((this->listaHuesped[i])->getEsFinger() == true) {
            cantFingers++;
        }
    }

    int rtn = this->habitacionReservada->getPrecio() * this->checkIn.calcularDias(this->checkOut);

    return (cantFingers == 2) ? rtn * 0.7 : rtn;
}

Huesped** ReservaGrupal::getListaHuesped() { 
    return this->listaHuesped; 
}

void ReservaGrupal::setListaHuesped(Huesped** listaHuesped) {
    delete[] this->listaHuesped;
    this->listaHuesped = listaHuesped;
}

ReservaGrupal::~ReservaGrupal() {}
