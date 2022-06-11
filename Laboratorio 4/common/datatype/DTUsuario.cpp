#include "header/DTUsuario.hpp"

// Constructors
DTUsuario::DTUsuario()
{
}

DTUsuario::DTUsuario(std::string nombre, std::string contrasenya, std::string email)
{
	_nombre = nombre;
	_contrasenya = contrasenya;
	_email = email;
}

// Destructor
DTUsuario::~DTUsuario()
{
}

// Getters
std::string DTUsuario::getNombre() const
{
	return _nombre;
}
std::string DTUsuario::getContrasenya() const
{
	return _contrasenya;
}
std::string DTUsuario::getEmail() const
{
	return _email;
}
