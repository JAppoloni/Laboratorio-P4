#ifndef _RESERVAINDIVIDUAL_HH_
#define _RESERVAINDIVIDUAL_HH_

#include "Reserva.h"

class ReservaIndividual : public Reserva
{

private:
    bool pagado;

public:
    virtual void imprimir();
    virtual float calcularCosto();

    bool getPagado();
    void setPagado(bool pagado);


    ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, Habitacion habitacionReservada, Huesped Huesped, bool pagado);
    ~ReservaIndividual();
};

#endif
