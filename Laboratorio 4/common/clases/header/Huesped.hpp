#ifndef _HUESPED_HH_
#define _HUESPED_HH_
#include "Usuario.hpp"
#include "Estadia.hpp"
#include "../../datatype/header/DTHuesped.hpp"
#include <list>
#include <string>

class DTHuesped;
class Estadia;

class Huesped : public Usuario
{
private:
    
    bool esFinger;
    std::list<Estadia*> estadias;
    

public:
    Huesped(std::string nombre, std::string email, std::string contrasena,  bool esFinger, std::list<Estadia*> estadias);
  
    ~Huesped(); 
  

    bool getEsFinger();
    std::list<Estadia*> getEstadias();
  
    void setEsFinger(bool esFinger);
    void setEstadias(std::list<Estadia*> estadias);
    
    //Metodos
    void agregarEstadia(Estadia* e); 
    DTHuesped getDatatype();


    
};

#endif