#ifndef _HOSTAL_HH_
#define _HOSTAL_HH_
#include <string>
#include "Estadia.hpp"
#include "Habitacion.hpp"
#include "Calificacion.hpp"
#include "../../datatype/header/DTHostal.hpp"
#include "../../datatype/header/DTCalificacion.hpp"
#include <list> 


using namespace std;

class DTHostal;

class Hostal
{
private:
   std::string nombre;
   std::string direccion;
   std::string telefono;
   std::list<Habitacion*> listaHabitaciones;
   std::list<Calificacion*> listaCalificaciones;


public:
  Hostal(std::string nombre, std::string direccion, std::string telefono); 
  ~Hostal(); 
    
  std::string getNombre(); 
  std::string getDireccion(); 
  std::string getTelefono(); 
  std::list<Habitacion*> getHabitaciones();
  std::list<Calificacion*> getCalificaciones();
  void setNombre(std::string nombre); 
  void setDireccion(std::string direccion); 
  void setTelefono(std::string telefono); 
  void agregarHabitacion(Habitacion * habitacion);
  Habitacion * getHabitacion(int num);


  bool operator==(const Hostal & assign);
   
   std::list<DTCalificacion> obtenerCalificaciones(); 
   DTHostal getDatatype();
   // getDatatypeCompleto(): DTHostal 
   std::list<int> obtenerComentariosSinResponder(); //set(<IDReserva>)


};

#endif