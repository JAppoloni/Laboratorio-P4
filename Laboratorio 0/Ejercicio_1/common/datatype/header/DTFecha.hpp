#ifndef _DTFECHA_HH_
#define _DTFECHA_HH_

#include <iostream>

class DTFecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha(int dia, int mes, int anio);
    void imprimir();

    int getDia();
    int getMes();
    int getAnio();
    int calcularDias(DTFecha fchAComparar);

    bool operator!=(const DTFecha &) const;
    bool operator==(const DTFecha &) const;
    bool operator>=(const DTFecha &) const;
    bool operator<=(const DTFecha &) const;
    bool operator>(const DTFecha &) const;
    bool operator<(const DTFecha &) const;
};

std::ostream &operator<<(std::ostream &out, DTFecha fecha);

#endif
