#ifndef DTRESERVA_HPP
#define DTRESERVA_HPP

#include <iostream>
#include <string>
#include "DTFecha.hpp"
#include "DTHuesped.hpp"
#include "DTHabitacion.hpp"
#include "../../clases/header/EstadoReserva.hpp"

class DTReserva
{
public:
	// Constructors
	DTReserva();
	DTReserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo);
	DTReserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, DTHabitacion *habitacion, DTHuesped *huesped);

	// Destructor
	~DTReserva();

	// Operators
	virtual std::ostream &operator<<(std::ostream &o) = 0;

	// Getters
	int getCodigo() const;
	DTFecha getCheckIn() const;
	DTFecha getCheckOut() const;
	EstadoReserva getEstado() const;
	float getCosto() const;
	DTHabitacion *getHabitacion() const;

protected:
	int _codigo;
	DTFecha _checkIn;
	DTFecha _checkOut;
	EstadoReserva _estado;
	float _costo;
	DTHabitacion *_habitacion;
	DTHuesped *_huesped;
};

#endif