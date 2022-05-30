#include "../include/Videojuego.hpp"
#include "../include/ControladorPartidas.hpp"
#include "../include/ControladorUsuarios.hpp"
#include "../include/Jugador.hpp"
#include "../include/Partida.hpp"
#include "../include/PartidaMultijugador.hpp"
#include "../include/Puntua.hpp"

Videojuego::Videojuego(int idJuego,
                       std::string nombre,
                       std::string descripcion,
                       DtCosto costos,
                       std::set<Genero*> catG,
                       std::set<Otros*> catO,
                       std::set<TipoDePlataforma*> catP,
                       Desarrollador* des) {
    this->idJuego = idJuego;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costos = costos;
    this->puntajeProm = 0;
    this->cantidadDePuntajes = 0;
    this->catGenero = catG;
    this->catOtros = catO;
    this->catPlataforma = catP;
    this->creador = des;

    std::set<Puntua*> punt;
    this->puntuaciones = punt;
    std::map<int, Partida*> part;
    this->Partidas = part;
    std::set<HistorialDeSuscripciones*> sus;
    this->Suscripciones = sus;
    this->horasDeJuego = 0;
}

DtCosto Videojuego::getCostos() {
    return this->costos;
}

int Videojuego::getId() {
    return this->idJuego;
}

double Videojuego::getHorasDeJuego() {
    return this->horasDeJuego;
}

std::string Videojuego::getName() {
    return this->nombre;
}

std::string Videojuego::getDescripcion() {
    return this->descripcion;
}

double Videojuego::getPuntajePromedio() {
    return this->puntajeProm;
}

void Videojuego::agregarCategoria(Categoria* cat) {
    Genero* gen = dynamic_cast<Genero*>(cat);
    if (cat != NULL) {
        this->catGenero.insert(gen);
    }
    Otros* ot = dynamic_cast<Otros*>(cat);
    if (cat != NULL) {
        this->catOtros.insert(ot);
    }
    TipoDePlataforma* tp = dynamic_cast<TipoDePlataforma*>(cat);
    if (cat != NULL) {
        this->catPlataforma.insert(tp);
    }
}

void Videojuego::addPartida(Partida* p) {
    Partidas.insert(std::pair<int, Partida*>(p->getIdPartida(), p));
}

void Videojuego::actualizarPuntuacion(int nuevoP, bool esNuevo, int viejoP) {
    int total =
        (this->cantidadDePuntajes * this->puntajeProm) + nuevoP - viejoP;
    if (esNuevo) {
        this->cantidadDePuntajes++;
    }
    this->puntajeProm = (double)total / (double)this->cantidadDePuntajes;
}

Desarrollador* Videojuego::getDesarrollador() {
    return this->creador;
}

DtCosto Videojuego::getCosto() {
    return costos;
}

std::set<DtCategoria> Videojuego::getDtCatGenero() {
    std::set<DtCategoria> res;
    for (std::set<Genero*>::iterator it = catGenero.begin();
         it != catGenero.end(); it++) {
        Genero* gen = (*it);
        TipoCat cat = genero;
        DtCategoria auxiliar =
            DtCategoria(gen->getNombre(), gen->getDescripcion(), cat);
        res.insert(auxiliar);
    }
    return res;
}

std::map<int, Partida*> Videojuego::getPartidas() {
    return Partidas;
}

std::set<DtCategoria> Videojuego::getDtCatOtros() {
    std::set<DtCategoria> res;
    for (std::set<Otros*>::iterator it = catOtros.begin(); it != catOtros.end();
         it++) {
        Otros* otr = (*it);
        TipoCat cat = otro;
        DtCategoria auxiliar =
            DtCategoria(otr->getNombre(), otr->getDescripcion(), cat);
        res.insert(auxiliar);
    }
    return res;
}

std::set<DtCategoria> Videojuego::getDtCatPlataforma() {
    std::set<DtCategoria> res;
    for (auto it : catPlataforma) {
        TipoDePlataforma* catp = it;
        TipoCat cat = plataforma;
        DtCategoria auxiliar =
            DtCategoria(catp->getNombre(), catp->getDescripcion(), cat);
        res.insert(auxiliar);
    }
    return res;
}

void Videojuego::addHorasJuego(double horas) {
    horasDeJuego += horas;
}

void Videojuego::insertarPuntuacion(Puntua* newp) {
    this->puntuaciones.insert(newp);
}

void Videojuego::preEliminacion() {
    // Deslink des
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Desarrollador* des = dynamic_cast<Desarrollador*>(cu->userLogged());
    des->desasociarVideojuegoConDesarrollador(this);
    // puntuaciones
    for (auto i = puntuaciones.begin(); i != puntuaciones.end(); i++) {
        (*i)->getJugador()->unlinkPuntuacion(this->idJuego);
        delete (*i);
    }
    // Hist Sus
    for (auto j = Suscripciones.begin(); j != Suscripciones.end(); j++) {
        (*j)->getJugador()->unlinkSusc((*j));
        delete (*j);
    }
    // partidas
    ControladorPartidas* cp = ControladorPartidas::getInstance();
    for (auto j = Partidas.begin(); j != Partidas.end(); j++) {
        PartidaMultijugador* pm =
            dynamic_cast<PartidaMultijugador*>((*j).second);
        if (pm != nullptr) {
            pm->unlinkJugM();
        } else {
            (*j).second->getInicia()->unlinkInicia((*j).second);
        }
        cp->quitarPartida((*j).first);
        delete (*j).second;
    }
}