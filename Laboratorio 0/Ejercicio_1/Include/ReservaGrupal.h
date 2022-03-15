#ifndef _RESERVAGRUPAL_HH_
#define _RESERVAGRUPAL_HH_

#include "Reserva.h"

class ReservaGrupal : public Reserva
{

public:
    virtual void imprimir();
    virtual float calcularCosto();


    ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, Habitacion habitacionReservada, Huesped Huesped[], bool pagado);
    ~ReservaGrupal();
};

#endif
