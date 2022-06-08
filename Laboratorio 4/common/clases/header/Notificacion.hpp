#ifndef _NOTIFICACION_HH_
#define _NOTIFICACION_HH_

#include "Usuario.hpp"
#include "Estadia.hpp"
#include "../../datatype/header/DTNotificacion.hpp"
#include <list>
#include <string>

class Notificacion{
  private: 
  std::string autor;
	std::string comentario;
	int puntaje;

  public:

  Notificacion(std::string autor,	std::string comentario,int puntaje);
  void set(std::string autor);
  DTNotificacion getDatatype();



};

#endif