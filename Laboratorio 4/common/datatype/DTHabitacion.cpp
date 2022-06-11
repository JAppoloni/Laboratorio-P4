#include "header/DTHabitacion.hpp"

// Constructors
DTHabitacion::DTHabitacion()
{
}

DTHabitacion::DTHabitacion(int numero, float precio, int capacidad)
{
	_numero = numero;
	_precio = precio;
	_capacidad = capacidad;
	_listaCalificaciones = nullptr;
}

DTHabitacion::DTHabitacion(int numero, float precio, int capacidad, std::list<DTCalificacion> *listaCalificaciones)
{
	_numero = numero;
	_precio = precio;
	_capacidad = capacidad;
	_listaCalificaciones = listaCalificaciones;
}

// Operators
std::ostream &operator<<(std::ostream &out, DTHabitacion imprimir)
{
	return out << " Implementar /n";
}

// Destructor
DTHabitacion::~DTHabitacion()
{
}

// Getters
int DTHabitacion::getNumero() const
{
	return _numero;
}
float DTHabitacion::getPrecio() const
{
	return _precio;
}
int DTHabitacion::getCapacidad() const
{
	return _capacidad;
}
std::list<DTCalificacion> *DTHabitacion::getListaCalificaciones() const
{
	return _listaCalificaciones;
}
