#include "header/DTEmpleado.hpp"

// Constructors
DTEmpleado::DTEmpleado(std::string nombre, std::string email, std::string contrasena, Cargo cargo,std::list<Notificacion*> notificaciones, std::list<Comentario*> comentarios,Hostal* hostal){

}

DTEmpleado::DTEmpleado(const DTEmpleado &copy)
{
	(void) copy;
}


// Destructor
DTEmpleado::~DTEmpleado()
{
}


// Operators
DTEmpleado & DTEmpleado::operator=(const DTEmpleado &assign)
{
	(void) assign;
	return *this;
}