#include "header/DTComentario.hpp"

// Constructors
DTComentario::DTComentario(std::string _Comentario, Calificacion* _CalificacionComentario)
{

}

DTComentario::DTComentario(const DTComentario &copy)
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