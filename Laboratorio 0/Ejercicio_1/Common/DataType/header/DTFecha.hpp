#ifndef _DTFECHA_HH_
#define _DTFECHA_HH_

class DTFecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    void imprimir();

    int getDia();
    int getMes();
    int getAnio();
    int calcularDias(DTFecha fchAComparar);
    DTFecha(int, int, int);

    bool operator!=(const DTFecha &) const;
    bool operator==(const DTFecha &) const;
    bool operator>=(const DTFecha &) const;
    bool operator<=(const DTFecha &) const;
    bool operator>(const  DTFecha &) const;
    bool operator<(const  DTFecha &) const;
};

#endif
