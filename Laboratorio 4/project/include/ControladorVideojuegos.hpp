#ifndef CONTROLADOR_VIDEOJUEGOS_HPP
#define CONTROLADOR_VIDEOJUEGOS_HPP

#include <set>
#include <string>
#include "DtCategoria.hpp"
#include "DtCosto.hpp"
#include "DtVideojuego.hpp"
#include "Otros.hpp"
#include "TFormasPago.hpp"
#include "TipoCat.hpp"
#include "TipoDePlataforma.hpp"
#include "TiposSuscripcion.hpp"
#include "Videojuego.hpp"

class Otros;
class Videojuego;

class ControladorVideojuegos {
   private:
    static ControladorVideojuegos* instance;
    ControladorVideojuegos();

    Videojuego* alQueSeQuiereSuscribir;
    TiposSuscripcion tipoDeSuscripcionNuevaSus;
    TFormasPago tFormaDePagoNuevaSus;
    std::set<Videojuego*> ColJuegos;
    std::set<Genero*> ColGeneros;
    std::set<Otros*> ColOtros;
    std::set<TipoDePlataforma*> ColTiposDePlataforma;
    DtVideojuego dataVideojuego;
    int ultimo_id;
    std::set<Genero*> GenerosTemporal;
    std::set<Otros*> OtrasTemporal;
    std::set<TipoDePlataforma*> TiposDePlataformaTemporal;
    std::set<DtCategoria> DtGenerosTemporal;
    std::set<DtCategoria> DtOtrasTemporal;
    std::set<DtCategoria> DtTiposDePlataformaTemporal;
    std::string nombrerecordado;
    std::string descripcionrecordada;
    DtCosto costorecordado;
    Videojuego* juegoeliminar;

   public:
    std::set<Genero*> getColGeneros();
    std::set<Otros*> getColOtros();
    std::set<TipoDePlataforma*> getColTiposDePlataforma();
    static ControladorVideojuegos* getInstance();
    Videojuego* buscarVideojuego(std::string);

    // Caso de uso publicar videojuego:
    void agregarVideojuego(std::string, std::string, DtCosto);
    void elegirCategoriaGenero(std::string);
    void elegirCategoriaPlataforma(std::string);
    void elegirOtraCategoria(std::string);
    std::set<DtCategoria> consultarCategoria(TipoCat);
    void abortarPublicacion();
    DtVideojuego obtenerDatosIngresadosVideojuego();
    void confirmarPublicacion();

    // Caso de uso suscribirse a videojuego:
    std::set<DtVideojuego> obtenerVideojuegosConSuscripcionActiva();
    std::set<DtVideojuego> obtenerVideojuegosSinSuscripcionActiva();
    std::pair<bool, bool> seleccionarVideojuego(std::string);
    void suscripcion(TiposSuscripcion, TFormasPago);  // throw en esta operacion
    void cancelarSuscripcion();  // throw en Jugador::desactivarSuscripcion
    void altaSuscripcion();
    // void liberarSuscripcion();

    // Otro casos de uso:
    std::set<std::string> getNombreVideojuegosSinPartidaEnCurso();
    void eliminarVideojuego();  // falta
    void seleccionarVideojuegoEliminar(std::string);

    // Caso de uso: Ver informacion de Videojuego:
    // Devuelve un set con todos los nombres de los videojuegos en el sistema.
    std::set<std::string> nombresVideojuegos();
    /* Devuelve un (DtVideojuego, horasTotalesJuego) con la informacion del
     videojuego "nombre". Tira std::invalid_argument si no lo encuentra. */

    std::pair<DtVideojuego, double> infoDetalladaVideojuego(std::string nombre);

    // Caso de uso Asignar puntaje a videojuego;
    std::set<std::pair<std::string, std::string>> obtenerJuegos();

    void puntuarJuego(std::string, int);  // throw si el juego no existe

    ~ControladorVideojuegos();  // falta
    std::set<DtCategoria> listarCategorias();
    std::set<DtCategoria> listarCatsGenero();
    std::set<DtCategoria> listarCatsPlataforma();
    std::set<DtCategoria> listarCatsOtra();
    DtCategoria crearCategoria(std::string, std::string, TipoCat);
    void altaCategoria(DtCategoria);
    double getPuntaje(std::string);
};

#endif
