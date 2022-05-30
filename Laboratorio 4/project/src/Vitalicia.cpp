#include "../include/Vitalicia.hpp"

Vitalicia::Vitalicia(DtFechaHora fh, TFormasPago fp, float costo)
    : Suscripcion(fh, fp, costo) {}

bool Vitalicia::actividad() {
    return true;
}