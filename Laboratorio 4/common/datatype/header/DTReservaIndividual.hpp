#ifndef DTRESERVAINDIVIDUAL_HPP
#define DTRESERVAINDIVIDUAL_HPP

#include <iostream>
#include <string>
#include "DTReserva.hpp"

class DTReservaIndividual : public DTReserva
{
public:
	// Constructors
	DTReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, DTHabitacion habitacion, DTHuesped huesped, bool pago);

	// Destructor
	~DTReservaIndividual();

	// Operators
	virtual std::ostream &operator<<(std::ostream &o);

	// Getters
	bool getPago() const;

private:
	bool _pago;
};

#endif