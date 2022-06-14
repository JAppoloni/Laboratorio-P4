#include "header/DTHostal.hpp"

// Constructors
DTHostal::DTHostal(std::string nombre, std::string direccion, std::string telefono)
{
	_nombre = nombre;
	_direccion = direccion;
	_telefono = telefono;
	_listaHabitaciones = nullptr;
	_listaEstadia = nullptr;
	_promClaif = 0;
}

DTHostal::DTHostal(std::string nombre, std::string direccion, std::string telefono, int promClaif)
{
	_nombre = nombre;
	_direccion = direccion;
	_telefono = telefono;
	_promClaif = promClaif;
	_listaHabitaciones = nullptr;
	_listaEstadia = nullptr;
}

DTHostal::DTHostal(std::string nombre, std::string direccion, std::string telefono, int promClaif, std::list<DTHabitacion> *listaHabitaciones, std::list<DTEstadia> *listaEstadias)
{
	_nombre = nombre;
	_direccion = direccion;
	_telefono = telefono;
	_listaHabitaciones = listaHabitaciones;
	_listaEstadia = listaEstadias;
	_promClaif = promClaif;
}

// Destructor
DTHostal::~DTHostal()
{
	if (_listaHabitaciones != nullptr)
		_listaHabitaciones->clear();
	if (_listaEstadia != nullptr)
		 _listaEstadia->clear();
	
	delete _listaHabitaciones;
	delete _listaEstadia;
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
int DTHostal::getPromedioCalificaciones() const
{
	return _promClaif;
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