#include "header/DTHuesped.hpp"

DTHuesped::DTHuesped()
{
}

DTHuesped::DTHuesped(std::string nombre, std::string contrasenya, std::string email, bool esFinger) : DTUsuario(nombre, contrasenya, email)
{
	_esFinger = esFinger;
}

// Destructor
DTHuesped::~DTHuesped()
{
}

// Operators
std::ostream &DTHuesped::operator<<(std::ostream &out)
{
	out << "IMPLEMENTAR" << std::endl;
	return out;
}

// Getters
bool DTHuesped::getEsFinger()
{
	return _esFinger;
}
