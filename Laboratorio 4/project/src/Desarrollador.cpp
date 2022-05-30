#include "../include/Desarrollador.hpp"
#include "../include/Partida.hpp"

#include <exception>

Desarrollador::Desarrollador(int id,
                             std::string email,
                             std::string contrasena,
                             std::string empresa)
    : Usuario(id, email, contrasena) {
    this->nombre_empresa = empresa;
    EstadisticasDes = new EstadisticasDev;
}

std::set<std::string> Desarrollador::getNombresJuegos() {
    std::set<std::string> setNombresJuegos;
    for (auto i : VideojuegosCreados) {
        std::string nombre_vj = i.second->getName();
        setNombresJuegos.insert(nombre_vj);
    }
    return setNombresJuegos;
}

std::set<std::string> Desarrollador::getVideojuegosDesarrolladorSinActivas(
    Desarrollador* d) {
    std::set<std::string> setNombresJuegos;
    bool sinPartidasSinTerminar;
    for (auto i : VideojuegosCreados) {
        sinPartidasSinTerminar = true;
        for (auto j : i.second->getPartidas()) {
            if (!j.second->getTerminada()) {
                sinPartidasSinTerminar = false;
            }
        }
        if (sinPartidasSinTerminar) {
            setNombresJuegos.insert(i.second->getName());
        }
    }
    return setNombresJuegos;
}

Videojuego* Desarrollador::buscarJuegoPorNombre(std::string nombre_vj) {
    Videojuego* ret = nullptr;
    for (auto i : VideojuegosCreados) {
        if (i.second->getName() == nombre_vj) {
            ret = i.second;
        }

        // se throwea domain_error porque la funcion no esta definida
        // para juegos no presentes en la coleccion
    }
    if (ret == nullptr) {
        throw std::domain_error("game_not_found");
    }
    return ret;
}

std::set<Estadistica*> Desarrollador::getEstadisticasDes() {
    return EstadisticasDes->getEst();
}

EstadisticasDev* Desarrollador::getEstDev() {
    return EstadisticasDes;
}

void Desarrollador::asociarVideojuegoDesarrollador(int x, Videojuego* v) {
    VideojuegosCreados.insert(std::pair<int, Videojuego*>(x, v));
}

void Desarrollador::desasociarVideojuegoConDesarrollador(Videojuego* v) {
    int x = v->getId();
    VideojuegosCreados.erase(x);
}

std::string Desarrollador::getEmpresa() {
    return this->nombre_empresa;
}

Desarrollador::~Desarrollador() {
    delete EstadisticasDes;
}
