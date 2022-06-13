#include "header/DTReservaIndividual.hpp"

// Constructors
DTReservaIndividual::DTReservaIndividual(int codigo,
													  DTFecha checkIn,
													  DTFecha checkOut,
													  EstadoReserva estado,
													  float costo,
													  bool pago) : DTReserva(codigo, checkIn, checkOut, estado, costo)
{
	_pago = pago;
}
DTReservaIndividual::DTReservaIndividual(int codigo,
													  DTFecha checkIn,
													  DTFecha checkOut,
													  EstadoReserva estado,
													  float costo,
													  DTHabitacion *habitacion,
													  DTHuesped *huesped,
													  bool pago) : DTReserva(codigo, checkIn, checkOut, estado, costo, habitacion, huesped)
{
	_pago = pago;
}

// Destructor
DTReservaIndividual::~DTReservaIndividual()
{
	delete _habitacion;
	delete _huesped;
}

// Operators
std::ostream &DTReservaIndividual::operator<<(std::ostream &out)
{
	out << "IMPLEMENTAR" << std::endl;
	return out;
}

// Getters
bool DTReservaIndividual::getPago() const
{
	return _pago;
}
