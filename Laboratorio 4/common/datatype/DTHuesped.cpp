#include "header/DTHuesped.hpp"
#include <iostream>



// Constructors
DTHuesped::DTHuesped( std::string nombre,std::string email, std::string contrasena,bool esFinger,std::list<Estadia*> estadias)
{
}

//DTHuesped::DTHuesped(const DTHuesped &copy)
//{
	//(void) copy;
//}


// Destructor
DTHuesped::~DTHuesped()
{

}


// Operators
DTHuesped & DTHuesped::operator=(const DTHuesped &assign)
{
	(void) assign;
	return *this;
}
