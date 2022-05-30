#include <set>
#include <string>
#include "Estadistica.hpp"

#ifndef HORASTOTALES_HPP
#define HORASTOTALES_HPP

class HorasTotalesJuego : public Estadistica {
   public:
    HorasTotalesJuego(std::string name, std::string desc);
    ~HorasTotalesJuego() = default;
    double getDato(Videojuego*);
};

#endif