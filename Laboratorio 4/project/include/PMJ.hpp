#ifndef PMJ_HPP
#define PMJ_HPP

#include "DtFechaHora.hpp"
#include "Jugador.hpp"

class PartidaMultijugador;

class PMJ {
   private:
    DtFechaHora horaAbandono;
    PartidaMultijugador* partidaM;
    Jugador* jugador;
    bool salio;

   public:
    PMJ(PartidaMultijugador*, std::string);

    ~PMJ() = default;
    void setHoraAbandono(DtFechaHora);
    DtFechaHora getHoraAbandono();
    PartidaMultijugador* getPartidaM();
    Jugador* getJugador();
    bool getSalida();
};

#endif