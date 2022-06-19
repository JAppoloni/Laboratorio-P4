#ifndef DTHOSTAL_HPP
#define DTHOSTAL_HPP

#include <iostream>
#include <string>
#include "DTHabitacion.hpp"
#include "DTEstadia.hpp"

class DTHostal
{
public:
	// Constructors
	DTHostal(std::string nombre, std::string direccion, std::string telefono);
	DTHostal(std::string nombre, std::string direccion, std::string telefono, float promClaif);

	DTHostal(std::string nombre, std::string direccion, std::string telefono, float promClaif, std::list<DTHabitacion> *listaHabitaciones, std::list<DTEstadia> *listaEstadias, std::list<DTCalificacion> *listaCalificaciones );
	DTHostal(const DTHostal &other);

	// Destructor
	~DTHostal();

	// Operators
	DTHostal &operator=(const DTHostal &hostal);

	// Getters
	float getPromedioCalificaciones() const;
	std::string getNombre() const;
	std::string getDireccion() const;
	std::string getTelefono() const;
	std::list<DTHabitacion> *getListaHabitaciones() const;
	std::list<DTEstadia> *getListaEstadia() const;
	std::list<DTCalificacion> *getListaCalificaciones() const;

private:
	float _promClaif;
	std::string _nombre;
	std::string _direccion;
	std::string _telefono;
	std::list<DTHabitacion> *_listaHabitaciones;
	std::list<DTEstadia> *_listaEstadia;
	std::list<DTCalificacion> *_listaCalificaciones;
};

std::ostream &operator<<(std::ostream &out, DTHostal imprimir);
#endif