#ifndef _DTRESERVAGRUPAL_HH_
#define _DTRESERVAGRUPAL_HH_

#include "DTReserva.h"

class DTReservaIndividual : public DTReserva
{

private:
    bool pagado;

public:
    std::ostream virtual operator<<(std::ostream &out);

    bool getPagado();

    DTReservaIndividual(int, DTFecha, DTFecha, EstadoReserva, float, int, bool);
};

#endif
