#include "../include/FechaSistema.hpp"

FechaSistema* FechaSistema::instance = nullptr;

FechaSistema* FechaSistema::getInstance() {
    if (instance == nullptr)
        instance = new FechaSistema();
    return instance;
}

void FechaSistema::setFecha(DtFechaHora f) {
    this->fecha = f;
}

DtFechaHora FechaSistema::getFecha() {
    return fecha;
}