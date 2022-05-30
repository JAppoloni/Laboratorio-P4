#ifndef ESTADISTICAS_DEV_HPP
#define ESTADISTICAS_DEV_HPP

#include <set>
#include "Estadistica.hpp"

class Estadistica;

class EstadisticasDev {
   private:
    std::set<Estadistica*> setEst;

   public:
    EstadisticasDev() = default;

    ~EstadisticasDev() = default;

    std::set<Estadistica*> getEst();
    void addEstadistica(Estadistica*);
};

#endif