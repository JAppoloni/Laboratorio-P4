#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include <string>
#include "DtFechaHora.hpp"

class Jugador;
class Videojuego;

class Partida {
   private:
    DtFechaHora fechaInicio;
    float duracion;
    int idPartida;
    bool terminada;
    std::string Nombrevideojuego;
    Jugador* inicia;  // multiplicidad : 1
    Videojuego* juego;

   protected:
    Partida(DtFechaHora, int, Jugador*, std::string, Videojuego*);

   public:
    virtual ~Partida() = default;

    void setDuracion(float);
    void setTerminada(bool);

    DtFechaHora getFechaInicio();
    float getDuracion();
    int getIdPartida();
    bool getTerminada();
    Jugador* getInicia();
    std::string getVideojuego();
    Videojuego* getVideojuegoObj();
};

#endif
