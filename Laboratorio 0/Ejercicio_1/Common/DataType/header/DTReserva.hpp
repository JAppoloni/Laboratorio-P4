#ifndef _DTRESERVA_HH_
#define _DTRESERVA_HH_

#include "DTFecha.hpp"
#include "EstadoReserva.hpp"
#include <iostream>

class DTReserva
{
protected:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    int costo;
    int habitacion;

public:
    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    float getCosto();
    int getHabitacion();
    DTReserva();
    DTReserva(int, DTFecha, DTFecha, EstadoReserva, float, int);
    virtual std::ostream &operator<<(std::ostream &o)=0;
};

#endif
