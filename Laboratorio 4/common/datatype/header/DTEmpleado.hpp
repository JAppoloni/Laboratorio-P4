

#ifndef DTEmpleado_HPP
# define DTEmpleado_HPP
#include "../../clases/header/Empleado.hpp"
# include <iostream>
# include <string>

class DTEmpleado
{
	public:
		// Constructors
		DTEmpleado(Empleado* empleado);
		DTEmpleado(const DTEmpleado &copy);
		
		// Destructor
		~DTEmpleado();
		
		// Operators
		DTEmpleado & operator=(const DTEmpleado &assign);
		
	private:
		
};

#endif