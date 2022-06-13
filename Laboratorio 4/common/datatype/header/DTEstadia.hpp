#ifndef DTESTADIA_HPP
#define DTESTADIA_HPP

#include <iostream>
#include "DTFecha.hpp"

class DTEstadia
{
public:
	// Constructors
	DTEstadia(int id, std::string email, DTFecha checkIn, DTFecha *checkOut, std::string promo);

	// Destructor
	~DTEstadia();

	// Getters
	DTFecha getCheckIn() const;
	DTFecha *getCheckOut() const;
	std::string getPromo() const;
	std::string getEmail() const;
	int getID() const;

private:
	DTFecha _checkIn;
	DTFecha *_checkOut;
	std::string _promo;
	int _IDReserva;
	std::string _EmailHuesped;
};

std::ostream &operator<<(std::ostream &out, DTEstadia imprimir);

#endif