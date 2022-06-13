#ifndef DTCOMENTARIO_HPP
#define DTCOMENTARIO_HPP

#include <iostream>
#include <string>

class DTComentario
{
public:
	// Constructors
	DTComentario(std::string comentario);

	// Destructor
	~DTComentario();

	// Getters
	std::string getComentario() const;

private:
	std::string _comentario;
};

std::ostream &operator<<(std::ostream &out, DTComentario imprimir);
#endif