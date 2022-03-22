#ifndef _DTHABITACION_HH_
#define _DTHABITACION_HH_

class DTHabitacion
{
private:
    int numero;
    float precio;
    int capacidad;

public:
    void imprimir();

    int getnumero();
    float getprecio();
    int getcapacidad();

      
    DTHabitacion(int, float, int);
};

#endif