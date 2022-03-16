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

DTHuesped::DTHuesped(std::string nombre, std::string email, bool esFinger) {
    this->nombre = nombre;
    this->email = email;
    this->esFinger = esFinger;
}

// #ifndef _DTHUESPED_HH_
// #define _DTHUESPED_HH_

// #include <string>

// class DTHuesped
// {
// private:
//     std::string nombre;
//     std::string email;
//     bool esFinger;

// public:
//     void imprimir();

//     std::string getNombre();
//     std::string getEmail();
//     bool getEsFinger();

//     DTHuesped(std::string, std::string, bool);
// };

// #endif


