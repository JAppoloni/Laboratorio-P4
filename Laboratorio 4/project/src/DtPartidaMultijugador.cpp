#include "../include/DtPartidaMultijugador.hpp"
#include "../include/DtFechaHora.hpp"

DtPartidaMultijugador::DtPartidaMultijugador(
    int id,
    DtFechaHora fechaHora,
    std::string videojuego,
    double duracion,
    std::string creador,
    bool terminada,
    int idVideojuego,
    bool esTrasmitida,
    std::set<std::string> jugadoresConectados)
    : DtPartida(id,
                fechaHora,
                videojuego,
                duracion,
                creador,
                terminada,
                idVideojuego) {
    this->esTrasmitida = esTrasmitida;
    this->jugadoresConectados = jugadoresConectados;
}

bool DtPartidaMultijugador::getEsTrasmitida() {
    return esTrasmitida;
}

std::set<std::string> DtPartidaMultijugador::getJugadores() {
    return jugadoresConectados;
}

bool DtPartidaMultijugador::operator<(const DtPartidaMultijugador& Part) const {
    DtPartidaMultijugador copy = Part;
    DtPartidaMultijugador copy_this = *this;
    return (copy_this.getFechaHora() < copy.getFechaHora());
}