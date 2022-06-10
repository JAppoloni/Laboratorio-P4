#ifndef DTCALIFICACION_HPP
#define DTCALIFICACION_HPP

#include <iostream>
#include <string>
#include "../../clases/header/Calificacion.hpp"
#include "../../clases/header/Estadia.hpp"

class Calificacion;
class Estadia;

class DTCalificacion
{
public:
	// Constructors
	DTCalificacion(int _puntaje, std::string _comentario, DTFecha _fecha, Estadia *_estadiaComentario){};
	DTCalificacion(const Calificacion *&Calificacion);
	DTCalificacion(const Calificacion &Calificacion);
	DTCalificacion(const DTCalificacion &copy);

	// Destructor
	~DTCalificacion();

	// Operators
	DTCalificacion &operator=(const DTCalificacion &assign);

private:
};

#endif
