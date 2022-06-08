#ifndef DTCALIFICACION_HPP
#define DTCALIFICACION_HPP

#include <iostream>
#include <string>
#include "../../clases/header/Calificacion.hpp"

class Calificacion;

class DTCalificacion
{
public:
	// Constructors
	DTCalificacion(const Calificacion *&Calificacion);
	DTCalificacion(const Calificacion &Calificacion);
	DTCalificacion(const DTCalificacion &copy);

	// Destructor
	~DTCalificacion();

	// Operators
	DTCalificacion &operator=(const DTCalificacion &assign);

private:
};

#endif
