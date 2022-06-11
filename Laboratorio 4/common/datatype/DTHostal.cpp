#include "header/DTHostal.hpp"

// Constructors
DTHostal::DTHostal(std::string nombre, std::string direccion, std::string telefono)
{
	_nombre = nombre;
	_direccion = direccion;
	_telefono = telefono;
	_listaHabitaciones = nullptr;
	_listaHabitaciones = nullptr;
}

DTHostal::DTHostal(std::string nombre, std::string direccion, std::string telefono, std::list<DTHabitacion> *listaHabitaciones, std::list<DTEstadia> *listaEstadias)
{
	_nombre = nombre;
	_direccion = direccion;
	_telefono = telefono;
	_listaHabitaciones = listaHabitaciones;
	_listaEstadia = listaEstadias;
}

// Destructor
DTHostal::~DTHostal()
{
}

// Operators
std::ostream &operator<<(std::ostream &out, DTHostal imprimir)
{
	return out << " Implementar /n";
}

// Getters
std::string DTHostal::getNombre() const
{
	return _nombre;
}
std::string DTHostal::getDireccion() const
{
	return _direccion;
}
std::string DTHostal::getTelefono() const
{
	return _telefono;
}
std::list<DTHabitacion> *DTHostal::getListaHabitaciones() const
{
	return _listaHabitaciones;
}
std::list<DTEstadia> *DTHostal::getListaEstadia() const
{
	return _listaEstadia;
}
