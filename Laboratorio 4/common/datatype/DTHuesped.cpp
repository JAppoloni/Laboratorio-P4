#include "header/DTHuesped.hpp"
#include <iostream>



// Constructors
DTHuesped::DTHuesped()
{
}

DTHuesped::DTHuesped(const DTHuesped &copy)
{
	(void) copy;
}


DTHuesped::DTHuesped(const Huesped &copy)
{
	(void) copy;
}

DTHuesped::DTHuesped(const Huesped* &copy)
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
