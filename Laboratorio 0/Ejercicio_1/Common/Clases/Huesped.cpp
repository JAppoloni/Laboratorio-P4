#include "header/Huesped.hpp"
#include <iostream>

std::string Huesped::getNombre() { 
    return this->nombre; 
}

void Huesped::setNombre(std::string nombre) { 
    this->nombre = nombre; 
}

std::string Huesped::getEmail() { 
    return this->email; 
}

void Huesped::setEmail(std::string email) { 
    this->email = email; 
}

bool Huesped::getEsFinger() { 
    return this->esFinger; 
}

void Huesped::setEsFinger(bool esFinger) { 
    this->esFinger = esFinger; 
}

void Huesped::imprimir() { 
    std::cout << " El huesped " << this->nombre << " posee el correo " << this->email << " y " << (this->esFinger == true) ? "es Finger." : "no es Finger."; 
}

Huesped::Huesped(std::string nombre, std::string correo, bool esFing) {
    this->email=correo;
    this->nombre=nombre;
    this->esFinger=esFing;
}

//~Huesped();
