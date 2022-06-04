#ifndef HUESPED_HPP
# define HUESPED_HPP

# include <iostream>
# include <string>

class Huesped
{
	public:
		// Constructors
		Huesped();
		Huesped(const Huesped &copy);
		
		// Destructor
		~Huesped();
		
		// Operators
		Huesped & operator=(const Huesped &assign);
		
	private:
		
};

#endif