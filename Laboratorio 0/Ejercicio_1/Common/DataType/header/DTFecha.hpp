#ifndef _DTFECHA_HH_
#define _DTFECHA_HH_

class DTFecha {
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
    DTFecha();
     bool operator ==(const DTFecha &fecha) const;
     DTFecha& operator = (const DTFecha &fecha);

};

#endif