#ifndef _DTRESERVAINDIVIDUAL_HH_
#define _DTRESERVAINDIVIDUAL_HH_

#include "DTReserva.hpp"

class DTReservaIndividual : public DTReserva {
private:
    bool pagado;

public:
   
    bool getPagado();
    DTReservaIndividual(const DTReservaIndividual& );
    DTReservaIndividual (int, DTFecha, DTFecha, EstadoReserva, float, int, bool);
    virtual std::ostream&  operator<<(std::ostream &o);
};



#endif
