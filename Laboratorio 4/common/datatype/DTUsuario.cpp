#include "header/DTUsuario.hpp"
#include <iostream>
// Constructors
DTUsuario::DTUsuario(Usuario* h)
{
}

DTUsuario::DTUsuario(const DTUsuario &copy)
{
	(void) copy;
}


// Destructor
DTUsuario::~DTUsuario()
{

}


// Operators
DTUsuario & DTUsuario::operator=(const DTUsuario &assign)
{
	(void) assign;
	return *this;
}
