#ifndef DTHuesped_HPP
#define DTHuesped_HPP

#include <iostream>
#include <string>
#include "../../clases/header/Huesped.hpp"

class DTHuesped
{
	public:
		// Constructors
		DTHuesped(Huesped* h);
		DTHuesped(const DTHuesped &copy);
		
		// Destructor
		~DTHuesped();
		
		// Operators
		DTHuesped & operator=(const DTHuesped &assign);
		
	private:
		
};

#endif