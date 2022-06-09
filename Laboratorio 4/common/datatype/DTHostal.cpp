#include "header/DTHostal.hpp"
#include <iostream>
// Constructors
DTHostal::DTHostal(std::string nombre,std::string direccion,std::string telefono, std::list<Habitacion*> listaHabitaciones, std::list<Calificacion*> listaCalificaciones)
{

}

//DTHostal::DTHostal(const DTHostal &copy)
//{
//	(void) copy;
//}


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