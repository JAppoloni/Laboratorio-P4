#ifndef DTHostal_HPP
#define DTHostal_HPP
#include "../../clases/header/Hostal.hpp"
# include <iostream>
# include <string>

class Hostal;

class DTHostal
{
	public:
		// Constructors
		DTHostal();
		DTHostal(const Hostal* &hostal);
		DTHostal(const Hostal &hostal);
		DTHostal(const DTHostal &copy);
		
		// Destructor
		~DTHostal();
		
		// Operators
		DTHostal & operator=(const DTHostal &assign);
		
	private:
		
};

#endif