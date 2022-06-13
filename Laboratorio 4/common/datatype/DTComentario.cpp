#include "header/DTComentario.hpp"

DTComentario::DTComentario(std::string comentario)
{
	_comentario = comentario;
}

// Destructor
DTComentario::~DTComentario()
{
}

// Operators
std::ostream &operator<<(std::ostream &out, DTComentario imprimir)
{
	return out << " Implementar /n";
}

// Getters 
std::string DTComentario::getComentario() const
{
	return _comentario;
}
