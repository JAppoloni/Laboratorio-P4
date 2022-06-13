#ifndef DTEMPLEADO_HPP
#define DTEMPLEADO_HPP

#include "../../clases/header/Cargo.hpp"
#include <iostream>
#include <string>
#include "DTUsuario.hpp"

class DTEmpleado : public DTUsuario
{
public:
	// Constructors
	DTEmpleado( std::string nombre, std::string contrasenya, std::string email, Cargo cargo);
	
	// Destructor
	~DTEmpleado();

	// Operators
	virtual std::ostream &operator<<(std::ostream &o);

	// Getters 
	Cargo getCargo() const;

private:
	Cargo _cargo;
};

#endif

