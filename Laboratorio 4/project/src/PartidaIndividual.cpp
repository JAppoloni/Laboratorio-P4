#include "../include/PartidaIndividual.hpp"
#include "../include/ControladorUsuarios.hpp"
#include "../include/ControladorVideojuegos.hpp"

PartidaIndividual::PartidaIndividual(DtPartidaIndividual DtIndiv,
                                     Jugador* jug,
                                     PartidaIndividual* cont,
                                     Videojuego* juego)
    : Partida(DtIndiv.getFechaHora(),
              DtIndiv.getId(),
              jug,
              DtIndiv.getVideojuego(),
              juego) {
    this->continuaPartida = DtIndiv.getEsContinuacion();
    this->continuacion = cont;
}

bool PartidaIndividual::getContinuaPartida() {
    return this->continuaPartida;
}

PartidaIndividual* PartidaIndividual::getContinuacion() {
    return this->continuacion;
}