#include "header/DTHuesped.hpp"
#include <iostream>

std::string DTHuesped::getNombre() { 
    return this->nombre; 
}

std::string DTHuesped::getEmail() {
    return this->email; 
}

bool DTHuesped::getEsFinger() { 
    return this->esFinger; 
}

bool DTHuesped::esVacia(){
    return (this->email == "") && (this->nombre =="") && (!this->esFinger);
}

DTHuesped::DTHuesped(std::string nombre, std::string email, bool esFinger) {
    this->nombre = nombre;
    this->email = email;
    this->esFinger = esFinger;
}

DTHuesped::DTHuesped(Huesped* huesped) {
    this->nombre = huesped->getNombre();
    this->email = huesped->getEmail();
    this->esFinger = huesped->getEsFinger();
}

std::ostream& operator<<(std::ostream& out, DTHuesped &huesped) {
    out << "Nombre: " << huesped.getNombre() << std::endl;   
    out << "Email: " << huesped.getEmail() << std::endl;
    out << "Es FInger: " << (huesped.getEsFinger() ? "SI" : "NO") << std::endl;
    out << "-----------------------" << std::endl;

    return out;
}