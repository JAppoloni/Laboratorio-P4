#include "header/DTNotificacion.hpp"

// Constructors
DTNotificacion::DTNotificacion(std::string autor, std::string comentario, int puntaje)
{
	_autor = autor;
	_comentario = comentario;
	_puntaje = puntaje;
}

// Destructor
DTNotificacion::~DTNotificacion()
{
}

// Operators
std::ostream &operator<<(std::ostream &out, DTNotificacion imprimir)
{
	return out << " Implementar /n";
}

// Getters
std::string DTNotificacion::getAutor() const
{
	return _autor;
}
std::string DTNotificacion::getComentario() const
{
	return _comentario;
}
int DTNotificacion::getPuntaje() const
{
	return _puntaje;
}
