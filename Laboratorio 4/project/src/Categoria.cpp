#include "../include/Categoria.hpp"

Categoria::Categoria(std::string n, std::string d) {
    this->nombre = n;
    this->descripcion = d;
}

std::string Categoria::getNombre() {
    return nombre;
}
std::string Categoria::getDescripcion() {
    return descripcion;
}