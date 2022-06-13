#include "header/DTEmpleado.hpp"

// Constructors

DTEmpleado::DTEmpleado(std::string nombre, std::string contrasenya, std::string email, Cargo cargo): DTUsuario(nombre, contrasenya, email)
{
	_cargo = cargo;
}

std::ostream &DTEmpleado::operator<<(std::ostream &out)
{
	out << "IMPLEMENTAR" << std::endl;
	return out;
}

// Destructor
DTEmpleado::~DTEmpleado()
{
}

// Getters 
Cargo DTEmpleado::getCargo() const
{
	return _cargo;
}
