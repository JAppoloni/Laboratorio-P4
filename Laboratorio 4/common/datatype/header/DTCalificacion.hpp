#ifndef DTCALIFICACION_HPP
# define DTCALIFICACION_HPP

# include <iostream>
# include <string>
#include "../../clases/header/Comentario.hpp"
#include "../../clases/header/Calificacion.hpp"

class DTCalificacion
{
	public:
		// Constructors
		DTCalificacion(int _puntaje,std::string _comentario,DTFecha _fecha,Estadia* _estadiaComentario);
		DTCalificacion(const DTCalificacion &copy);
		
		// Destructor
		~DTCalificacion();
		
		// Operators
		DTCalificacion & operator=(const DTCalificacion &assign);
		
	private:
		
};

#endif

