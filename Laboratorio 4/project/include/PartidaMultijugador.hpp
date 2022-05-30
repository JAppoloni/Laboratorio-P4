#ifndef PARTIDAMULTIJUGADOR_HPP
#define PARTIDAMULTIJUGADOR_HPP

#include <set>
#include <string>
#include "DtPartidaMultijugador.hpp"
#include "Jugador.hpp"
#include "Partida.hpp"

class PMJ;

class PartidaMultijugador : public Partida {
   private:
    bool trasmitidaEnVivo;
    std::set<PMJ*> participantes;

   public:
    PartidaMultijugador(DtPartidaMultijugador, Jugador*, Videojuego*);

    ~PartidaMultijugador();

    bool getTransmitidaEnVivo();
    void unlinkJugM();
    // Devuelve pseudoatributo participantes
    std::set<PMJ*> getParticipantes();
};

#endif