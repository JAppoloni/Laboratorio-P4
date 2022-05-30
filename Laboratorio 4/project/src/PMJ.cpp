#include "../include/PMJ.hpp"
#include "../include/ControladorUsuarios.hpp"
#include "../include/PartidaMultijugador.hpp"

PMJ::PMJ(PartidaMultijugador* p, std::string s) {
    this->partidaM = p;
    this->salio = false;
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    this->jugador = cu->buscarJugador(s);
    this->jugador->addPMJ(this);
}

void PMJ::setHoraAbandono(DtFechaHora fh) {
    this->horaAbandono = fh;
    this->salio = true;
}

DtFechaHora PMJ::getHoraAbandono() {
    return this->horaAbandono;
}

PartidaMultijugador* PMJ::getPartidaM() {
    return this->partidaM;
}

Jugador* PMJ::getJugador() {
    return this->jugador;
}

bool PMJ::getSalida() {
    return salio;
}