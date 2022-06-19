#ifndef _RESERVAINDIVIDUAL_HH_
#define _RESERVAINDIVIDUAL_HH_

#include "Reserva.hpp"

class ReservaIndividual : public Reserva
{
private:
    bool pago;
    Huesped *huesped;

public:
    ReservaIndividual();
    ReservaIndividual(
        int codigo,
        DTFecha checkIn,
        DTFecha checkOut,
        EstadoReserva estado,
        Habitacion *habitacionReservada,
        Huesped *huesped,
        bool pago);
    float calcularCosto();

    Huesped *getHuesped();
    void setHuesped(Huesped *huesped);

    bool getPago();
    void setPago(bool pago);

    ~ReservaIndividual();
};

#endif
