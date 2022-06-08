#include "header/Notificacion.hpp"

// Constructors

Notificacion::Notificacion(std::string pautor, std::string pcomentario, int ppuntaje)
{
	autor = pautor;
	comentario = pcomentario;
	puntaje = ppuntaje;
}

// Destructor

void Notificacion::set(std::string autor)
{
	this->autor = autor;
}

DTNotificacion Notificacion::getDatatype()
{
	return DTNotificacion(autor, comentario, puntaje);
}
