#ifndef DTComentario_HPP
# define DTComentario_HPP

# include <iostream>
# include <string>

class DTComentario
{
	public:
		// Constructors
		DTComentario();
		DTComentario(const DTComentario &copy);
		
		// Destructor
		~DTComentario();
		
		// Operators
		DTComentario & operator=(const DTComentario &assign);
		
	private:
		
};

#endif