#include "header/ReservaGrupal.hpp"

// Constructors
ReservaGrupal::ReservaGrupal() {}

ReservaGrupal::ReservaGrupal(const ReservaGrupal &copy)
{
	_codigo = copy.getCodigo();
	_checkIn = copy.getCheckIn();
	_checkOut = copy.getCheckOut();
	_huespedReserva = copy.getHuespedReserva();
	_estado = copy.getEstado();
	_listaEstadia = copy.getListaEstadia();
	_habitacionReserva = copy.getHabitacionReserva();
	_listaEstadia = copy.getListaEstadia();
	_listaHuesped = copy.getListaHuesped();
}

ReservaGrupal::ReservaGrupal(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, std::list<Huesped *> listaHuesped)
{
	_codigo = codigo;
	_checkIn = CheckIn;
	_checkOut = checkOut;
	_huespedReserva = huespedReserva;
	_estado = estado;
	_habitacionReserva = habitacionReserva;
	_listaHuesped = listaHuesped;
}

ReservaGrupal::ReservaGrupal(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, std::list<Estadia *> listaEstadia, std::list<Huesped *> listaHuesped)
{
	_codigo = codigo;
	_checkIn = CheckIn;
	_checkOut = checkOut;
	_huespedReserva = huespedReserva;
	_estado = estado;
	_habitacionReserva = habitacionReserva;
	_listaEstadia = listaEstadia;
	_listaHuesped = listaHuesped;
}


// Destructor
ReservaGrupal::~ReservaGrupal()
{
	_listaEstadia.clear();
	_listaHuesped.clear();
}

// Operators
ReservaGrupal &ReservaGrupal::operator=(const ReservaGrupal &assign)
{
	_codigo = assign.getCodigo();
	_checkIn = assign.getCheckIn();
	_checkOut = assign.getCheckOut();
	_huespedReserva = assign.getHuespedReserva();
	_estado = assign.getEstado();
	_listaEstadia = assign.getListaEstadia();
	_habitacionReserva = assign.getHabitacionReserva();
	_listaEstadia = assign.getListaEstadia();
	_listaHuesped = assign.getListaHuesped();
	return *this;
}

// Getters / Setters
std::list<Estadia *> ReservaGrupal::getListaEstadia() const
{
	return _listaEstadia;
}
void ReservaGrupal::setListaEstadia(std::list<Estadia *> listaEstadia)
{
	_listaEstadia = listaEstadia;
}

std::list<Huesped *> ReservaGrupal::getListaHuesped() const
{
	return _listaHuesped;
}
void ReservaGrupal::setListaHuesped(std::list<Huesped *> listaHuesped)
{
	_listaHuesped = listaHuesped;
}

// Methods
float ReservaGrupal::calcularCosto() // VER.
{
	// if (_listaEstadia == NULL)
	// 	return 0;
	// else
	// {
	// 	return 1;
	// }
}

void ReservaGrupal::agregarEstadia(Estadia estadia)
{ // iterar si existe y si esta en la lista
	// if (_listaEstadia != NULL)
		// throw YAEXISTEESTADIA();
	// _listaEstadia = estadia;
}

bool ReservaGrupal::esReservaHostalHuesped(std::string email, std::string nombre)
{ // iterar si esta en la lista
	return _huespedReserva->getNombre() == nombre && _huespedReserva->getEmail() == email;
}

void ReservaGrupal::darBaja()
{ // No es destructor???
  // HACER
}