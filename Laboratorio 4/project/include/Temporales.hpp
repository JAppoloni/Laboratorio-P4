#include "Suscripcion.hpp"
#include "DtFechaHora.hpp"
#include "TFormasPago.hpp"
#include "TiposSuscripcion.hpp"
#include <string>

#ifndef TEMPORALES_HPP
#define TEMPORALES_HPP

class Temporales : public Suscripcion {
    private:
        TiposSuscripcion periodo_validez;
        bool cancelada;
    public:
        Temporales(DtFechaHora, TFormasPago, float, TiposSuscripcion);
        void cancelar();
        bool actividad();
};

#endif