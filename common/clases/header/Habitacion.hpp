#ifndef _HABITACION_HH_
#define _HABITACION_HH_

#include "Hostal.hpp"

class Hostal;

class Habitacion
{
private:
    int numero;
    float precio;
    int capacidad;
    Hostal * hostal;

public:
    Habitacion(int numero, float precio, int capacidad, Hostal * Hostal);

    ~Habitacion();
    void imprimir();
    

    int getNumero();
    float getPrecio();
    int getCapacidad();
    Hostal* getHostal();

    void setNumero(int numero);
    void setPrecio(float precio);
    void setCapacidad(int capacidad);
    void setHostal(Hostal * hostal);
};

#endif