#ifndef _DTRESERVAGRUPAL_HH_
#define _DTRESERVAGRUPAL_HH_

//#define MAX_HUESPEDES 100 // MAX_HUESPEDES = ? Val También está en Reserva.h

#include "DTReserva.hpp"
#include "DTHuesped.hpp"
#include "Constantes.hpp"

class DTReservaGrupal : public DTReserva {
private:
    DTHuesped huespedes[MAX_HUESPEDES];

public:
    std::ostream virtual operator<<(std::ostream &out);

    DTHuesped* gethuespedes();

    DTReservaGrupal(int, DTFecha, DTFecha, EstadoReserva, float, int, DTHuesped[]);
};

#endif
