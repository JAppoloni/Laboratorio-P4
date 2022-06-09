#include "header/DTCalificacion.hpp"

// Constructors
DTCalificacion::DTCalificacion(int _puntaje,std::string _comentario,DTFecha _fecha,Estadia* _estadiaComentario)
{
}

DTCalificacion::DTCalificacion(const DTCalificacion &copy)
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

