#include "header/Calificacion.hpp"


void Calificacion::ValidarPuntaje(int puntaje)
{
	if (puntaje < 1 || puntaje > 5)
	{
		throw OutOfRange();
	}
}

Calificacion::Calificacion(const Calificacion &copy)
{
	ValidarPuntaje(copy.getPuntaje());
	_puntaje = copy.getPuntaje();
	_comentario = copy.getComentario();
	_fecha = copy.getFecha();
	_estadiaComentario = copy.getEstadiaComentario();
	_respuestaComentario = copy.getRespuestaComentario();
}

Calificacion::Calificacion(int puntaje, std::string comentario, DTFecha fecha, Estadia *estadiaComentario)
{
	ValidarPuntaje(puntaje);
	_puntaje = puntaje;
	_comentario = comentario;
	_fecha = fecha;
	_estadiaComentario = estadiaComentario;
	_respuestaComentario = NULL;
}

Calificacion::Calificacion(int puntaje, std::string comentario, DTFecha fecha, Estadia *estadiaComentario, Comentario *respuestaComentario)
{
	ValidarPuntaje(puntaje);
	_puntaje = puntaje;
	_comentario = comentario;
	_fecha = fecha;
	_estadiaComentario = estadiaComentario;
	_respuestaComentario = respuestaComentario;
}

// Destructor
Calificacion::~Calificacion()
{
	_estadiaComentario = nullptr;
	
	delete _estadiaComentario;
	delete _respuestaComentario;
}

// Operators
Calificacion &Calificacion::operator=(const Calificacion &assign)
{
	_puntaje = assign.getPuntaje();
	_comentario = assign.getComentario();
	_fecha = assign.getFecha();
	_estadiaComentario = assign.getEstadiaComentario();
	_respuestaComentario = assign.getRespuestaComentario();
	return *this;
}

bool Calificacion::operator==(const Calificacion &assign)
{
	return (_estadiaComentario == assign._estadiaComentario);
}

// Getters / Setters
int Calificacion::getPuntaje() const
{
	return _puntaje;
}
void Calificacion::setPuntaje(int puntaje)
{
	_puntaje = puntaje;
}

std::string Calificacion::getComentario() const
{
	return _comentario;
}
void Calificacion::setComentario(std::string comentario)
{
	_comentario = comentario;
}

DTFecha Calificacion::getFecha() const
{
	return _fecha;
}
void Calificacion::setFecha(DTFecha fecha)
{
	_fecha = fecha;
}

Estadia *Calificacion::getEstadiaComentario() const
{
	return _estadiaComentario;
}
void Calificacion::setEstadiaComentario(Estadia *estadiaComentario)
{
	_estadiaComentario = estadiaComentario;
}

Comentario *Calificacion::getRespuestaComentario() const
{
	return _respuestaComentario;
}
void Calificacion::setRespuestaComentario(Comentario *respuestaComentario)
{
	_respuestaComentario = respuestaComentario;
}

// Exceptions
const char *Calificacion::OutOfRange::what() const throw()
{
	return "El puntaje no se encuentra en el intervalo 1-5.";
}

// Methods
DTCalificacion Calificacion::getDataType()
{
	return DTCalificacion(*this);
}

int Calificacion::obtenerID()
{
	return this->getEstadiaComentario()->obtenerID();
}

bool Calificacion::estaResponida()
{
	return this->getRespuestaComentario() != NULL;
}