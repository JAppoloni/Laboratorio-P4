#include "header/DTComentario.hpp"

// Constructors

DTComentario::DTComentario(const DTComentario &copy)
{
	(void) copy;
}

DTComentario::DTComentario(const Comentario &copy)
{
	(void) copy;
}

DTComentario::DTComentario(const Comentario* &copy)
{
	(void) copy;
}

// Destructor
DTComentario::~DTComentario()
{
}


// Operators
DTComentario & DTComentario::operator=(const DTComentario &assign)
{
	(void) assign;
	return *this;
}

