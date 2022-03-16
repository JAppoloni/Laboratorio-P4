#ifndef _HABITACION_HH_
#define _HABITACION_HH_

class Habitacion
{
private:
    int numero;

    float precio;

    int capacidad;

public:
    void imprimir();


    int getNumero();
    float getPrecio();
    int getCapacidad();

    void setNumero(int numero);
    void setPrecio(float precio);
    void setCapacidad(int capacidad);

    Habitacion();
    Habitacion(int numero, float precio, int capacidad);
    ~Habitacion();
};
#endif