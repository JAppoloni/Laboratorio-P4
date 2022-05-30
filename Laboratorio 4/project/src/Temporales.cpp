#include "../include/Temporales.hpp"
#include "../include/FechaSistema.hpp"

Temporales::Temporales(DtFechaHora fechaHora, TFormasPago formaPago, float pago, TiposSuscripcion tipoSus): Suscripcion(fechaHora, formaPago, pago){
    this -> periodo_validez = tipoSus;
    this -> cancelada = false;
}

bool Temporales::actividad() {
    if (cancelada) {
        return false;
    } else {
        FechaSistema* fs;
        fs = FechaSistema::getInstance();
        // El overload operator+ le agrega la duracion del periodo de validez a
        // la fecha:
        return fs->getFecha() < (this->getFechaAlta() + periodo_validez);
    }
}

void Temporales::cancelar(){
    this->cancelada=true;
}