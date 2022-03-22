#ifndef _RESERVA_HH_
#define _RESERVA_HH_

#include "../../datatype/header/Constantes.hpp"
#include "../../datatype/header/DTFecha.hpp"
#include "../../datatype/header/EstadoReserva.hpp"
#include "Habitacion.hpp"
#include "Huesped.hpp"

class Reserva {
protected:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    Habitacion *habitacionReservada;
    
public:
    Reserva(
        int codigo,
        DTFecha checkIn,
        DTFecha checkOut,
        EstadoReserva estado,
        Habitacion *habitacionReservada);

    virtual float calcularCosto() = 0;  

    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    Habitacion *getHabitacionReservada();

    void setCodigo(int codigo);
    void setCheckIn(DTFecha checkIn);
    void setCheckOut(DTFecha checkOut);
    void setEstado(EstadoReserva estado);
    void setHabitacionReservada(Habitacion *habitacionReservada);
};

#endif
