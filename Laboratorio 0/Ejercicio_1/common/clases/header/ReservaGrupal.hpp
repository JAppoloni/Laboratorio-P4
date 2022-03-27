#ifndef _RESERVAGRUPAL_HH_
#define _RESERVAGRUPAL_HH_

#include "Reserva.hpp"

class ReservaGrupal : public Reserva
{
public:

    ReservaGrupal(
        int codigo,
        DTFecha checkIn,
        DTFecha checkOut,
        EstadoReserva estado,
        Habitacion *habitacionReservada,
        Huesped **Huesped);

    float calcularCosto();
    Huesped **listaHuesped;
    Huesped **getListaHuesped();
    void setListaHuesped(Huesped **listaHuesped);

    ~ReservaGrupal();
};

#endif
