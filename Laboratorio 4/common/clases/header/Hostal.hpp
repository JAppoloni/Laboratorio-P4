#ifndef _HOSTAL_HH_
#define _HOSTAL_HH_
#include <string>
#include "Estadia.hpp"
#include "Habitacion.hpp"
#include "Calificacion.hpp"
#include "../../datatype/header/DTHostal.hpp"
#include "../../datatype/header/DTCalificacion.hpp"
#include <list> 

class Hostal
{
private:
   std::string nombre;
   std::string direccion;
   std::string telefono;
   std::list<Habitacion*> listaHabitaciones;
   std::list<Calificacion*> listaCalificaciones;


public:
  Hostal(std::string nombre, std::string direccion, std::string telefono, std::list<Habitacion*> listaHabitaciones,std::list<Calificacion*> listaCalificaciones); 
  Hostal( Hostal &copy); 
  ~Hostal(); 
    
  std::string getNombre(); 
  std::string getDireccion(); 
  std::string getTelefono(); 
  std::list<Habitacion*> getHabitaciones();
  std::list<Calificacion*> getCalificaciones();
  void setNombre(std::string nombre); 
  void setDireccion(std::string direccion); 
  void setTelefono(std::string telefono); 
  void setHabitaciones(std::list<Habitacion*> habitaciones);
  void setCalificaciones(std::list<Calificacion*> calificaciones);

  Hostal & operator=(const Hostal &assign);
  bool operator==(const Hostal & assign);
   
   std::list<DTCalificacion> obtenerCalificaciones(); 
   DTHostal getDatatype();
   // getDatatypeCompleto(): DTHostal que es?
   std::list<int> obtenerComentariosSinResponder(); //set(<idCalificacion>)


};

#endif