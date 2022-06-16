#include "header/ReservaIndividual.hpp"

// Constructors
ReservaIndividual::ReservaIndividual()
{
	_estadiaReserva = nullptr;
}

ReservaIndividual::ReservaIndividual(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, bool pago)
{
	_codigo = codigo;
	_checkIn = CheckIn;
	_checkOut = checkOut;
	_huespedReserva = huespedReserva;
	_estado = estado;
	_habitacionReserva = habitacionReserva;
	_pago = pago;
	_estadiaReserva = nullptr;
}

// Destructor
ReservaIndividual::~ReservaIndividual()
{
	if (_huespedReserva != nullptr)
		_huespedReserva = nullptr;

	if (_habitacionReserva != nullptr)
		_habitacionReserva = nullptr;

	if (_estadiaReserva != nullptr)
	{
		delete _estadiaReserva;
		_estadiaReserva = nullptr;
	}
}

// Getters / Setters
bool ReservaIndividual::getPago() const
{
	return _pago;
}
void ReservaIndividual::setPago(bool pago)
{
	_pago = pago;
}

Estadia *ReservaIndividual::getEstadiaReserva() const
{
	return _estadiaReserva;
}

// Methods
void ReservaIndividual::agregarEstadia(Estadia *estadia)
{
	if (_estadiaReserva != nullptr)
		throw YAEXISTEESTADIA();
	_estadiaReserva = estadia;
}

bool ReservaIndividual::esReservaHostalHuesped(std::string email, std::string nombre)
{
	return _habitacionReserva->getHostal()->getNombre() == nombre && _huespedReserva->getEmail() == email;
}

DTReserva *ReservaIndividual::getDataReserva()
{

	return new DTReservaIndividual(_codigo,
											 _checkIn,
											 _checkOut,
											 _estado,
											 calcularCosto(),
											 new DTHabitacion(_habitacionReserva->getNumero(), _habitacionReserva->getPrecio(), _habitacionReserva->getCapacidad()),
											 _huespedReserva->getDatatypeptr(),
											 _pago);
}
