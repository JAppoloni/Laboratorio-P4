#include "header/Huesped.hpp"
#include <iostream>


bool Huesped::getEsFinger()
{
    return this->esFinger;
}

void Huesped::setEsFinger(bool esFinger) {
    this->esFinger = esFinger;
}

std::list<Estadia*> Huesped::getEstadias(){
    return this->estadias;
}

void Huesped::setEstadias(std::list<Estadia*> estadias){
    this->estadias = estadias;
}


Huesped::Huesped(std::string nombre, std::string email, std::string contrasena,bool esFinger,std::list<Estadia*> estadias):Usuario(nombre,  email, contrasena) {
  this->esFinger = esFinger;
  this->estadias = estadias;
}
Huesped::Huesped(const Huesped &copy){
  this->esFinger = copy.esFinger;
  this->estadias = copy.estadias;
}

 Huesped:: ~Huesped(){
      estadias.clear();
}

Huesped &Huesped::operator=(const Huesped &assign){
  estadias = assign.estadias;
  esFinger = assign.esFinger;
  nombre = assign.nombre;
  email = assign.email;
  contrasena = assign.contrasena;
  return *this;
}

void Huesped::agregarEstadia(Estadia* e){
  estadias.insert(estadias.begin(), e);
  
}

DTHuesped Huesped::getDatatype() {

  DTHuesped* data = new DTHuesped(this->nombre,this->email,this->contrasena,this->esFinger,this->estadias);
  return *data;
}

