#include "header/DTHuesped.hpp"
#include <iostream>
// Constructors
DTHuesped::DTHuesped(Huesped* h)
{
}

DTHuesped::DTHuesped(const DTHuesped &copy)
{
	(void) copy;
}


// Destructor
DTHuesped::~DTHuesped()
{

}


// Operators
DTHuesped & DTHuesped::operator=(const DTHuesped &assign)
{
	(void) assign;
	return *this;
}
