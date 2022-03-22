#ifndef _DTRESERVAGRUPAL_HH_
#define _DTRESERVAGRUPAL_HH_

#include "DTReserva.hpp"
#include "DTHuesped.hpp"
#include "Constantes.hpp"

class DTReservaGrupal : public DTReserva {
private:
    DTHuesped huespedes[MAX_HUESPEDES];
    
public:
    
  DTHuesped* gethuespedes();
  DTReservaGrupal(int, DTFecha, DTFecha, EstadoReserva, float, int,int, DTHuesped[]);
  virtual std::ostream&  operator<<(std::ostream &o);
  
};

#endif
