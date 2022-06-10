#include "header/DTEmpleado.hpp"

// Constructors
DTEmpleado::DTEmpleado()
{
}

DTEmpleado::DTEmpleado(const Empleado &copy)
{
	(void)copy;
}

DTEmpleado::DTEmpleado(const Empleado *&copy)
{
	(void)copy;
}

DTEmpleado::DTEmpleado(const DTEmpleado &copy)
{
	(void)copy;
}

// Destructor
DTEmpleado::~DTEmpleado()
{
}

// Operators
DTEmpleado &DTEmpleado::operator=(const DTEmpleado &assign)
{
	(void)assign;
	return *this;
}
