#include "header/Hostal.hpp"
#include <iostream>
#include <string>
#include <list>

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
    for (auto it : this->listaHabitaciones)
    {
        if (it != nullptr)
        {
            delete it;
            it = nullptr;
        }
    }
    listaHabitaciones.clear();

    for (auto it : this->listaCalificaciones)
    {
        if (it != nullptr)
        {
            it = nullptr;
        }
    }
    listaCalificaciones.clear();
}

bool Hostal::operator==(const Hostal &hostal)
{
    return (nombre == hostal.nombre);
}

Hostal &Hostal::operator=(const Hostal &assign)
{
    this->nombre = assign.nombre;
    this->direccion = assign.direccion;
    this->telefono = assign.telefono;
    this->listaHabitaciones = assign.listaHabitaciones;
    this->listaCalificaciones = assign.listaCalificaciones;
    return *this;
}

std::set<DTCalificacion*> Hostal::obtenerComentariosSinResponder()
{
    std::set<DTCalificacion*> res;
    std::list<Calificacion *>::iterator it;
    for (it = listaCalificaciones.begin(); it != listaCalificaciones.end(); ++it)
    {
        if((*it) == nullptr){
            break;
        }
        Calificacion *c = *it;
        if (!(c->estaResponida()))
        {
            res.insert(new DTCalificacion((*it)->obtenerID(), (*it)->getEstadiaComentario()->getHuespedEstadia()->getEmail(), (*it)->getPuntaje(), (*it)->getFecha(), (*it)->getComentario()));
        };
    };
    return res;
}

std::list<DTCalificacion> Hostal::obtenerCalificaciones()
{
    std::list<DTCalificacion> calificaciones;
    std::list<Calificacion *>::iterator it;
    for (it = listaCalificaciones.begin(); it != listaCalificaciones.end(); ++it)
    {
        Calificacion *c = *it;
        calificaciones.insert(calificaciones.end(), c->getDataType());
    }
    return calificaciones;
}

DTHostal Hostal::getDatatype()
{
    DTHostal data = DTHostal(this->nombre, this->direccion, this->telefono);
    return data;
}

void Hostal::agregarHabitacion(Habitacion *habitacion)
{
    listaHabitaciones.push_back(habitacion);
}

Habitacion *Hostal::getHabitacion(int num)
{
    for (std::list<Habitacion *>::iterator it = listaHabitaciones.begin(); it != listaHabitaciones.end(); ++it)
    {
        if ((*it)->getNumero() == num)
        {
            return *it;
        };
    };
    return nullptr;
}

void Hostal::agregarCalificacion(Calificacion *calificacion)
{
    listaCalificaciones.push_back(calificacion);
}

void Hostal::eliminarCalificacion(Calificacion * calif)
{
    listaCalificaciones.remove(calif);
}