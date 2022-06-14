#include "header/DTEstadia.hpp"

// Constructors
DTEstadia::DTEstadia(int id, std::string email, DTFecha checkIn, DTFecha *checkOut, std::string promo)
{
	_IDReserva = id;
	_EmailHuesped = email;
	_checkIn = checkIn;
	_checkOut = checkOut;
	_promo = promo;
}

// Destructor
DTEstadia::~DTEstadia()
{
	delete _checkOut;
}

// Operators
std::ostream &operator<<(std::ostream &out, DTEstadia imprimir)
{
	out << "Reserva: " << imprimir.getID() << std::endl;
	out << "Huésped: " << imprimir.getEmail() << std::endl;
	out << "Check In: " << imprimir.getCheckIn() << std::endl;
	if (imprimir.getCheckOut() != nullptr)
		out << "Check Out: " << imprimir.getCheckOut() << std::endl;
	out << "Promo: " << imprimir.getPromo() << std::endl;
	return out;
	}

// Getters
DTFecha DTEstadia::getCheckIn() const
{
	return _checkIn;
}
DTFecha *DTEstadia::getCheckOut() const
{
	return _checkOut;
}
std::string DTEstadia::getPromo() const
{
	return _promo;
}
std::string DTEstadia::getEmail() const
{
	return _EmailHuesped;
}
int DTEstadia::getID() const
{
	return _IDReserva;
}