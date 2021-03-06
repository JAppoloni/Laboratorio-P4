#ifndef DTCALIFICACION_HPP
#define DTCALIFICACION_HPP

#include <iostream>
#include <string>
#include "DTFecha.hpp"

class DTCalificacion
{
public:
	// Constructors
	DTCalificacion();
	DTCalificacion(int IDReserva, std::string IDHuesped, int calificacion, DTFecha fecha, std::string comentario);
	DTCalificacion(int IDReserva, std::string IDHuesped, int calificacion, DTFecha fecha, std::string comentario, std::string respuesta);

	// Destructor
	~DTCalificacion();

	// Getters / Setters
	int getIDReserva();
	std::string getIDHuesped();
	int getCalificacion();
	DTFecha getFecha();
	std::string getComentario();
	std::string getRespuesta();

private:
	int _IDReserva; 
	std::string _IDHuesped;
	int _calificacion;
	DTFecha _fecha;
	std::string _comentario;
	std::string _respuesta;
};

std::ostream &operator<<(std::ostream &out, DTCalificacion imprimir);

#endif