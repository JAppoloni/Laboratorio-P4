#include "header/Empleado.hpp"
#include "header/Estadia.hpp"
#include "header/Huesped.hpp"
#include <iostream>
#include <string>

Empleado::Empleado(std::string nombre, std::string email,  std::string contrasena, Cargo cargo,std::list<Notificacion*> notificaciones, std::list<Comentario*> comentarios,Hostal* hostal):Usuario(nombre,  email, contrasena){ 
  this->cargo = cargo; //ver
  this->Notificaciones = notificaciones;
  this->Comentarios = comentarios;
  this->hostal = hostal;
}

Empleado::Empleado(Empleado &copy){
  this->nombre = copy.getNombre();
  this->email = copy.getEmail();
  this->contrasena = copy.getContrasena();
  this->cargo = copy.getCargo();
  this->Comentarios = copy.getComentarios();
  this->Notificaciones = copy.getNotificaciones();
  this->hostal = copy.getHostal();

}

Cargo Empleado::getCargo(){
  return this->cargo;
}

void Empleado::setCargo(Cargo cargo){
  this->cargo = cargo;
}

std::list<Notificacion*> Empleado::getNotificaciones(){
  return this->Notificaciones;
}

void Empleado::setNotificaciones(std::list<Notificacion*> notificaciones ){
  Notificaciones = notificaciones;
}

std::list<Comentario*> Empleado::getComentarios(){
 return this->Comentarios;
}

void Empleado::setComentarios(std::list<Comentario*> comentarios){
  Comentarios = comentarios;
}

Hostal* Empleado::getHostal(){
  return hostal;
 }

void Empleado::setHostal(Hostal* hostal){
  this->hostal = hostal;
}

Empleado::~Empleado(){
  Notificaciones.clear();
  Comentarios.clear();
}

Empleado &Empleado::operator=(const Empleado &assign)
{
  nombre = assign.nombre;
  email = assign.email;
  contrasena = assign.contrasena;
  cargo = assign.cargo;
  Comentarios = assign.Comentarios;
  Notificaciones = assign.Notificaciones;
  return *this;

}


DTEmpleado Empleado::getDatatype(){
  DTEmpleado data = DTEmpleado(nombre,email,contrasena,cargo,Notificaciones,Comentarios, hostal);
  return data;
}

void Empleado::agregarNotificacion( Calificacion* c){
  //terminar: c->estadia->huesped->nombre?
   
 std::string autor = c->getEstadiaComentario()->obtenerAutor();
  Notificacion n = Notificacion(autor,c->getComentario(), c->getPuntaje());
  Notificacion* notif;
  notif = &n;
  Notificaciones.insert(Notificaciones.begin(),notif);

}

void Empleado::agregarComentario(std::string comentario, Calificacion* c){
  Comentario com = Comentario(comentario, c);
  Comentario* co;
  co = &com;

 this->Comentarios.insert(Comentarios.begin(), co ) ;
}

std::list<DTNotificacion> Empleado::listarNotificaciones(){
  std::list<DTNotificacion> notificaciones = {};
  std::list<Notificacion*>::iterator it;
  for (it = Notificaciones.begin(); it != Notificaciones.end(); ++it) {
    Notificacion* n = *it;
    notificaciones.insert(notificaciones.end(), n->getDatatype());
  }
  return notificaciones;
}

std::set<int> Empleado::obtenerComentariosSinResponder(){
  std::set<int> idComentarios = {};
  std::list<Comentario*>::iterator it;
  for (it = Comentarios.begin(); it != Comentarios.end(); ++it) {
    Comentario* com = *it;
    if (!com->getCalificacionComentario()->estaRespondida())
      idComentarios.insert(com->getCalificacionComentario()->obtenerID());
  }
  return idComentarios;
}

DTHostal Empleado::obtenerHostal(){
  Hostal* h = this->getHostal();
  DTHostal data =  DTHostal(h->getNombre(),h->getDireccion(), h->getTelefono(),h->getHabitaciones(),h->getCalificaciones());
 return data;
  
}








