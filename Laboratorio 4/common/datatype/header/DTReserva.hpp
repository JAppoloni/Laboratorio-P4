#ifndef DTRESERVA_HPP
# define DTRESERVA_HPP

# include <iostream>
# include <string>
# include "../../clases/header/Reserva.hpp"

class Reserva;

class DTReserva
{
	public:
		// Constructors
		DTReserva();
		DTReserva(const DTReserva &copy);
		DTReserva(const Reserva* &copy);
		DTReserva(const Reserva &copy);

		
		// Destructor
		~DTReserva();
		
		// Operators
		DTReserva & operator=(const DTReserva &assign);
		
	private:
		
};

#endif