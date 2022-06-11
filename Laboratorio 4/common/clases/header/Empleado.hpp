#ifndef _EMPLEADO_HH_
#define _EMPLEADO_HH_

#include "Usuario.hpp"
#include "Cargo.hpp"
#include "Comentario.hpp"
#include "Hostal.hpp"
#include "Calificacion.hpp"

#include "../../datatype/header/DTEmpleado.hpp"
#include "../../datatype/header/DTHostal.hpp"
#include "../../datatype/header/DTNotificacion.hpp"

#include <set>
#include <string>
#include <list>

class Empleado : public Usuario
{
private:
  Cargo cargo;
  Hostal *hostal;
  std::list<Comentario *> Comentarios;
  std::list<Calificacion *> Notificaciones;

public:
  // Constructores
  Empleado(std::string nombre, std::string email, std::string contrasena, Cargo cargo);

  // getters / setters
  Cargo getCargo();
  void setCargo(Cargo cargo);
  std::list<Comentario *> getComentarios();
  void setComentarios(std::list<Comentario *> comentarios);
  Hostal *getHostal();
  void setHostal(Hostal *hostal);
  std::list<Calificacion *> getNotificaciones();
  void setNotificaciones(std::list<Calificacion *> Notificaciones) ;

  // Destructor
  ~Empleado();

  // Operadores
  Empleado &operator=(const Empleado &assign);
  void agregarNotificacion(Calificacion *c);
  void agregarComentario(std::string comentario, Calificacion *c);

  std::list<Calificacion> listarNotificaciones();
  std::set<DTCalificacion> obtenerComentariosSinResponder();
  DTEmpleado getDatatype();
  DTHostal obtenerHostal();
};

#endif