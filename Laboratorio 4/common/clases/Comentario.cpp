#include "header/Comentario.hpp"


Comentario::Comentario(std::string Comentario, Calificacion* CalificacionComentario)
{
	_Comentario = Comentario;
	_CalificacionComentario = CalificacionComentario;
}


// Destructor
Comentario::~Comentario()
{
	_CalificacionComentario = nullptr;
}



bool Comentario::operator==(const Comentario & assign)
{
    return (_CalificacionComentario==assign._CalificacionComentario);
}


// Getters / Setters
std::string Comentario::getComentario() const
{
	return _Comentario;
}
void Comentario::setComentario(std::string Comentario)
{
	_Comentario = Comentario;
}

Calificacion* Comentario::getCalificacionComentario() const
{
	return _CalificacionComentario;
}

// Methods
DTComentario Comentario::getDataType()
{
	return DTComentario(_Comentario);
}

int Comentario::obtenerID()
{
	return _CalificacionComentario->obtenerID();
}