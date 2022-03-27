#include "header/DTReservaGrupal.hpp"
#include <iostream>

DTHuesped **DTReservaGrupal::getHuespedes()
{
    return *this->huespedes;
}

DTReservaGrupal::DTReservaGrupal(
    int codigo,
    DTFecha CheckIn,
    DTFecha CheckOut,
    EstadoReserva estado,
    float costo,
    int habitacion,
    DTHuesped **listaHuespedes) : DTReserva(codigo, CheckIn, CheckOut, estado, costo, habitacion)
{
    *this->huespedes = listaHuespedes;
}

std::ostream &DTReservaGrupal::operator<<(std::ostream &out)
{
    out << "Reserva Grupal" << std::endl;
    out << "Codigo: " << this->getCodigo() << std::endl;
    out << "Check in: " << this->getCheckIn() << std::endl;
    out << "Check out: " << this->getCheckOut() << std::endl;
    out << "Habitacion: " << this->getHabitacion() << std::endl;
    out << "Costo: $" << this->getCosto() << std::endl;

    int i = 0;
    out << "Huéspedes: " << std::endl;

    while ((this->getHuespedes()[i] != nullptr) && !(this->getHuespedes()[i]->esVacia()) && i < MAX_HUESPEDES)
    {
        DTHuesped *huesped = this->getHuespedes()[i];
        std::string esFinger = huesped->getEsFinger() ? " (FInger)" : "";
        out << "    " << huesped->getNombre() << " - " << huesped->getEmail() << esFinger << std::endl;
        i++;
    }
    out << "-----------------------" << std::endl;
    return out;
}
