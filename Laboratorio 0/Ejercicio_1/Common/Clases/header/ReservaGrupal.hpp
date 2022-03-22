#ifndef _RESERVAGRUPAL_HH_
#define _RESERVAGRUPAL_HH_

#include "Reserva.hpp"

class ReservaGrupal : public Reserva {
public:
    float calcularCosto();
    Huesped** listaHuesped;

    ReservaGrupal(
        int codigo, 
        DTFecha checkIn,
        DTFecha checkOut, 
        EstadoReserva estado,
        Habitacion* habitacionReservada,
        Huesped **Huesped);

    Huesped** getListaHuesped();
    void setListaHuesped(Huesped**listaHuesped);

    ~ReservaGrupal();
};

#endif
