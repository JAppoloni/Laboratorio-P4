#include "DtFechaHora.hpp"

#ifndef FECHASISTEMA_HPP
#define FECHASISTEMA_HPP

class FechaSistema {
   private:
    static FechaSistema* instance;
    DtFechaHora fecha;
    FechaSistema() = default;

   public:
    ~FechaSistema() = default;
    static FechaSistema* getInstance();
    void setFecha(DtFechaHora);
    DtFechaHora getFecha();
};

#endif