#include "../include/DtEstadistica.hpp"

DtEstadistica::DtEstadistica(std::string name, double dato) {
    this->name = name;
    this->dato = dato;
}

std::string DtEstadistica::getName() {
    return name;
}

double DtEstadistica::getDato() {
    return dato;
}

bool DtEstadistica::operator<(const DtEstadistica& param) const {
    DtEstadistica copy_param = param;
    DtEstadistica copy_this = *this;
    return (copy_this.getDato() < copy_param.getDato());
}