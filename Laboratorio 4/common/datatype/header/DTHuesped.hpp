#ifndef DTHuesped_HPP
#define DTHuesped_HPP

#include <iostream>
#include <string>
#include "../../clases/header/Huesped.hpp"

class Huesped;

class DTHuesped
{
	public:
		// Constructors
		DTHuesped();
		DTHuesped(const Huesped &h);
		DTHuesped(const Huesped* &h);
		DTHuesped(const DTHuesped &copy);
		
		// Destructor
		~DTHuesped();
		
		// Operators
		DTHuesped & operator=(const DTHuesped &assign);
		
	private:
		
};

#endif