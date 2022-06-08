

#ifndef DTUsuario_HPP
# define DTUsuario_HPP
#include "../../clases/header/Usuario.hpp"
# include <iostream>
# include <string>

class DTUsuario
{
	public:
		// Constructors
		DTUsuario(Usuario* usuario);
		DTUsuario(const DTUsuario &copy);
		
		// Destructor
		~DTUsuario();
		
		// Operators
		DTUsuario & operator=(const DTUsuario &assign);
		
	private:
		
};

#endif