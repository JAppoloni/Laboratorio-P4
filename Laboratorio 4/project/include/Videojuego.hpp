
#ifndef VIDEOJUEGO_HPP
#define VIDEOJUEGO_HPP

#include <string>
#include "Desarrollador.hpp"
#include "DtCategoria.hpp"
#include "DtCosto.hpp"
#include "Genero.hpp"
#include "HistorialDeSuscripciones.hpp"
#include "Otros.hpp"
#include "TipoDePlataforma.hpp"

class HistorialDeSuscripciones;
class Desarrollador;
class Partida;
class Puntua;

class Videojuego {
   private:
    int idJuego;
    std::string nombre;
    std::string descripcion;
    double horasDeJuego;
    DtCosto costos;
    double puntajeProm;
    int cantidadDePuntajes;
    std::set<Puntua*> puntuaciones;
    std::set<Genero*> catGenero;
    std::set<Otros*> catOtros;
    std::set<TipoDePlataforma*> catPlataforma;
    Desarrollador* creador;
    std::map<int, Partida*> Partidas;  // Id_partida , Partida*
    std::set<HistorialDeSuscripciones*> Suscripciones;

   public:
    Videojuego(int idJuego,
               std::string nombre,
               std::string descripcion,
               DtCosto costos,
               std::set<Genero*>,
               std::set<Otros*>,
               std::set<TipoDePlataforma*>,
               Desarrollador*);
    ~Videojuego() = default;
    DtCosto getCostos();
    int getId();
    double getHorasDeJuego();
    Desarrollador* getDesarrollador();
    std::string getName();
    std::string getDescripcion();
    DtCosto getCosto();
    std::map<int, Partida*> getPartidas();
    std::set<DtCategoria> getDtCatGenero();
    std::set<DtCategoria> getDtCatOtros();
    std::set<DtCategoria> getDtCatPlataforma();
    double getPuntajePromedio();
    void actualizarPuntuacion(int nuevoP, bool esNuevo, int viejoP);
    void addPartida(Partida*);
    void agregarCategoria(Categoria*);
    void insertarPuntuacion(Puntua*);
    void preEliminacion();

    void addHorasJuego(double horas);
};

#endif