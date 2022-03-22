#include "header/DTReservaGrupal.hpp"
#include <iostream>

DTHuesped* DTReservaGrupal::getHuespedes() {
    DTHuesped (*h) [MAX_HUESPEDES]; 

    for(int i=0; i < MAX_HUESPEDES; i++){
        (*h)[i] = this->huespedes[i];
    } 

    return *h;
}

// DTReservaGrupal::DTReservaGrupal(
//     int codigo, 
//     DTFecha checkIn, 
//     DTFecha checkOut, 
//     EstadoReserva estado, 
//     float costo, 
//     int habitacion,
//     int cantHuespedes,  
//     DTHuesped* huespedes
// ): DTReserva(codigo, checkIn, checkOut, estado, costo, habitacion) {
//     // this->huespedes = new DTHuesped*[MAX_HUESPEDES];
//     for (int i = 0; i < MAX_HABITACIONES ; i++) {
//         this->huespedes[i] = huespedes[i];
//     }
// }

std::ostream& DTReservaGrupal::operator<<(std::ostream &o) {
    o << "TipoReserva: Grupal \n";
    o << "FechaCheckIn:" << this->getCheckIn().getDia() << "/" << this->getCheckIn().getMes() << "/" << this->getCheckIn().getAnio() << "\n" ;
    o << "FechaCheckIn:" << this->getCheckOut().getDia() << "/" << this->getCheckOut().getMes() << "/" << this->getCheckOut().getAnio() << "\n" ;
    o << "Habitacion:"<< this->getHabitacion() << "/n" ;
    o << "Costo: $" << this->getCosto() << "/n" ;
    
    int i = 0;
    while (!(this->getHuespedes()[i].esVacia()) && i < MAX_HUESPEDES) {
        o << this->getHuespedes()[i].getNombre() << "-" << this->getHuespedes()[i].getEmail() << "-" ;

        if (this->getHuespedes()[i].getEsFinger()) {
            o << "Es finger," << "/n" ;
        } else {
            o << ", /n";
        }

        i++;
    }

    return o;
}
