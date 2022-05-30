#include "../include/DtPartida.hpp"

DtPartida::DtPartida(int id,
                     DtFechaHora fechaHora,
                     std::string videojuego,
                     double duracion,
                     std::string creador,
                     bool terminada,
                     int idVideojuego) {
    this->id = id;
    this->fechaHora = fechaHora;
    this->videojuego = videojuego;
    this->duracion = duracion;
    this->creador = creador;
    this->terminada = terminada;
}

int DtPartida::getId() {
    return id;
}

DtFechaHora DtPartida::getFechaHora() {
    return fechaHora;
}

std::string DtPartida::getVideojuego() const{ 
  return videojuego; 
}

double DtPartida::getDuracion() {
    return duracion;
}

std::string DtPartida::getcreador() {
    return creador;
}

bool DtPartida::getTerminada() {
    return terminada;
}

int DtPartida::getIdVideojuego() {
    return idVideojuego;
}
