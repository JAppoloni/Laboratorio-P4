#ifndef DTHostal_HPP
#define DTHostal_HPP
#include "../../clases/header/Hostal.hpp"
#include "../../clases/header/Calificacion.hpp"
#include "../../clases/header/Habitacion.hpp"
# include <iostream>
# include <string>
# include <list>

class DTHostal
{
	public:
		// Constructors
		DTHostal(std::string nombre,std::string direccion,std::string telefono, std::list<Habitacion*> listaHabitaciones, std::list<Calificacion*> listaCalificaciones);
		//DTHostal(const DTHostal &copy);
		
		// Destructor
		~DTHostal();
		
		// Operators
		DTHostal & operator=(const DTHostal &assign);
		
	private:
	std::string nombre;
	std::string direccion;
	std::string telefono;
	std::list<Habitacion*> listaHabitaciones;
	std::list<Calificacion*> listaCalificaciones;
		
};

#endif