#include "header/Hostal.hpp"
#include <iostream>
#include <string>

std::string Hostal::getNombre()
{
    return this->nombre;
}
void Hostal::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

std::string Hostal::getDireccion()
{
    return this->direccion;
}
void Hostal::setDireccion(std::string direccion)
{
    this->direccion = direccion;
}

std::string Hostal::getTelefono()
{
    return this->telefono;
}
void Hostal::setTelefono(std::string telefono)
{
    this->telefono = telefono;
}


std::list<Habitacion *> Hostal::getHabitaciones()
{
    return this->listaHabitaciones;
}

std::list<Calificacion *> Hostal::getCalificaciones()
{
    return this->listaCalificaciones;
}

Hostal::Hostal(std::string nombre, std::string direccion, std::string telefono)
{
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
}

Hostal::~Hostal()
{
    listaHabitaciones.clear();
    listaCalificaciones.clear();
}

bool Hostal::operator==(const Hostal &hostal)
{
    return (nombre == hostal.nombre && direccion == hostal.direccion && telefono == hostal.telefono);
}


std::list<int> Hostal::obtenerComentariosSinResponder()
{
    std::list<int> idComentarios = {};
    std::list<Calificacion*>::iterator it;
    for (it = listaCalificaciones.begin(); it != listaCalificaciones.end(); ++it) {
           Calificacion* c = *it;
        if (!(c->estaResponida())) {
            int id = c->obtenerID();
            idComentarios.insert(idComentarios.begin(), id);
        }
    }
    return idComentarios;
}

std::list<DTCalificacion> Hostal::obtenerCalificaciones(){
  std::list<DTCalificacion> calificaciones;// {};
   std::list<Calificacion*>::iterator it;
  for (it = listaCalificaciones.begin(); it != listaCalificaciones.end(); ++it) {
    Calificacion* c = *it;
    calificaciones.insert(calificaciones.end(), c->getDataType());
  }
  return calificaciones;
}


DTHostal Hostal::getDatatype()
{
    DTHostal data =   DTHostal(this->nombre, this->direccion,this->telefono);
    return data;
    
}

void Hostal::agregarHabitacion(Habitacion * habitacion)
{
    listaHabitaciones.push_back(habitacion);
}

Habitacion * Hostal::getHabitacion(int num)
{
    for(list<Habitacion*>::iterator it = listaHabitaciones.begin(); it != listaHabitaciones.end(); ++it){
        if((*it)->getNumero() == num){
            return *it;
        };
    };
    return nullptr;
}
  