#ifndef _EMPLEADO_HH_
#define _EMPLEADO_HH_

#include "Usuario.hpp"
#include "Cargo.hpp"
#include "Notificacion.hpp"
#include "Comentario.hpp"
#include "Calificacion.hpp"
#include "../../datatype/header/DTEmpleado.hpp"

#include <set>
#include <string>

class Empleado : public Usuario
{
private:
    Cargo cargo;
    //hostal?
    std::list<Notificacion*> Notificaciones;
    std::list<Comentario*> Comentarios;
  
public:


  Empleado(std::string nombre, std::string email,  std::string contrasena, Cargo cargo,std::list<Notificacion*> notificaciones, std::list<Comentario*> comentarios  );
  Empleado( Empleado &copy);
  Cargo getCargo();
  void setCargo(Cargo cargo); 
  std::list<Notificacion*> getNotificaciones();
  void setNotificaciones(std::list<Notificacion*> notificaciones );
  std::list<Comentario*> Empleado::getComentarios();
  void setComentarios(std::list<Comentario*> comentarios);

  ~Empleado();
  Empleado & operator=(const Empleado &assign);

  void agregarNotificacion( Calificacion c);
  void agregarComentario(std::string comentario, Calificacion* c);
  std::list<DTNotificacion> listarNotificaciones();
  std::set<int> obtenerComentariosSinResponder(); //ids
  DTEmpleado getDatatype(); 

//Metodos
/*
  DTHostal obtenerHostal(); 
  
  

*/


};

#endif