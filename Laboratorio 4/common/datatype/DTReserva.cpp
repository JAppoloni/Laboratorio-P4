#include "header/DTReserva.hpp"

// Constructors
DTReserva::DTReserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo)
{
	_codigo = codigo;
	_checkIn = checkIn;
	_checkOut = checkOut;
	_estado = estado;
	_costo = costo;
	_habitacion = nullptr;
	_huesped = nullptr;
}

DTReserva::DTReserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, DTHabitacion* habitacion, DTHuesped* huesped)
{
	_codigo = codigo;
	_checkIn = checkIn;
	_checkOut = checkOut;
	_estado = estado;
	_costo = costo;
	_habitacion = habitacion;
	_huesped = huesped;
}

// Destructor
DTReserva::~DTReserva()
{
	delete _habitacion;
	delete _huesped;
}

// Getters
int DTReserva::getCodigo() const
{
	return _codigo;
}
DTFecha DTReserva::getCheckIn() const
{
	return _checkIn;
}
DTFecha DTReserva::getCheckOut() const
{
	return _checkOut;
}
EstadoReserva DTReserva::getEstado() const
{
	return _estado;
}
float DTReserva::getCosto() const
{
	return _costo;
}
DTHabitacion* DTReserva::getHabitacion() const
{
	return _habitacion;
}
