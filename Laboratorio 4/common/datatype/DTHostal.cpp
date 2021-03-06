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

DTHostal ::DTHostal(const DTHostal &other)
{
	_nombre = other._nombre;
	_direccion = other._direccion;
	_telefono = other._telefono;
	_listaHabitaciones = other._listaHabitaciones;
	_listaEstadia = other._listaEstadia;
	_promClaif = other._promClaif;
}

DTHostal::DTHostal(std::string nombre, std::string direccion, std::string telefono, float promClaif)
{
	_nombre = nombre;
	_direccion = direccion;
	_telefono = telefono;
	_promClaif = promClaif;
	_listaHabitaciones = nullptr;
	_listaEstadia = nullptr;
}

DTHostal::DTHostal(std::string nombre, std::string direccion, std::string telefono, float promClaif, std::list<DTHabitacion> *listaHabitaciones, std::list<DTEstadia> *listaEstadias)
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
	{
		_listaHabitaciones->clear();
		delete _listaHabitaciones;
		_listaEstadia = nullptr;
	}
	if (_listaEstadia != nullptr)
	{
		_listaEstadia->clear();
		delete _listaEstadia;
		_listaHabitaciones = nullptr;
	}
}

// Operators
std::ostream &operator<<(std::ostream &out, DTHostal imprimir)
{
	out << "Nombre: " << imprimir.getNombre() << std::endl;
	out << "Direccion: " << imprimir.getDireccion() << std::endl;
	out << "Telefono: " << imprimir.getTelefono() << std::endl;
	out << "Promedio de calificaciones: " << imprimir.getPromedioCalificaciones() << std::endl;
	if (imprimir.getListaHabitaciones() != nullptr)
	{
		out << "Habitaciones: " << std::endl;
		for (auto it = imprimir.getListaHabitaciones()->begin(); it != imprimir.getListaHabitaciones()->end(); it++)
		{
			out << *it << std::endl;
		}
	}
	if (imprimir.getListaEstadia() != nullptr)
	{
		out << "Estadias: " << std::endl;
		for (auto it = imprimir.getListaEstadia()->begin(); it != imprimir.getListaEstadia()->end(); it++)
		{
			out << *it << std::endl;
		}
	}
	return out;
}

// Getters
std::string DTHostal::getNombre() const
{
	return _nombre;
}
float DTHostal::getPromedioCalificaciones() const
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

DTHostal& DTHostal::operator=(const DTHostal &hostal)
{
	_nombre = hostal.getNombre();
	_direccion = hostal.getDireccion();
	_telefono = hostal.getTelefono();
	_listaHabitaciones = hostal.getListaHabitaciones();
	_listaEstadia = hostal.getListaEstadia();
	_promClaif = hostal.getPromedioCalificaciones();
	return *this;
}