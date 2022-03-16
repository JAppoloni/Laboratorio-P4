#ifndef _RESERVA_HH_
#define _RESERVA_HH_

#include "../../datatype/header/Constantes.hpp"
#include "../../datatype/header/DTFecha.hpp"
#include "EstadoReserva.hpp"
#include "Habitacion.hpp"
#include "Huesped.hpp"

class Reserva {
protected:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    Habitacion habitacionReservada;
    Huesped listaHuesped[MAX_HUESPEDES];

public:
    virtual void imprimir();

    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    Habitacion getHabitacionReservada();
    Huesped *getlistaHuesped();

    void setCodigo(int codigo);
    void setCheckIn(DTFecha checkIn);
    void setCheckOut(DTFecha checkOut);
    void setEstado(EstadoReserva estado);
    void setHabitacionReservada(Habitacion habitacionReservada);
    void setlistaHuesped(Huesped listaHuesped[]);

    Reserva();
    Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, Habitacion habitacionReservada, Huesped *Huesped);
    ~Reserva();

    virtual float calcularCosto() = 0;
};

#endif