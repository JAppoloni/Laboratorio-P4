#ifndef DTComentario_HPP
# define DTComentario_HPP
#include "../../clases/header/Comentario.hpp"

# include <iostream>
# include <string>

class DTComentario
{
	public:
		// Constructors
		DTComentario(Comentario* comentario);
		DTComentario(const DTComentario &copy);
		
		// Destructor
		~DTComentario();
		
		// Operators
		DTComentario & operator=(const DTComentario &assign);
		
	private:
		
};

#endif
