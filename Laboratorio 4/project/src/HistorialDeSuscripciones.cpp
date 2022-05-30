#include "../include/HistorialDeSuscripciones.hpp"
#include "../include/DtCosto.hpp"
#include "../include/DtFechaHora.hpp"
#include "../include/Jugador.hpp"
#include "../include/Temporales.hpp"
#include "../include/Videojuego.hpp"
#include "../include/Vitalicia.hpp"

HistorialDeSuscripciones::HistorialDeSuscripciones(Jugador* j, Videojuego* vj) {
    this->jugador = j;
    this->videojuego = vj;
    std::set<Suscripcion*> sus;
    this->suscripciones = sus;
    this->susActiva = nullptr;
}

Jugador* HistorialDeSuscripciones::getJugador() {
    return this->jugador;
}

void HistorialDeSuscripciones::activar(TiposSuscripcion tipoS,
                                       TFormasPago formaP,
                                       DtFechaHora fecha) {
    DtCosto costos = this->videojuego->getCostos();
    double precio;

    if (tipoS == vitalicio) {
        Vitalicia* nueva = new Vitalicia(fecha, formaP, costos.getVitalicio());
        this->suscripciones.insert(nueva);
        susActiva = nueva;
    } else {
        switch (tipoS) {
            case un_mes:
                precio = costos.getMensual();
                break;
            case tres_meses:
                precio = costos.getTrimestral();
                break;
            case un_anio:
                precio = costos.getAnual();
                break;
            case vitalicio:
                break;
        }
        Temporales* nueva = new Temporales(fecha, formaP, precio, tipoS);
        this->suscripciones.insert(nueva);
        susActiva = nueva;
    }
}

Videojuego* HistorialDeSuscripciones::obtenerVideojuego() {
    return this->videojuego;
}

bool HistorialDeSuscripciones::HaySuscActiva() {
    bool encontrado = false;
    for (auto it = suscripciones.begin();
         it != suscripciones.end() && !encontrado; it++) {
        encontrado = (*it)->actividad();
    }
    return encontrado;
}

void HistorialDeSuscripciones::desactivar() {
    if (susActiva != nullptr) {
        Vitalicia* auxiliarVitalicia = dynamic_cast<Vitalicia*>(susActiva);
        Temporales* auxiliarTemporal = dynamic_cast<Temporales*>(susActiva);
        if (auxiliarVitalicia) {
            throw std::invalid_argument(
                "No podes cancelar una suscripcion vitalicia.");
        } else if (auxiliarTemporal) {
            auxiliarTemporal->cancelar();
            susActiva = nullptr;
        } else {
            throw std::invalid_argument("Error no esperado.");
        }
    } else {
        throw std::invalid_argument(
            "El videojuego no tiene una suscripcion activa.");
    }
}

std::set<Suscripcion*> HistorialDeSuscripciones::getSuscripciones() {
    return this->suscripciones;
}

HistorialDeSuscripciones::~HistorialDeSuscripciones() {
    for (std::set<Suscripcion*>::iterator it = this->suscripciones.begin();
         it != this->suscripciones.end(); it++) {
        delete (*it);
    }
}

bool HistorialDeSuscripciones::esVitaliciaLaActiva() {
    Vitalicia* vit = dynamic_cast<Vitalicia*>(susActiva);
    return !(vit == nullptr);
}
