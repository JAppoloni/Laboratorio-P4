#ifndef _DTRESERVA_HH_
#define _DTRESERVA_HH_

#include "DTFecha.hpp"
#include "../../clases/header/EstadoReserva.hpp"
#include <iostream>

class DTReserva {
private:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    float costo;
    int habitacion;

public:
    std::ostream virtual operator<<(std::ostream &out);

    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    float getCosto();
    int getHabitacion();

    DTReserva(int, DTFecha, DTFecha, EstadoReserva, float, int);
};

#endif
