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

DTHuesped::DTHuesped(){
    this->email = "";
    this->email = "";
    this->esFinger = false;

}

DTHuesped& DTHuesped::operator = (const DTHuesped &huesped){
     if(this!= &huesped){ 
         this->nombre = huesped.nombre;
         this->email = huesped.email;
         this->esFinger = huesped.esFinger;
    }
    return *this;
}




