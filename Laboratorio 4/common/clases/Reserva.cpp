#include "header/Reserva.hpp"

// Constructors
Reserva::Reserva() {}

// Destructor
Reserva::~Reserva()
{
	_huespedReserva = nullptr;
	_habitacionReserva = nullptr;
	delete _huespedReserva;
	delete _habitacionReserva;
}

// Operators
bool Reserva::operator==(const Reserva &assign)
{
	return (_codigo == assign._codigo);
}

// Getters / Setters
int Reserva::getCodigo() const
{
	return _codigo;
}
void Reserva::setCodigo(int codigo)
{
	_codigo = codigo;
}

DTFecha Reserva::getCheckIn() const
{
	return _checkIn;
}
void Reserva::setCheckIn(DTFecha CheckIn)
{
	_checkIn = CheckIn;
}

DTFecha Reserva::getCheckOut() const
{
	return _checkOut;
}
void Reserva::setCheckOut(DTFecha checkOut)
{
	_checkOut = checkOut;
}

Huesped *Reserva::getHuespedReserva() const
{
	return _huespedReserva;
}
void Reserva::setHuespedReserva(Huesped *huespedReserva)
{
	_huespedReserva = huespedReserva;
}

EstadoReserva Reserva::getEstado() const
{
	return _estado;
}
void Reserva::setEstado(EstadoReserva estado)
{
	_estado = estado;
}

Habitacion *Reserva::getHabitacionReserva() const
{
	return _habitacionReserva;
}

void Reserva::setHabitacionReserva(Habitacion *habitacionReserva)
{
	_habitacionReserva = habitacionReserva;
}

// Exceptions
const char *Reserva::NOEXISTEHUESPED::what() const throw()
{
	return "Ese Huésped no está relacionado con la reserva";
}

const char *Reserva::YAEXISTEESTADIA::what() const throw()
{
	return "Ya existe una estadía asignada a esa Reserva.";
}

// Methods
void Reserva::cancelarReserva()
{
	_estado = Cancelada;
}

