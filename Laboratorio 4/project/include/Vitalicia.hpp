#include "Suscripcion.hpp"
#include "DtFechaHora.hpp"
#include "TFormasPago.hpp"
#include <string>

#ifndef VITALICIA_HPP
#define VITALICIA_HPP

class Vitalicia : public Suscripcion {
    public:
        Vitalicia(DtFechaHora, TFormasPago, float);
        bool actividad();
};

#endif