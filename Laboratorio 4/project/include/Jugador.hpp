#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <map>
#include <set>
#include <string>
#include <vector>
#include "DtPartidaIndividual.hpp"
#include "DtPartidaMultijugador.hpp"
#include "HistorialDeSuscripciones.hpp"
#include "PMJ.hpp"
#include "Puntua.hpp"
#include "TFormasPago.hpp"
#include "Usuario.hpp"

class PMJ;
class HistorialDeSuscripciones;
class Puntua;
class Videojuego;

class Jugador : public Usuario {
   private:
    std::string nickname;
    // std::string descripcion;
    std::set<HistorialDeSuscripciones*> Historiales;

    std::map<int, Puntua*> Puntuaciones;  // Id_Juego, Obj Puntua
    std::set<PMJ*> PartidasMultiPertenece;
    std::set<Partida*> PartidasIniciadas;

   public:
    Jugador(int,
            std::string,
            std::string,
            std::string);
    ~Jugador();            
    std::vector<DtPartidaIndividual> PartidasIndiv(std::string);
    std::set<Videojuego*> obtenerVideojuegosActivos();
    std::set<Videojuego*> obtenerVideojuegosNoActivos();
    std::set<Partida*> getPartidasIniciadas();
    std::string getNickname();
    std::vector<DtPartidaMultijugador> partidasAbandonarJug();
    void AbandonarJug(int id);
    bool esVitalicia(std::string);
    void desactivarSuscripcion(Videojuego*);  // throwea
    void activarSuscripcion(Videojuego*,
                            DtFechaHora,
                            TiposSuscripcion,
                            TFormasPago);
    void addPartidaJugadorCreador(Partida*);
    void addPMJ(PMJ*);
    void puntuar(Videojuego*, int);
    bool videojuegoActivo(std::string);
    void unlinkPuntuacion(int);
    void unlinkSusc(HistorialDeSuscripciones*);
    void unlinkPMJ(PMJ*);
    void unlinkInicia(Partida*);
};

#endif