#ifndef DTCALIFICACION_HPP
# define DTCALIFICACION_HPP

# include <iostream>
# include <string>
#include "../../clases/header/Calificacion.hpp"
class DTCalificacion
{
	public:
		// Constructors
		DTCalificacion(Calificacion* c);
		DTCalificacion(const DTCalificacion &copy);
		
		// Destructor
		~DTCalificacion();
		
		// Operators
		DTCalificacion & operator=(const DTCalificacion &assign);
		
	private:
		
};

#endif
