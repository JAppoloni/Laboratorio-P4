#include "header/DTEstadia.hpp"

// Constructors
DTEstadia::DTEstadia(int id, std::string email, DTFecha checkIn, DTFecha *checkOut, std::string promo)
{
	_IDReserva = id;
	_EmailHuesped = email;
	_checkIn = checkIn;
	if (checkOut != NULL)
	{
		_checkOut = new DTFecha(checkOut);
	}
	else
	{
		_checkOut = NULL;
	}
	_promo = promo;
}

// Destructor
DTEstadia::~DTEstadia()
{
	if (_checkOut != nullptr)
	{
		delete _checkOut;
		_checkOut = nullptr;
	}
}

// Operators
std::ostream &operator<<(std::ostream &out, DTEstadia imprimir)
{
	out << "Reserva: " << imprimir.getID() << std::endl;
	out << "Huésped: " << imprimir.getEmail() << std::endl;
	out << "Check In: " << imprimir.getCheckIn();
	if (imprimir.getCheckOut() != nullptr)
		out << "Check Out: " << *imprimir.getCheckOut();
	if (imprimir.getPromo() == "")
		out << "Promo: No tiene promo" << std::endl;
	else
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