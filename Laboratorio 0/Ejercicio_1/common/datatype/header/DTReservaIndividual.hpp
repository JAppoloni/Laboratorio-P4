#ifndef _DTRESERVAINDIVIDUAL_HH_
#define _DTRESERVAINDIVIDUAL_HH_

#include "DTReserva.hpp"
class DTReservaIndividual : public DTReserva
{
private:
    bool pago;

public:
    bool getPago();
    DTReservaIndividual(const DTReservaIndividual &);
    DTReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, int habitacion, bool pago);
    virtual std::ostream &operator<<(std::ostream &o);
};

#endif
