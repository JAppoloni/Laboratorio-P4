#include "header/DTCalificacion.hpp"

// ructors
DTCalificacion::DTCalificacion(int IDCalificacion, std::string IDHuesped, int calificacion, DTFecha fecha, std::string comentario, std::string respuesta)
{
	_IDCalificacion = IDCalificacion;
	_IDHuesped = IDHuesped;
	_calificacion = calificacion;
	_fecha = fecha;
	_comentario = comentario;
	_respuesta = respuesta;
}

DTCalificacion::DTCalificacion(int IDCalificacion, std::string IDHuesped, int calificacion, DTFecha fecha, std::string comentario)
{
	_IDCalificacion = IDCalificacion;
	_IDHuesped = IDHuesped;
	_calificacion = calificacion;
	_fecha = fecha;
	_comentario = comentario;
}

// Destructor
DTCalificacion::~DTCalificacion()
{
}

// Operators
std::ostream &operator<<(std::ostream &out, DTCalificacion imprimir)
{
	return out << " Implementar /n";
}

// Getters
int DTCalificacion::getIDCalificacion()
{
	return _IDCalificacion;
}
std::string DTCalificacion::getIDHuesped()
{
	return _IDHuesped;
}
int DTCalificacion::getCalificacion()
{
	return _calificacion;
}
DTFecha DTCalificacion::getFecha()
{
	return _fecha;
}
std::string DTCalificacion::getComentario()
{
	return _comentario;
}
std::string DTCalificacion::getRespuesta()
{
	return _respuesta;
}
