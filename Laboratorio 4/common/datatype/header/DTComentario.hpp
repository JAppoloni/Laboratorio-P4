#ifndef DTComentario_HPP
# define DTComentario_HPP
#include "../../clases/header/Comentario.hpp"
#include "../../clases/header/Calificacion.hpp"

# include <iostream>
# include <string>

class Calificacion;
class DTComentario
{
	public:
		// Constructors
		DTComentario (std::string _Comentario, Calificacion* _CalificacionComentario);
		DTComentario(const DTComentario &copy);

		
		// Destructor
		~DTComentario();
		
		// Operators
		DTComentario & operator=(const DTComentario &assign);
		
	private:

	std::string _Comentario;
	Calificacion* _CalificacionComentario;

		
};

#endif
