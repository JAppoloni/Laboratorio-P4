#include "../include/DtVideojuego.hpp"

DtVideojuego::DtVideojuego(std::string nombre,
                           std::string descripcion,
                           DtCosto costosPar,
                           std::set<DtCategoria> categoriaGenero,
                           std::set<DtCategoria> categoriaOtros,
                           std::set<DtCategoria> categoriaPlataformas)
    : costos(costosPar) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->categoriaGenero = categoriaGenero;
    this->categoriaOtros = categoriaOtros;
    this->categoriaPlataformas = categoriaPlataformas;
}

std::string DtVideojuego::getNombre() {
    return nombre;
}

std::string DtVideojuego::getDescripcion() {
    return descripcion;
}

DtCosto DtVideojuego::getCostos() {
    return costos;
}

std::set<DtCategoria> DtVideojuego::getCategoriaGenero() {
    return categoriaGenero;
}

std::set<DtCategoria> DtVideojuego::getCategoriaOtros() {
    return categoriaOtros;
}

std::set<DtCategoria> DtVideojuego::getCategoriaPlataformas() {
    return categoriaPlataformas;
}

bool DtVideojuego::operator<(const DtVideojuego& param) const {
    return true;
}