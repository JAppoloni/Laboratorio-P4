#ifndef CONTROLADOR_ESTADISTICAS_HPP
#define CONTROLADOR_ESTADISTICAS_HPP

#include <set>
#include <string>
#include <vector>
#include "CantUsuariosSusc.hpp"
#include "DtEstadistica.hpp"
#include "Estadistica.hpp"
#include "HorasTotalesJuego.hpp"
#include "Videojuego.hpp"

class ControladorEstadisticas {
   private:
    static ControladorEstadisticas* instance;
    ControladorEstadisticas();
    Videojuego* videojuego_sel;

    // instancias de las estadisticas del sistema.
    std::set<Estadistica*> setEstSis;

   public:
    ~ControladorEstadisticas();
    static ControladorEstadisticas* getInstance();
    std::set<std::string> listarVideojuegosDesarrollador();
    void selVideojuego(std::string);
    DtEstadistica crearDtEst(std::string, double);
    std::set<DtEstadistica> obtenerEstadisticas();

    // devuelve vector con pares (nombre, descripcion) de todas las estadisticas
    // del sistema
    std::vector<std::pair<std::string, std::string>> listarEstadisticas();

    void seleccionarEstadistica(std::string);
};

#endif