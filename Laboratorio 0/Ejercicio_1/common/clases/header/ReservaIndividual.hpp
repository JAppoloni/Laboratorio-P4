#ifndef _RESERVAINDIVIDUAL_HH_
#define _RESERVAINDIVIDUAL_HH_

#include "Reserva.hpp"

class ReservaIndividual : public Reserva {
private:
    bool pagado;
    Huesped* huesped;

public:
    float calcularCosto();

    bool getPagado();
    void setPagado(bool pagado);

    ReservaIndividual(
        int codigo, 
        DTFecha checkIn, 
        DTFecha checkOut,
        EstadoReserva estado, 
        float costo, 
        Habitacion habitacionReservada, 
        Huesped* huesped, 
        bool pagado);
    ~ReservaIndividual();
};

#endif
