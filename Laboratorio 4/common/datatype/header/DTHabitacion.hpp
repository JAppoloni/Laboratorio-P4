#ifndef DTHABITACION_HPP
#define DTHABITACION_HPP

#include <iostream>
#include <list>
#include <string>
#include "DTCalificacion.hpp"

class DTHabitacion
{
public:
	// Constructors
	DTHabitacion();
	DTHabitacion(int numero, float precio, int capacidad);
	DTHabitacion(int numero, float precio, int capacidad, std::list<DTCalificacion> *listaCalificaciones);

	// Destructor
	~DTHabitacion();

	// Getters 
	int getNumero() const;
	float getPrecio() const;
	int getCapacidad() const;
	std::list<DTCalificacion> *getListaCalificaciones() const;

private:
	int _numero;
	float _precio;
	int _capacidad;
	std::list<DTCalificacion> *_listaCalificaciones;
};

std::ostream &operator<<(std::ostream &out, DTHabitacion imprimir);
#endif