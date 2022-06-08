#include "header/DTReserva.hpp"

// Constructors
DTReserva::DTReserva()
{
}

DTReserva::DTReserva(const Reserva &copy)
{
	(void)copy;
}

DTReserva::DTReserva(const Reserva *&copy)
{
	(void)copy;
}

DTReserva::DTReserva(const DTReserva &copy)
{
	(void)copy;
}

// Destructor
DTReserva::~DTReserva()
{
}

// Operators
DTReserva &DTReserva::operator=(const DTReserva &assign)
{
	(void)assign;
	return *this;
}
