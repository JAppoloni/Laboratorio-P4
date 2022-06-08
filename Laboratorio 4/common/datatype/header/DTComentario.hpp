#ifndef DTComentario_HPP
# define DTComentario_HPP
#include "../../clases/header/Comentario.hpp"

# include <iostream>
# include <string>

class Comentario;


class DTComentario
{
	public:
		// Constructors
		DTComentario(const Comentario &comentario);
		DTComentario(const Comentario* &comentario);
		DTComentario(const DTComentario &copy);
		
		// Destructor
		~DTComentario();
		
		// Operators
		DTComentario & operator=(const DTComentario &assign);
		
	private:
		
};

#endif
