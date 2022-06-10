#include "header/DTNotificacion.hpp"

// Constructors

DTNotificacion::DTNotificacion(const DTNotificacion &copy)
{

}

DTNotificacion::DTNotificacion(std::string pautor, std::string pcomentario, int ppuntaje)
{
	autor = pautor;
	comentario = pcomentario;
	puntaje = ppuntaje;
}


// Destructor
DTNotificacion::~DTNotificacion()
{
}


// Operators
DTNotificacion & DTNotificacion::operator=(const DTNotificacion &assign)
{
	(void) assign;
	return *this;
}
