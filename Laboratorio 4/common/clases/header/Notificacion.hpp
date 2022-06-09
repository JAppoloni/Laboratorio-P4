#ifndef _HUESPED_HH_
#define _HUESPED_HH_

#include "Usuario.hpp"
#include "Estadia.hpp"
#include "../../datatype/header/DTNotificacion.hpp"
#include <list>
#include <string>

class DTNotificacion;

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