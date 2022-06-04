#include "Comentario.hpp"


Comentario::Comentario(const Comentario &copy)
{
	_Comentario = copy.getComentario();
	_CalificacionComentario = copy.getCalificacionComentario();
}

Comentario::Comentario(std::string Comentario, Calificacion* CalificacionComentario)
{
	_Comentario = Comentario;
	_CalificacionComentario = CalificacionComentario;
}


// Destructor
Comentario::~Comentario()
{
	delete _CalificacionComentario;
}


// Operators
Comentario & Comentario::operator=(const Comentario &assign)
{
	_Comentario = assign.getComentario();
	_CalificacionComentario = assign.getCalificacionComentario();
	return *this;
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
	return DTComentario(this);
}

int Comentario::ObtenerID()
{
	return _CalificacionComentario->getID();
}