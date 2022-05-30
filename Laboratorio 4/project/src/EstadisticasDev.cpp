#include "../include/EstadisticasDev.hpp"

std::set<Estadistica*> EstadisticasDev::getEst() {
    return setEst;
}

void EstadisticasDev::addEstadistica(Estadistica* est) {
    if (!setEst.count(est)) {  // solo agrega la estadistica si la misma no esta
                               // en el set.
        setEst.insert(est);
    }
}