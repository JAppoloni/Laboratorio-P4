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

class Calificacion
{
	public:
		// Constructors
		Calificacion(const Calificacion &copy);
		Calificacion(int puntaje, std::string comentario, DTFecha fecha, Estadia* estadiaComentario, Comentario* respuestaComentario);
		Calificacion(int puntaje, std::string comentario, DTFecha fecha, Estadia* estadiaComentario);
		
		// Destructor
		~Calificacion();
		
		// Operators
		Calificacion & operator=(const Calificacion &assign);
		bool operator==(const Calificacion & assign);
		
		// Getters / Setters
		int getPuntaje() const;
		void setPuntaje(int puntaje);
		std::string getComentario() const;
		void setComentario(std::string comentario);
		DTFecha getFecha() const;
		void setFecha(DTFecha fecha);
		Estadia* getEstadiaComentario() const;
		void setEstadiaComentario(Estadia* estadiaComentario);
		Comentario* getRespuestaComentario() const;
		void setRespuestaComentario(Comentario* respuestaComentario);
		
		// Exceptions
		class OutOfRange : public std::exception {
			virtual const char* what() const throw();
		};

		// Methods
		DTCalificacion getDataType();
		int obtenerID();
		bool estaResponida();
		
	private:
		int _puntaje;
		std::string _comentario;
		DTFecha _fecha;
		Estadia* _estadiaComentario;
		Comentario* _respuestaComentario;


		void ValidarPuntaje(int puntaje);		
};

#endif