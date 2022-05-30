#ifndef PUNTUA_HPP
#define PUNTUA_HPP

#include "Videojuego.hpp"

class Puntua {
   private:
    Videojuego* videojuego;
    int puntaje;
    Jugador* jugador;

   public:

    Puntua(Videojuego*, int, Jugador*);
    ~Puntua() = default;

    void setPuntaje(int);
    Videojuego* getVideojuego();
    int getPuntaje();
    Jugador* getJugador();
};

#endif