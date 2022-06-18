#ifndef Comentario_HPP
#define Comentario_HPP

#include <iostream>
#include <string>
#include "../../datatype/header/DTComentario.hpp"
#include "Calificacion.hpp"

class DTComentario;
class Calificacion;

class Comentario
{
	public:
		
		// Constructors
		Comentario(std::string Comentario, Calificacion* CalificacionComentario);
		
		// Destructor
		~Comentario();
		
		// Operators
		bool operator==(const Comentario & assign);

		
		// Getters / Setters
		std::string getComentario() const;
		void setComentario(std::string Comentario);
		Calificacion* getCalificacionComentario() const;

		// Methods
		DTComentario getDataType();
		int obtenerID();
		
	private:
		std::string _Comentario;
		Calificacion* _CalificacionComentario;
		
};

#endif