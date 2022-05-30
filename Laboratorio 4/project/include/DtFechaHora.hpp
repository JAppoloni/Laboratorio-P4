
#ifndef DTFECHAHORA_HPP
#define DTFECHAHORA_HPP

#include "TiposSuscripcion.hpp"
#include <iostream>
#include <stdexcept>

class DtFechaHora {
   private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

   public:
    DtFechaHora() = default;
    ~DtFechaHora() = default;
    DtFechaHora(int D, int M, int A, int H, int Min);

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    bool operator==(const DtFechaHora&);
    bool operator<(const DtFechaHora&);
    DtFechaHora operator+(const TiposSuscripcion);
    float operator-(const DtFechaHora&);
    friend std::ostream& operator<<(std::ostream& os, DtFechaHora&);
};

#endif