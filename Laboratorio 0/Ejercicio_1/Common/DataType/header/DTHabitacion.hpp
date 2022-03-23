#ifndef _DTHABITACION_HH_
#define _DTHABITACION_HH_

#include <iostream>

class DTHabitacion {
private:
    int numero;
    float precio;
    int capacidad;

public:
    DTHabitacion(int, float, int);

    int getNumero();
    float getPrecio();
    int getCapacidad();
};

std::ostream& operator<<(std::ostream& out, DTHabitacion &habitacion);

#endif
