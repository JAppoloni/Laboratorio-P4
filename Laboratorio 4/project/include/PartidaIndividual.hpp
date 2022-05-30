#ifndef PARTIDAINDIVIDUAL_HPP
#define PARTIDAINDIVIDUAL_HPP

#include <string>

#include "DtPartidaIndividual.hpp"
#include "Partida.hpp"
#include "Videojuego.hpp"

class PartidaIndividual : public Partida {
   private:
    bool continuaPartida;
    PartidaIndividual* continuacion;

   public:
    PartidaIndividual(
        DtPartidaIndividual,
        Jugador*,
        PartidaIndividual*,
        Videojuego*);  // En el constructor setear continuacion==NULL

    ~PartidaIndividual() = default;

    bool getContinuaPartida();
    PartidaIndividual* getContinuacion();
};

#endif