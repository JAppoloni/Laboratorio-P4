#ifndef _DTFECHA_HH_
#define _DTFECHA_HH_

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string.h>

class DTFecha
{
private:
    tm fecha;

public:
    DTFecha();
    DTFecha(tm fch);
    DTFecha(const DTFecha &);
    DTFecha(DTFecha *fch);
    DTFecha(int min, int hh, int dd, int mm, int yyyy);
    DTFecha(int min, int hh, int dd, int mm, int yyyy, int wday);

    ~DTFecha();

    int getDweek();
    int getSegundos();
    int getMinutos();
    int getHora();
    int getDia();
    int getMes();
    int getAnio();
    int diferenciaDias(DTFecha fchAComparar);

    DTFecha &operator=(const DTFecha &assign);
    DTFecha operator+(const tm &assign);
    bool operator!=(const DTFecha &) const;
    bool operator==(const DTFecha &) const;
    bool operator>=(const DTFecha &) const;
    bool operator<=(const DTFecha &) const;
    bool operator>(const DTFecha &) const;
    bool operator<(const DTFecha &) const;

    void Imprimir();
};

std::ostream &operator<<(std::ostream &out, DTFecha fecha);

#endif
