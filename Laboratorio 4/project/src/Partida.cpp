#include "../include/Partida.hpp"
#include "../include/ControladorUsuarios.hpp"
#include "../include/Jugador.hpp"
#include "../include/Videojuego.hpp"

Partida::Partida(DtFechaHora fecha,
                 int id,
                 Jugador* jug,
                 std::string vid,
                 Videojuego* juego) {
    this->fechaInicio = fecha;
    this->duracion = 0;
    this->idPartida = id;
    this->terminada = false;
    this->Nombrevideojuego = vid;
    this->inicia = jug;
    this->juego = juego;
}

void Partida::setDuracion(float dur) {
    duracion = dur;
}
void Partida::setTerminada(bool term) {
    terminada = term;
}

DtFechaHora Partida::getFechaInicio() {
    return fechaInicio;
}

float Partida::getDuracion() {
    return duracion;
}

int Partida::getIdPartida() {
    return idPartida;
}

bool Partida::getTerminada() {
    return terminada;
}

Jugador* Partida::getInicia() {
    return inicia;
}

std::string Partida::getVideojuego() {
    return Nombrevideojuego;
}

Videojuego* Partida::getVideojuegoObj() {
    return juego;
}