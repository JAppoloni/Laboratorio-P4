

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
		DTEmpleado(std::string nombre, std::string email, std::string contrasena, Cargo cargo,std::list<Notificacion*> notificaciones, std::list<Comentario*> comentarios,Hostal* hostal){};
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