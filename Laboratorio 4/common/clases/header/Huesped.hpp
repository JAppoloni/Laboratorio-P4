#ifndef _HUESPED_HH_
#define _HUESPED_HH_

#include "Usuario.hpp"
#include "Estadia.hpp"
#include "../../datatype/header/DTHuesped.hpp"
#include <list>
#include <string>

class Huesped : public Usuario
{
private:
    
    bool esFinger;
    std::list<Estadia*> estadias;
    

public:
    Huesped(std::string, std::string, std::string,  bool, std::list<Estadia*>);
    Huesped(const Huesped &copy); 

    ~Huesped(); 
    Huesped & operator=(const Huesped &assign); 
   // bool operator==(const Huesped &c) const; 

    bool getEsFinger();
    std::list<Estadia*> getEstadias();
  
    void setEsFinger(bool esFinger);
    void setEstadias(std::list<Estadia*> estadias);
    
    //Metodos
    void agregarEstadia(Estadia* e); 
    DTHuesped getDatatype();


    
};

#endif