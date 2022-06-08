

#ifndef DTEmpleado_HPP
# define DTEmpleado_HPP
#include "../../clases/header/Empleado.hpp"
# include <iostream>
# include <string>

class Empleado;

class DTEmpleado
{
	public:
		// Constructors
		DTEmpleado();
		DTEmpleado(const Empleado* &empleado);
		DTEmpleado(const Empleado &empleado);
		DTEmpleado(const DTEmpleado &copy);
		
		// Destructor
		~DTEmpleado();
		
		// Operators
		DTEmpleado & operator=(const DTEmpleado &assign);
		
	private:
		
};

#endif