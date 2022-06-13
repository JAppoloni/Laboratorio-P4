#ifndef DTUSUARIO_HPP
#define DTUSUARIO_HPP

#include <iostream>
#include <string>

class DTUsuario
{
public:
	// Constructors
	DTUsuario();
	DTUsuario(std::string nombre, std::string contrasenya, std::string email);

	// Destructor
	virtual ~DTUsuario();

	// Operators
	virtual std::ostream &operator<<(std::ostream &o) = 0;

	// Getters 
	std::string getNombre() const;
	std::string getContrasenya() const;
	std::string getEmail() const;

protected:
	std::string _nombre;
	std::string _contrasenya;
	std::string _email;
};

#endif