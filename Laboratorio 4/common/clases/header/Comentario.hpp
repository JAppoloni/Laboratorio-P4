#ifndef Comentario_HPP
#define Comentario_HPP

#include <iostream>
#include <string>
#include "../../datatype/header/DTComentario.hpp"
#include "Calificacion.hpp"

class Calificacion;

class Comentario
{
	public:
		
		// Constructors
		Comentario(const Comentario* &copy);
		Comentario(std::string Comentario, Calificacion* CalificacionComentario);
        ~Comentario();
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

