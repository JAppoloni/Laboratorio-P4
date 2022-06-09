#ifndef DTEmpleado_HPP
# define DTEmpleado_HPP
#include "../../clases/header/Empleado.hpp"
#include "../../clases/header/Cargo.hpp"
#include "../../clases/header/Notificacion.hpp"
#include "../../clases/header/Comentario.hpp"
#include "../../clases/header/Hostal.hpp"
#include "DTFecha.hpp"
# include <iostream>
# include <string>

class DTEmpleado
{
	public:
		// Constructors
		DTEmpleado(std::string nombre, std::string email, std::string contrasena, Cargo cargo,std::list<Notificacion*> notificaciones, std::list<Comentario*> comentarios,Hostal* hostal);
		DTEmpleado(const DTEmpleado &copy);
		
		// Destructor
		~DTEmpleado();
		
		// Operators
		DTEmpleado & operator=(const DTEmpleado &assign);
		
	private:
		std::string nombre;
		 std::string email; 
		 std::string contrasena;
		Cargo cargo;
		std::list<Notificacion*> notificaciones;
		 std::list<Comentario*> comentarios;
		 Hostal* hostal;
};

#endif