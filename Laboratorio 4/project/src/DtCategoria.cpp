#include "../include/DtCategoria.hpp"

DtCategoria::DtCategoria(std::string nombre,
                         std::string descripcion,
                         TipoCat tipo) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
}

std::string DtCategoria::getNombre() {
    return nombre;
}

std::string DtCategoria::getDescripcion() {
    return descripcion;
}

TipoCat DtCategoria::getTipo() {
    return tipo;
}

bool DtCategoria::operator<(const DtCategoria& param) const {
    return true;
}