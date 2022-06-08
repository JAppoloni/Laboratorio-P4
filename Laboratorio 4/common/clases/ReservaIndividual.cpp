#include "header/ReservaIndividual.hpp"

// Constructors
ReservaIndividual::ReservaIndividual(){
	_estadiaReserva = NULL;
 }

ReservaIndividual::ReservaIndividual(const ReservaIndividual &copy)
{
	_codigo = copy.getCodigo();
	_checkIn = copy.getCheckIn();
	_checkOut = copy.getCheckOut();
	_huespedReserva = copy.getHuespedReserva();
	_estado = copy.getEstado();
	_estadiaReserva =copy.getEstadiaReserva();
	_habitacionReserva = copy.getHabitacionReserva();
	_pago = copy.getPago();
}


ReservaIndividual::ReservaIndividual(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped* huespedReserva, EstadoReserva estado, Habitacion* habitacionReserva, bool pago)
{
	_codigo = codigo;
	_checkIn = CheckIn;
	_checkOut = checkOut;
	_huespedReserva = huespedReserva;
	_estado = estado;		
	_habitacionReserva = habitacionReserva;
	_pago = pago;
	_estadiaReserva = NULL;
}

ReservaIndividual::ReservaIndividual(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, bool pago, Estadia *estadiaReserva)
{
	_codigo = codigo;
	_checkIn = CheckIn;
	_checkOut = checkOut;
	_estado = estado;		
	_habitacionReserva = habitacionReserva;
	_pago = pago;
	_estadiaReserva = estadiaReserva;
}


// Destructor
ReservaIndividual::~ReservaIndividual()
{
	delete _estadiaReserva;	
}

// Operators
ReservaIndividual & ReservaIndividual::operator=(const ReservaIndividual &assign)
{
	_codigo = assign.getCodigo();
	_checkIn = assign.getCheckIn();
	_checkOut = assign.getCheckOut();
	_huespedReserva = assign.getHuespedReserva();
	_estado = assign.getEstado();
	_estadiaReserva =assign.getEstadiaReserva();
	_habitacionReserva = assign.getHabitacionReserva();
	_pago = assign.getPago();
	return *this;
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

Estadia* ReservaIndividual::getEstadiaReserva() const
{
	return _estadiaReserva;
}


// Methods
float ReservaIndividual::calcularCosto()
{
	if (_estadiaReserva==NULL)
	return 0;
	else
	{
		return 1;
	}
}

void ReservaIndividual::agregarEstadia(Estadia estadia)
{
	// if(_estadiaReserva!=NULL)
	// 	YAEXISTEESTADIA;
	// _estadiaReserva=estadia;
}

bool ReservaIndividual::esReservaHostalHuesped(std::string email, std::string nombre)
{
	return _huespedReserva->getNombre() == nombre && _huespedReserva->getEmail()==email;
}

