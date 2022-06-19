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
}


// Operators
std::ostream &operator<<(std::ostream &out, DTHabitacion imprimir)
{
	out << "Número: " << imprimir.getNumero() << std::endl;
	out << "Precio: " << imprimir.getPrecio() << std::endl;
	out << "Capacidad: " << imprimir.getCapacidad() << std::endl;
	return out;
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
