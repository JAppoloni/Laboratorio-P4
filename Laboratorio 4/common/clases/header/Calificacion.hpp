#ifndef CALIFICACION_HPP
#define CALIFICACION_HPP

#include <iostream>
#include <string>
#include "../../datatype/header/DTFecha.hpp"
#include "../../datatype/header/DTCalificacion.hpp"
#include "Comentario.hpp"
#include "Estadia.hpp"


class Estadia;
class Comentario;

class Calificacion {
private:
    int _puntaje;
	std::string _comentario;
	DTFecha _fecha;
	Estadia* _estadiaComentario;
	Comentario* _respuestaComentario;
	


 
public:
 // Constructors
		Calificacion(const Calificacion &copy);
	//	Calificacion(int puntaje, std::string comentario, DTFecha fecha, Estadia* estadiaComentario, Comentario* respuestaComentario);
		Calificacion(int puntaje, std::string comentario, DTFecha fecha, Estadia* estadiaComentario);
		

 int obtenerID();
 bool estaRespondida();
 DTCalificacion getDatatype();
 std::string getComentario() const;
int getPuntaje() const;
Estadia* getEstadiaComentario() ;


};

#endif