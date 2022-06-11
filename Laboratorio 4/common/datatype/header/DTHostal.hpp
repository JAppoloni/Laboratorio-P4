#ifndef DTHOSTAL_HPP
# define DTHOSTAL_HPP

# include <iostream>
# include <string>
# include "DTHabitacion.hpp"
# include "DTEstadia.hpp"

class DTHostal
{
	public:
		// Constructors
		DTHostal(std::string nombre, std::string direccion, std::string telefono);
		DTHostal(std::string nombre, std::string direccion, std::string telefono, std::list<DTHabitacion>* listaHabitaciones, std::list<DTEstadia> *listaEstadias);
		
		// Destructor
		~DTHostal();
				
		// Getters
		std::string getNombre() const;
		std::string getDireccion() const;
		std::string getTelefono() const;
		std::list<DTHabitacion>* getListaHabitaciones() const;
		std::list<DTEstadia>* getListaEstadia() const;
		
	private:
		std::string _nombre;
		std::string _direccion;
		std::string _telefono;
		std::list<DTHabitacion>* _listaHabitaciones;
		std::list<DTEstadia>* _listaEstadia;
		
};

std::ostream &operator<<(std::ostream &out, DTHostal imprimir);
#endif