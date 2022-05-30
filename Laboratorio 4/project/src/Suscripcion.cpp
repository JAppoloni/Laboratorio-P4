#include "../include/Suscripcion.hpp"

Suscripcion::Suscripcion(DtFechaHora fechaHora, TFormasPago formaPago, float pago) {
    this -> fechaAlta = fechaHora;
    this -> metodoPago = formaPago;
    this -> pago = pago;
}

DtFechaHora Suscripcion::getFechaAlta() {
    return this -> fechaAlta;
}

TFormasPago Suscripcion::getMetodoPago() {
    return this -> metodoPago;
}

float Suscripcion::getPago() {
    return this -> pago;
}