#ifndef _HABITACION_HH_
#define _HABITACION_HH_

#include "Reserva.hpp"

class Habitacion
{
private:
    int numero;
    float precio;
    int capacidad;
    Reserva *listaReservas;

public:
    void imprimir();

    int getNumero();
    float getPrecio();
    int getCapacidad();
    Reserva *getListaReservas();

    void setListaReservas(Reserva *listaReservas);
    void setNumero(int numero);
    void setPrecio(float precio);
    void setCapacidad(int capacidad);

    Habitacion();
    Habitacion(int numero, float precio, int capacidad, Reserva *listaReservas);
    ~Habitacion();
};

#endif
