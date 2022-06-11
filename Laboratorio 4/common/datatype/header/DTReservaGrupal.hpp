#ifndef DTRESERVAGRUPAL_HPP
#define DTRESERVAGRUPAL_HPP

#include <iostream>
#include <string>
#include <list>
#include "DTReserva.hpp"
#include "DTHuesped.hpp"

class DTReservaGrupal : public DTReserva
{
public:
	// Constructors
	DTReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, DTHabitacion habitacion, DTHuesped huesped, std::list<DTHuesped> listaHuesped);

	// Destructor
	~DTReservaGrupal();

	// Operators
	virtual std::ostream &operator<<(std::ostream &o);

	// Getters
	std::list<DTHuesped> getListaHuesped() const;

private:
	std::list<DTHuesped> _listaHuesped;
};

#endif