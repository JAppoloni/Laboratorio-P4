#include "header/DTEstadia.hpp"

// Constructors
DTEstadia::DTEstadia(int id, std::string email, DTFecha checkIn, DTFecha *checkOut, std::string promo)
{
	_IDReserva = id;
	_EmailHuesped = email;
	_checkIn = checkIn;
	if (checkOut != nullptr)
	{
		_checkOut = new DTFecha(checkOut);
	}
	else
	{
		_checkOut = nullptr;
	}
	_promo = promo;
}

DTEstadia::DTEstadia(const DTEstadia & est)
{
	_IDReserva = est._IDReserva;
	_EmailHuesped = est._EmailHuesped;
	_checkIn = est._checkIn;
	if (est._checkOut != nullptr)
	{
		_checkOut = new DTFecha(est._checkOut);
	}
	else
	{
		_checkOut = nullptr;
	}
	_promo = est._promo;
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