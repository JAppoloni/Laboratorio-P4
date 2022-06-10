#include "header/DTCalificacion.hpp"

// Constructors

DTCalificacion::DTCalificacion(const DTCalificacion &copy)
{
	(void) copy;
}

DTCalificacion::DTCalificacion(const Calificacion &copy)
{
	(void) copy;
}

DTCalificacion::DTCalificacion(const Calificacion* &copy)
{
	(void) copy;
}


// Destructor
DTCalificacion::~DTCalificacion()
{
}


// Operators
DTCalificacion & DTCalificacion::operator=(const DTCalificacion &assign)
{
	(void) assign;
	return *this;
}

