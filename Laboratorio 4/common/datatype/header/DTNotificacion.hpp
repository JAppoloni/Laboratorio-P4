#ifndef DTNotificacion_HPP
#define DTNotificacion_HPP
#include "../../clases/header/Notificacion.hpp"
#include <iostream>
#include <string>

class DTNotificacion
{
	public:
		// Constructors
		DTNotificacion(std::string autor,std::string comentario, int puntaje);
		DTNotificacion(const DTNotificacion &copy);
		
		// Destructor
		~DTNotificacion();
		
		// Operators
		DTNotificacion & operator=(const DTNotificacion &assign);
		
	private:

	std::string autor;
	std::string comentario;
	int puntaje;
		
};

#endif