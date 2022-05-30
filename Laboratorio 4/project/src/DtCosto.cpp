#include "../include/DtCosto.hpp"

DtCosto::DtCosto(double mensual, double trimestral, double anual, double vitalicio) {
    this->mensual = mensual;
    this->trimestral = trimestral;
    this->anual = anual;
    this->vitalicio = vitalicio;
}

double DtCosto::getMensual() {
    return mensual;
}

double DtCosto::getTrimestral() {
    return trimestral;
}

double DtCosto::getAnual() {
    return anual;
}

double DtCosto::getVitalicio() {
    return vitalicio;
}