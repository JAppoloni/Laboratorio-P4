#include "header/DTCalificacion.hpp"

// ructors
DTCalificacion::DTCalificacion(int IDReserva, std::string IDHuesped, int calificacion, DTFecha fecha, std::string comentario, std::string respuesta)
{
	_IDReserva = IDReserva;
	_IDHuesped = IDHuesped;
	_calificacion = calificacion;
	_fecha = fecha;
	_comentario = comentario;
	_respuesta = respuesta;
}

DTCalificacion::DTCalificacion(int IDReserva, std::string IDHuesped, int calificacion, DTFecha fecha, std::string comentario)
{
	_IDReserva = IDReserva;
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
int DTCalificacion::getIDReserva()
{
	return _IDReserva;
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
