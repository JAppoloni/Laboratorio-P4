#include <set>
#include <string>
#include "DtFechaHora.hpp"
#include "DtPartida.hpp"

#ifndef DTPARTMULT_HPP
#define DTPARTMULT_HPP

class DtPartidaMultijugador : public DtPartida {
   private:
    bool esTrasmitida;
    std::set<std::string> jugadoresConectados;

   public:
    DtPartidaMultijugador(int id,
                          DtFechaHora fechaHora,
                          std::string videojuego,
                          double duracion,
                          std::string creador,
                          bool terminada,
                          int idVideojuego,
                          bool esTrasmitida,
                          std::set<std::string> jugadoresConectados);
    DtPartidaMultijugador() = default;
    ~DtPartidaMultijugador() = default;

    bool getEsTrasmitida();
    std::set<std::string> getJugadores();
    bool operator<(const DtPartidaMultijugador& Part) const;
};

#endif