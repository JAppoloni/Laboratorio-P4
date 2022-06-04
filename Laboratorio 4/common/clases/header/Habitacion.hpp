#ifndef HABITACION_HPP
#define HABITACION_HPP

#include <iostream>
#include <string>

class Habitacion
{
	public:
		// Constructors
		Habitacion();
		Habitacion(const Habitacion &copy);
		
		// Destructor
		~Habitacion();
		
		// Operators
		Habitacion & operator=(const Habitacion &assign);
		
	private:
		
};

#endif