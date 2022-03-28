
#include "header/DTReservaIndividual.hpp"
#include <iostream>

DTReservaIndividual::DTReservaIndividual(int codigo, DTFecha CheckIn, DTFecha CheckOut, EstadoReserva estado, float costo, int habitacion, bool pago) : DTReserva(codigo, CheckIn, CheckOut, estado, costo, habitacion)
{
    this->pago = pago;
}

bool DTReservaIndividual::getPago()
{
    return this->pago;
}

std::ostream &DTReservaIndividual::operator<<(std::ostream &out)
{
    out << "Reserva individual" << std::endl;
    out << "Codigo: " << this->getCodigo() << std::endl;
    out << "Check in: " << this->getCheckIn().getDia() << "/" << this->getCheckIn().getMes() << "/" << this->getCheckIn().getAnio() << std::endl;
    out << "Check out: " << this->getCheckOut().getDia() << "/" << this->getCheckOut().getMes() << "/" << this->getCheckOut().getAnio() << std::endl;
    out << "Habitacion: " << this->getHabitacion() << std::endl;
    out << "Costo: $" << this->getCosto() << std::endl;
    out << "Pago: " << (this->getPago() ? "Si" : "No") << std::endl;
    out << "-----------------------" << std::endl;

    return out;
}
