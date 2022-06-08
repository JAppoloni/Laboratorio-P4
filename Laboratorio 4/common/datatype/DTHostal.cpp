#include "header/DTHostal.hpp"
#include <iostream>



// Constructors
DTHostal::DTHostal()
{
}

DTHostal::DTHostal(const DTHostal &copy)
{
	(void) copy;
}


DTHostal::DTHostal(const Hostal &copy)
{
	(void) copy;
}

DTHostal::DTHostal(const Hostal* &copy)
{
	(void) copy;
}

// Destructor
DTHostal::~DTHostal()
{
}


// Operators
DTHostal & DTHostal::operator=(const DTHostal &assign)
{
	(void) assign;
	return *this;
}
