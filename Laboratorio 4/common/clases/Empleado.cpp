#include "header/Empleado.hpp"
#include "header/Estadia.hpp"
#include "header/Huesped.hpp"
#include <iostream>
#include <string>

Empleado::Empleado(std::string nombre, std::string email, std::string contrasena, Cargo cargo) : Usuario(nombre, email, contrasena)
{
  this->cargo = cargo;
  this->hostal = nullptr;
}

std::list<Calificacion *> Empleado::getNotificaciones()
{
  return Notificaciones;
}

void Empleado::setNotificaciones(std::list<Calificacion *> pNotificaciones)
{
  Notificaciones = pNotificaciones;
}

Cargo Empleado::getCargo()
{
  return this->cargo;
}

void Empleado::setCargo(Cargo cargo)
{
  this->cargo = cargo;
}

std::list<Comentario *> Empleado::getComentarios()
{
  return this->Comentarios;
}

void Empleado::setComentarios(std::list<Comentario *> comentarios)
{
  Comentarios = comentarios;
}

Hostal *Empleado::getHostal()
{
  return hostal;
}

void Empleado::setHostal(Hostal *hostal)
{
  this->hostal = hostal;
}

Empleado::~Empleado()
{
  hostal = nullptr;
  delete hostal;
  Comentarios.clear();
}

Empleado &Empleado::operator=(const Empleado &assign)
{
  nombre = assign.nombre;
  email = assign.email;
  contrasena = assign.contrasena;
  cargo = assign.cargo;
  Comentarios = assign.Comentarios;
  return *this;
}

DTEmpleado Empleado::getDatatype()
{
  // DTEmpleado data = DTEmpleado(nombre, email, contrasena, cargo, Comentarios, hostal);
  return DTEmpleado(nombre, email, contrasena, cargo);
}

void Empleado::agregarNotificacion(Calificacion *c)
{
  Notificaciones.push_front(c);
}

void Empleado::agregarComentario(std::string comentario, Calificacion *c)
{
  Comentario * com = new Comentario(comentario, c);
  this->Comentarios.push_back(com);
  c->setRespuestaComentario(com);
}

std::list<DTCalificacion> Empleado::obtenerComentariosSinResponder() // Esta Operación no es del Controlador??????
{
  std::list<DTCalificacion> idComentarios;

  // for (std::list<Comentario *>::iterator it = Comentarios.begin(); it != Comentarios.end(); ++it)
  // {
  //   Comentario *com = *it;
  //   if (!com->getCalificacionComentario()->estaResponida())
  //     idComentarios.insert(com->getCalificacionComentario()->getDataType());
  // }
  return idComentarios;
}

DTHostal Empleado::obtenerHostal()
{
  return DTHostal(this->getHostal()->getNombre(), this->getHostal()->getDireccion(), this->getHostal()->getTelefono());
}

void Empleado::eliminarNotificacion(Calificacion *c){
 Notificaciones.remove(c);
}

void Empleado::eliminarNotificaciones(){
 Notificaciones.clear();
}