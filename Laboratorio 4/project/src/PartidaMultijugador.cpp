#include "../include/PartidaMultijugador.hpp"
#include "../include/ControladorUsuarios.hpp"
#include "../include/ControladorVideojuegos.hpp"

PartidaMultijugador::PartidaMultijugador(DtPartidaMultijugador DtMulti,
                                         Jugador* jug,
                                         Videojuego* juego)
    : Partida(DtMulti.getFechaHora(),
              DtMulti.getId(),
              jug,
              DtMulti.getVideojuego(),
              juego) {
    this->trasmitidaEnVivo = DtMulti.getEsTrasmitida();
    for (auto it : DtMulti.getJugadores()) {
        PMJ* pm = new PMJ(this, it);
        this->participantes.insert(pm);
    }
}

bool PartidaMultijugador::getTransmitidaEnVivo() {
    return this->trasmitidaEnVivo;
}

std::set<PMJ*> PartidaMultijugador::getParticipantes() {
    return this->participantes;
}


void PartidaMultijugador::unlinkJugM(){
    this->getInicia()->unlinkInicia(this);
    for(auto i = participantes.begin(); i != participantes.end(); i++){
        (*i)->getJugador()->unlinkPMJ(*i);
    }
}

PartidaMultijugador::~PartidaMultijugador() {
    for (std::set<PMJ*>::iterator it = this -> participantes.begin(); it != this -> participantes.end(); it++) {
        delete (*it);
    }
}