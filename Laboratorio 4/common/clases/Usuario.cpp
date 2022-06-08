#include "header/Usuario.hpp"
#include <iostream>

std::string Usuario::getNombre()
{
    return this->nombre;
}

void Usuario::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

std::string Usuario::getEmail()
{
    return this->email;
}

void Usuario::setEmail(std::string email)
{
    this->email = email;
}

std::string Usuario::getContrasena()
{
    return this->contrasena;
}

void Usuario::setContrasena(std::string contrasena)
{
    this->contrasena = contrasena;
}

Usuario::Usuario(std::string nombre, std::string email, std::string contrasena){
   this->nombre = nombre;
   this->email = email;
   this->contrasena = contrasena;
}

bool Usuario::operator==(const Usuario &c)  {
    return (nombre == c.nombre && email== c.email );
}
