#include "../include/ControladorUsuarios.hpp"
#include "../include/Desarrollador.hpp"
#include "../include/Jugador.hpp"
#include "../include/Videojuego.hpp"

ControladorUsuarios* ControladorUsuarios::instance = nullptr;

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instance == nullptr) {
        instance = new ControladorUsuarios();
    }
    return instance;
}

ControladorUsuarios::ControladorUsuarios() {
    ultimo_id = 1;
    idLog = -1;
}

ControladorUsuarios::~ControladorUsuarios() {
    for (auto i : colJugadores) {
        delete i.second;
    }
    for (auto i : colDesarrolladores) {
        delete i.second;
    }
}

void ControladorUsuarios::ingresarDatosUsuario(std::string email,
                                               std::string password) {
    this->email = email;
    this->contrasena = password;
}

void ControladorUsuarios::usuarioEsDesarrollador(std::string empresa) {
    this->EsDesarrollador = true;
    dataDesarrollador = DtDesarrollador(this->email, this->contrasena, empresa);
}

bool ControladorUsuarios::existeJugador(std::string nick) {
    EsDesarrollador = false;
    int encontrado = 1;
    for (auto it = colJugadores.begin();
         it != colJugadores.end() && encontrado == 1; it++) {
        encontrado = nick.compare(it->second->getNickname());
        break;
    }
    if (encontrado == 0) {
        return true;
    } else {
        dataJugador = DtJugador(this->email, this->contrasena, nick);
        return false;
    }
}

DtJugador ControladorUsuarios::datosIngresadosJ() {
    return this->dataJugador;
}

DtDesarrollador ControladorUsuarios::datosIngresadosD() {
    return this->dataDesarrollador;
}

void ControladorUsuarios::darAltaUsuario() {
    if (EsDesarrollador) {
        Desarrollador* des = new Desarrollador(
            ultimo_id, dataDesarrollador.getEmail(),
            dataDesarrollador.getPassword(),
            dataDesarrollador.getEmpresa());
        colDesarrolladores.insert(
            std::pair<int, Desarrollador*>(ultimo_id, des));
    } else {
        Jugador* jug =
            new Jugador(ultimo_id, dataJugador.getEmail(),
                        dataJugador.getPassword(), dataJugador.getNick());
        colJugadores.insert(std::pair<int, Jugador*>(ultimo_id, jug));
    }

    ultimo_id++;
}

std::set<std::string> ControladorUsuarios::obtenerJugadoresActivos(
    std::string vid) {
    std::set<std::string> res;
    for (auto it = colJugadores.begin(); it != colJugadores.end(); it++) {
        bool activo = it->second->videojuegoActivo(vid);
        if (activo) {
            res.insert(it->second->getNickname());
        }
    }
    return res;
}

void ControladorUsuarios::addPartida(Partida* p, std::string name) {
    for (auto it = colJugadores.begin(); it != colJugadores.end(); it++) {
        if (it->second->getNickname() == name) {
            it->second->addPartidaJugadorCreador(p);
        }
    }
}

Jugador* ControladorUsuarios::buscarJugador(std::string name) {
    Jugador* ret = NULL;
    for (auto it = colJugadores.begin(); it != colJugadores.end(); it++) {
        if (it->second->getNickname() == name) {
            ret = (it->second);
        }
    }
    return ret;
}

Usuario* ControladorUsuarios::userLogged() {
    auto it = colJugadores.find(idLog);
    if (it == colJugadores.end()) {
        return (colDesarrolladores.find(idLog)->second);
    } else {
        return (it->second);
    }
}

EstadoSesion ControladorUsuarios::tipoUsuarioLogged() {
    Desarrollador* des = dynamic_cast<Desarrollador*>(userLogged());
    return (des == NULL) ? jugador : desarrollador;
}

void ControladorUsuarios::asociarVideojuegoDesarrollador(Desarrollador* d,
                                                         int idVid,
                                                         Videojuego* v) {
    d->asociarVideojuegoDesarrollador(idVid, v);
}

std::set<std::string> ControladorUsuarios::getVideojuegosDesarrollador(
    Desarrollador* d) {
    return d->getNombresJuegos();
}

std::pair<bool, bool> ControladorUsuarios::ingresarDatosLogIn(
    std::string email,
    std::string contrasena) {
    bool encontre = false;
    bool esdes = false;
    for (auto it = colJugadores.begin(); it != colJugadores.end(); it++) {
        if (it->second->getEmail() == email &&
            it->second->getContrasena() == contrasena) {
            emailLog = email;
            contrasenaLog = contrasena;
            idLog = it->second->getId();
            encontre = true;
        }
    }
    if (!encontre) {
        for (auto it = colDesarrolladores.begin();
             it != colDesarrolladores.end(); it++) {
            if (it->second->getEmail() == email &&
                it->second->getContrasena() == contrasena) {
                emailLog = email;
                contrasenaLog = contrasena;
                idLog = it->second->getId();
                encontre = true;
                esdes = true;
            }
        }
    }
    return std::make_pair(encontre, esdes);
}

std::string ControladorUsuarios::getNameLogged(EstadoSesion estSes) {
    if (estSes == jugador) {
        return colJugadores[idLog]->getNickname();
    } else {
        return colDesarrolladores[idLog]->getEmpresa();
    }
}