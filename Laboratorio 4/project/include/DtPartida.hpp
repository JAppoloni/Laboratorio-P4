#include <string>
#include "DtFechaHora.hpp"

#ifndef DTPARTIDA_HPP
#define DTPARTIDA_HPP

class DtPartida {
   private:
    int id;
    DtFechaHora fechaHora;
    std::string videojuego;
    double duracion;
    std::string creador;
    bool terminada;
    int idVideojuego;

   protected:
    DtPartida(int id,
              DtFechaHora fechaHora,
              std::string videojuego,
              double duracion,
              std::string creador,
              bool terminada,
              int idVideojuego);
    DtPartida() = default;

   public:
    ~DtPartida() = default;

    int getId();
    DtFechaHora getFechaHora();
    std::string getVideojuego() const;
    double getDuracion();
    std::string getcreador();
    bool getTerminada();
    int getIdVideojuego();
};

#endif