#include "header/Huesped.hpp"
#include <iostream>

bool Huesped::getEsFinger()
{
  return this->esFinger;
}

void Huesped::setEsFinger(bool esFinger)
{
  this->esFinger = esFinger;
}

std::list<Estadia *> Huesped::getEstadias()
{
  return this->estadias;
}

void Huesped::setEstadias(std::list<Estadia *> estadias)
{
  this->estadias = estadias;
}

Huesped::Huesped(std::string nombre, std::string email, std::string contrasena, bool esFinger) : Usuario(nombre, email, contrasena)
{
  this->esFinger = esFinger;
}

Huesped::~Huesped()
{
  estadias.clear();
}

void Huesped::agregarEstadia(Estadia *e)
{
  estadias.insert(estadias.begin(), e);
}

DTHuesped Huesped::getDatatype()
{

  return DTHuesped(this->nombre, this->contrasena, this->email, this->esFinger);
}
DTHuesped *Huesped::getDatatypeptr()
{

  return new DTHuesped(this->nombre, this->contrasena, this->email, this->esFinger);
}

void Huesped::elimirarEstadia(Estadia *estadia)
{
  estadias.remove(estadia);
}