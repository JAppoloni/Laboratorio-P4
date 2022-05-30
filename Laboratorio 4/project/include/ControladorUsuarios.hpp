#ifndef CONTROLADOR_USUARIOS_HPP
#define CONTROLADOR_USUARIOS_HPP

#include <map>
#include <set>
#include <string>

#include "DtDesarrollador.hpp"
#include "DtFechaHora.hpp"
#include "DtJugador.hpp"
#include "DtUsuario.hpp"
#include "DtVideojuego.hpp"
#include "EstadoSesion.hpp"
#include "Usuario.hpp"

class Jugador;
class Desarrollador;
class Videojuego;
class Partida;

class ControladorUsuarios {
   private:
    // patron Singleton
    static ControladorUsuarios* instance;
    ControladorUsuarios();

    int ultimo_id;

    DtJugador dataJugador;
    DtDesarrollador dataDesarrollador;
    bool EsDesarrollador;
    int idLog; 
    std::string email;
    std::string contrasena;
    std::string emailLog;
    std::string contrasenaLog;

    std::map<int, Jugador*> colJugadores;
    std::map<int, Desarrollador*> colDesarrolladores;

   public:
    // Instancia y destructor
    static ControladorUsuarios* getInstance();
    ~ControladorUsuarios();

    // ops
    Jugador* buscarJugador(std::string);
    Usuario* userLogged();
    void ingresarDatosUsuario(std::string email,
                              std::string contrasena);  // done
    std::pair<bool, bool> ingresarDatosLogIn(
        std::string email,
        std::string
            contrasena);  // primer bool:encontro segundo bool: esdesarrollador
    bool existeJugador(std::string nick);      // done
    void usuarioEsDesarrollador(std::string);  // done
    DtJugador datosIngresadosJ();              // done
    DtDesarrollador datosIngresadosD();        // done
    void darAltaUsuario();                     // done

    std::set<std::string> obtenerJugadoresActivos(std::string);  // done
    std::set<std::string> getVideojuegosDesarrollador(Desarrollador*);
    void addPartida(Partida*, std::string);
    EstadoSesion tipoUsuarioLogged();

    void asociarVideojuegoDesarrollador(Desarrollador*, int idVid, Videojuego*);
    std::string getNameLogged(EstadoSesion);
};

#endif