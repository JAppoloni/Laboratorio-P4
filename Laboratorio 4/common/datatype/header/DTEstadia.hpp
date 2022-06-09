#ifndef DTEstadia_HPP
#define DTEstadia_HPP

# include <iostream>
# include <string>
#include "Estadia.hpp"

class DTEstadia
{
	public:
		// Constructors
		DTEstadia(Estadia* estadia);
		DTEstadia(const DTEstadia &copy);
		
		// Destructor
		~DTEstadia();
		
		// Operators
		DTEstadia & operator=(const DTEstadia &assign);
		
	private:
		
};

#endif
