#ifndef DTHUESPED_HPP
#define DTHUESPED_HPP

#include <iostream>
#include <string>
#include "DTUsuario.hpp"

class DTHuesped : public DTUsuario
{
public:
	// Constructors
	DTHuesped();
	DTHuesped(std::string nombre, std::string contrasenya, std::string email, bool esFinger);

	// Destructor
	~DTHuesped();

	// Operators
	virtual std::ostream &operator<<(std::ostream &o);

	// Getters 
	bool getEsFinger();

private:
	bool _esFinger;
};

#endif