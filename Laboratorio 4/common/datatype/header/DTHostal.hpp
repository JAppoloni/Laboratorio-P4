#ifndef DTHostal_HPP
#define DTHostal_HPP
#include "../../clases/header/Hostal.hpp"
# include <iostream>
# include <string>

class DTHostal
{
	public:
		// Constructors
		DTHostal(Hostal* hostal);
		DTHostal(const DTHostal &copy);
		
		// Destructor
		~DTHostal();
		
		// Operators
		DTHostal & operator=(const DTHostal &assign);
		
	private:
		
};

#endif