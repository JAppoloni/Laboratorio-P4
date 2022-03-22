#ifndef _DTRESERVA_HH_
#define _DTRESERVA_HH_

#include "DTFecha.hpp"
#include "EstadoReserva.hpp"
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
    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    virtual float getCosto();
    int getHabitacion();
    DTReserva (int, DTFecha, DTFecha, EstadoReserva, float, int); 
    virtual  std::ostream&  operator<< (std::ostream &o) = 0;
  
};

#endif

