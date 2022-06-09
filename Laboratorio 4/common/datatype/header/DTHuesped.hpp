#ifndef DTHuesped_HPP
#define DTHuesped_HPP
#include <iostream>
#include <string>
#include <list>
#include "../../clases/header/Huesped.hpp"
#include "../../clases/header/Estadia.hpp"

class DTHuesped
{
	public:
		// Constructors
		DTHuesped( std::string nombre, std::string email, std::string contrasena,bool esFinger, std::list<Estadia*> estadias);
		//DTHuesped(const DTHuesped &copy);
		
		// Destructor
		~DTHuesped();
		
		// Operators
		DTHuesped & operator=(const DTHuesped &assign);
		
	private:
    std::string nombre;
	std::string email;
	std::string contrasena;
	bool esFinger;
    std::list<Estadia*> estadias;
		
};

#endif