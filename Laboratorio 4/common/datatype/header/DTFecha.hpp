#ifndef _DTFECHA_HH_
#define _DTFECHA_HH_

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string.h>

class DTFecha
{
private:
    struct tm *fecha;

public:
    DTFecha();
    DTFecha(int min, int hh, int dd, int mm, int yyyy);
    DTFecha(int min, int hh, int dd, int mm, int yyyy, int wday);

    ~DTFecha();

    int getMinutos();
    int getHora();
    int getDia();
    int getMes();
    int getAnio();
    int diferenciaDias(DTFecha fchAComparar);

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
