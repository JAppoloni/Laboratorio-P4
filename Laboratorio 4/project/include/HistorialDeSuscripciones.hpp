#ifndef HISTORIALSUSC_HPP
#define HISTORIALSUSC_HPP

#include <set>
#include "DtFechaHora.hpp"
#include "Suscripcion.hpp"
#include "TFormasPago.hpp"
#include "Temporales.hpp"
#include "TiposSuscripcion.hpp"
#include "Vitalicia.hpp"

class Jugador;
class Videojuego;

class HistorialDeSuscripciones {
   private:
    Jugador* jugador;
    Videojuego* videojuego;
    std::set<Suscripcion*> suscripciones;
    Suscripcion* susActiva;

   public:
    HistorialDeSuscripciones(Jugador*, Videojuego*);
    ~HistorialDeSuscripciones();
    Jugador* getJugador();
    Videojuego* obtenerVideojuego();
    std::set<Suscripcion*> getSuscripciones();
    bool HaySuscActiva();
    void activar(TiposSuscripcion, TFormasPago, DtFechaHora);  // falta impl
    void desactivar();  // throwea si pasan cosas turbia (no van a pasar)
    bool esVitaliciaLaActiva();
};

#endif