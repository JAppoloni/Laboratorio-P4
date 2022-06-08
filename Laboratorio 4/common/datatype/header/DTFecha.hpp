#ifndef DTFECHA_HPP
# define DTFECHA_HPP

# include <iostream>
# include <string>

class DTFecha
{
	public:
		// Constructors
		DTFecha();
		DTFecha(const DTFecha &copy);
		
		// Destructor
		~DTFecha();
		
		// Operators
		DTFecha & operator=(const DTFecha &assign);
		inline bool operator>=(const DTFecha& compare);

	private:
		
};

#endif