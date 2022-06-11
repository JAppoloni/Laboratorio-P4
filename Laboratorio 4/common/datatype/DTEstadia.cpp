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
}

// Operators
std::ostream &operator<<(std::ostream &out, DTEstadia imprimir)
{
	return out << " Implementar /n";
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