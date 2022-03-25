
#include "header/DTReservaIndividual.hpp"
#include <iostream>

DTReservaIndividual::DTReservaIndividual(int codigo, DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float costo, int habitacion, bool pagado) : DTReserva(codigo, CheckIn, CheckOut, estado, costo, habitacion)
{
   this->pagado = pagado;
}

bool DTReservaIndividual::getPagado()
{
   return this->pagado;
}

std::ostream &DTReservaIndividual::operator<<(std::ostream &o)
{

   o << "TipoReserva: Individual \n";
   o << "FechaCheckIn:" << this->getCheckIn().getDia() << "/" << this->getCheckIn().getMes() << "/" << this->getCheckIn().getAnio() << "\n";
   o << "FechaCheckIn:" << this->getCheckOut().getDia() << "/" << this->getCheckOut().getMes() << "/" << this->getCheckOut().getAnio() << "\n";
   o << "Habitacion:" << this->getHabitacion() << "\n";
   o << "Costo: $" << this->getCosto() << "\n";
   if (this->getPagado())
   {
      o << "Pagado:"
        << "Si"
        << "\n";
   }
   else
   {
      o << "Pagado:"
        << "No"
        << "\n";
   }
     o << "-----------------------" << std::endl;
   return o;
}
