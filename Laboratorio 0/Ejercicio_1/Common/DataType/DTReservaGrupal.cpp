
#include "header/DTReservaGrupal.hpp"
#include <iostream>


DTHuesped* DTReservaGrupal::gethuespedes(){
  DTHuesped (*h) [MAX_HUESPEDES]; 
  for(int i=0; i < MAX_HUESPEDES; i++){
    (*h)[i] = this->huespedes[i];
  } 
  return *h;

}

DTReservaGrupal::DTReservaGrupal (int codigo, DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float costo, int habitacion,int canthuespedes,  DTHuesped* huespedes ):DTReserva(codigo, CheckIn,CheckOut, estado, costo, habitacion){

  for (int i = 0; i < MAX_HABITACIONES ; i++)
    this->huespedes[i] = huespedes[i];
}

std::ostream& DTReservaGrupal::operator<<(std::ostream&o) {
    
  o << "TipoReserva: Grupal \n";
  o << "FechaCheckIn:" << this->getCheckIn().getDia() << "/" << this->getCheckIn().getMes() << "/" << this->getCheckIn().getAnio() << "\n" ;
  o << "FechaCheckIn:" << this->getCheckOut().getDia() << "/" << this->getCheckOut().getMes() << "/" << this->getCheckOut().getAnio() << "\n" ;
  o << "Habitacion:"<< this->getHabitacion() << "/n" ;
  o << "Costo: $" << this->getCosto() << "/n" ;
   
  int i = 0;
  while (!(this->gethuespedes()[i].esVacia()) && i < MAX_HUESPEDES) {
    o << this->gethuespedes()[i].getNombre() << "-" << this->gethuespedes()[i].getEmail() << "-" ;
    if (this->gethuespedes()[i].getEsFinger())
      o << "Es finger," << "/n" ;
    else o << ", /n";
  }

  return o;
}
