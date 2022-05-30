#include <string>
#include "DtFechaHora.hpp"
#include "DtPartida.hpp"

#ifndef DTPARTIDAIND_HPP
#define DTPARTIDAIND_HPP

class DtPartidaIndividual : public DtPartida {
   private:
    bool esContinuacion;
    int idCont;

   public:
    DtPartidaIndividual() = default;
    DtPartidaIndividual(int id,
                        DtFechaHora fechaHora,
                        std::string videojuego,
                        double duracion,
                        std::string creador,
                        bool terminada,
                        int idVideojuego,
                        bool esContinuacion,
                        int idCont);

    ~DtPartidaIndividual() = default;

    bool getEsContinuacion();
    int getIdCont();
    bool operator<(const DtPartidaIndividual& Part) const;
};

#endif