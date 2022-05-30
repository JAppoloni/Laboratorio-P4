#ifndef CONTROLADOR_PARTIDAS_HPP
#define CONTROLADOR_PARTIDAS_HPP

#include <map>
#include <set>
#include <string>
#include <vector>

#include "Videojuego.hpp"

#include "DtFechaHora.hpp"
#include "DtPartidaIndividual.hpp"
#include "DtPartidaMultijugador.hpp"

class Videojuego;

class ControladorPartidas {
   private:
    static ControladorPartidas* instance;
    std::map<int, Partida*> partidasSis;  // map<idPartida, Partida}>
    ControladorPartidas();
    int UltimoId;

    // variables de "Recordar"
    std::string JuegoRecordado;
    int IdContinuacion;
    bool esIndiv;
    bool vivoRec;
    std::set<std::string> SetJug;
    DtPartidaIndividual DtIndiv;
    DtPartidaMultijugador DtMulti;

   public:
    static ControladorPartidas* getInstance();

    std::set<std::string> obtenerVideojuegosConSuscripcionActiva();
    void selectGame(std::string);
    std::vector<DtPartidaIndividual> listarPartidasIndiv();
    // SI NO CONTINUA NINGUNA PASAR -1
    void crearPartidaIndividual(int);
    std::set<std::string> listarJugadoresActivos();
    void agregarJugador(std::set<std::string>, bool);
    DtPartidaIndividual getDtPartidaI();
    DtPartidaMultijugador getDtPartidaM();
    void altaPartida();

    std::vector<DtPartidaMultijugador> partidasAbandonar();
    void Abandonar(int id);

    std::set<DtPartidaIndividual> consultarPartidasActivasI();
    std::set<DtPartidaMultijugador> consultarPartidasActivasM();

    void quitarPartida(int);
    void terminarPartida(int);
    void eliminarPartida(Videojuego*);

    ~ControladorPartidas();
};

#endif
