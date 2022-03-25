#include "header/DTReservaGrupal.hpp"
#include <iostream>

DTHuesped **DTReservaGrupal::getHuespedes()
{
    return *this->huespedes;
}

DTReservaGrupal::DTReservaGrupal(int codigo, DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float costo, int habitacion, DTHuesped **listaHuespedes) : DTReserva(codigo, CheckIn, CheckOut, estado, costo, habitacion)
{
    *this->huespedes = listaHuespedes;
}

std::ostream &DTReservaGrupal::operator<<(std::ostream &o)
{
    o << "TipoReserva: Grupal \n";
    o << "FechaCheckIn:" << this->getCheckIn().getDia() << "/" << this->getCheckIn().getMes() << "/" << this->getCheckIn().getAnio() << "\n";
    o << "FechaCheckIn:" << this->getCheckOut().getDia() << "/" << this->getCheckOut().getMes() << "/" << this->getCheckOut().getAnio() << "\n";
    o << "Habitacion:" << this->getHabitacion() << "\n";
    o << "Costo: $" << this->getCosto() << "\n";

    int i = 0;
    o << "Huéspedes: " << this->getHuespedes()[i]->getNombre() << " - " << this->getHuespedes()[i]->getEmail();

    if (this->getHuespedes()[i]->getEsFinger())
    {
        o << " - Es finger";
    }
    i++;

    while ((this->getHuespedes()[i] != nullptr) && !(this->getHuespedes()[i]->esVacia()) && i < MAX_HUESPEDES)
    {
        o << ", \n           " << this->getHuespedes()[i]->getNombre() << " - " << this->getHuespedes()[i]->getEmail();

        if (this->getHuespedes()[i]->getEsFinger())
        {
            o << " - Es finger";
        }
        i++;
    }
    o << "\n-----------------------" << std::endl;
    return o;
}
