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
		DTHostal(std::string nombre,std::string direccion,std::string telefono, std::list<Habitacion*> listaHabitaciones, std::list<Calificacion*> listaCalificaciones){};
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