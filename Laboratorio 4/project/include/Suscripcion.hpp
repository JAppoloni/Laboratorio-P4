#include "DtFechaHora.hpp"
#include "TFormasPago.hpp"

#ifndef SUSCRIPCION_HPP
#define SUSCRIPCION_HPP

class Suscripcion {
   private:
    DtFechaHora fechaAlta;
    TFormasPago metodoPago;
    float pago;

   protected:
    Suscripcion(DtFechaHora, TFormasPago, float);

   public:
    virtual ~Suscripcion() = default;
    DtFechaHora getFechaAlta();
    TFormasPago getMetodoPago();
    float getPago();
    virtual bool actividad() = 0;
};

#endif