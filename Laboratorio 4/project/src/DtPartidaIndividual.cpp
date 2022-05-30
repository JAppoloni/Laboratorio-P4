#include "../include/DtPartidaIndividual.hpp"

DtPartidaIndividual::DtPartidaIndividual(int id,
                                         DtFechaHora fechaHora,
                                         std::string videojuego,
                                         double duracion,
                                         std::string creador,
                                         bool terminada,
                                         int idVideojuego,
                                         bool esContinuacion,
                                         int idCont)
    : DtPartida(id,
                fechaHora,
                videojuego,
                duracion,
                creador,
                terminada,
                idVideojuego) {
    this->esContinuacion = esContinuacion;
    this->idCont = idCont;
}

bool DtPartidaIndividual::getEsContinuacion() {
    return esContinuacion;
}

int DtPartidaIndividual::getIdCont() {
    return idCont;
}

bool DtPartidaIndividual::operator<(const DtPartidaIndividual& Part) const {
    DtPartidaIndividual copy = Part;
    DtPartidaIndividual copy_this = *this;
    return (copy_this.getFechaHora() < copy.getFechaHora());
}