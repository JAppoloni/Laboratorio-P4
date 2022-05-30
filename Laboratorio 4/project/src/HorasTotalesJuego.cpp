#include "../include/HorasTotalesJuego.hpp"

HorasTotalesJuego::HorasTotalesJuego(std::string name, std::string desc)
    : Estadistica(name, desc) {}

double HorasTotalesJuego::getDato(Videojuego* vj) {
    return vj->getHorasDeJuego();
}