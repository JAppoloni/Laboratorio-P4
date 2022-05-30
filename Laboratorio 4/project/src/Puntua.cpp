#include "../include/Puntua.hpp"

Puntua::Puntua(Videojuego* vj, int p, Jugador* jug) {
    this -> videojuego = vj;
    this -> puntaje = p;
    this -> jugador = jug;
}

void Puntua::setPuntaje(int p) {
    this -> puntaje = p;
}

Videojuego* Puntua::getVideojuego() {
    return this -> videojuego;
}

int Puntua::getPuntaje(){
    return this->puntaje;
}

Jugador* Puntua::getJugador(){
    return this->jugador;
}