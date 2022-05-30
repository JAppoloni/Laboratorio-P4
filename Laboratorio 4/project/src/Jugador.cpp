#include "../include/Jugador.hpp"
#include "../include/FechaSistema.hpp"
#include "../include/PartidaIndividual.hpp"
#include "../include/PartidaMultijugador.hpp"
#include "../include/Videojuego.hpp"


Jugador::Jugador(int id, std::string email, std::string contr, std::string nick)
    : Usuario(id, email, contr) {
    this->nickname = nick;
    std::set<HistorialDeSuscripciones*> his;
    this->Historiales = his;
    std::map<int, Puntua*> punt;
    this->Puntuaciones = punt;
    std::set<PMJ*> pmp;
    this->PartidasMultiPertenece = pmp;
    std::set<Partida*> pi;
    this->PartidasIniciadas = pi;
}

std::set<Videojuego*> Jugador::obtenerVideojuegosActivos() {
    Videojuego* elem;
    std::set<Videojuego*> res;
    for (auto it = Historiales.begin(); it != Historiales.end(); it++) {
        if ((*it)->HaySuscActiva()) {
            elem = (*it)->obtenerVideojuego();
            res.insert(elem);
        }
    }
    return res;
}

std::set<Videojuego*> Jugador::obtenerVideojuegosNoActivos() {
    Videojuego* elem;
    std::set<Videojuego*> res;
    for (auto it = Historiales.begin(); it != Historiales.end(); it++) {
        if (!(*it)->HaySuscActiva()) {
            elem = (*it)->obtenerVideojuego();
            res.insert(elem);
        }
    }
    return res;
}

std::string Jugador::getNickname() {
    return nickname;
}

void Jugador::desactivarSuscripcion(Videojuego* vid) {
    bool encontrado = false;
    std::set<HistorialDeSuscripciones*>::iterator it = Historiales.begin();
    while (!encontrado && (it != Historiales.end())) {
        if (vid == (*it)->obtenerVideojuego()) {
            encontrado = true;
        } else {
            it++;
        }
    }
    if (!encontrado) {
        throw std::invalid_argument("No existe historial para ese videojuego.");
    } else {
        (*it)->desactivar();
    }
}

void Jugador::activarSuscripcion(Videojuego* vid,
                                 DtFechaHora deteFH,
                                 TiposSuscripcion ts,
                                 TFormasPago tfp) {
    std::set<HistorialDeSuscripciones*>::iterator it = Historiales.begin();
    bool encontrado = false;
    while (!encontrado && (it != Historiales.end())) {
        if (vid == (*it)->obtenerVideojuego()) {
            encontrado = true;
        } else {
            it++;
        }
    }
    if (!encontrado) {
        HistorialDeSuscripciones* hds = new HistorialDeSuscripciones(this, vid);
        Historiales.insert(hds);
        hds->activar(ts, tfp, deteFH);
    } else {
        (*it)->activar(ts, tfp, deteFH);
    }
}
std::vector<DtPartidaIndividual> Jugador::PartidasIndiv(
    std::string JuegoSelect) {
    std::set<DtPartidaIndividual> partidas;
    for (auto it = PartidasIniciadas.begin(); it != PartidasIniciadas.end();
         it++) {
        PartidaIndividual* elem = dynamic_cast<PartidaIndividual*>(*it);
        if ((elem != NULL) && (elem->getVideojuego() == JuegoSelect) &&
            (elem->getTerminada())) {
            DtPartidaIndividual DtPart = DtPartidaIndividual(
                elem->getIdPartida(), elem->getFechaInicio(),
                elem->getVideojuego(), elem->getDuracion(), "", true, 0,
                elem->getContinuaPartida(), 0);
            partidas.insert(DtPart);
        }
    }
    int tope = partidas.size();
    std::vector<DtPartidaIndividual> res;
    for (int i = 0; i < tope; i++) {
        auto min = partidas.begin();
        for (auto it = partidas.begin(); it != partidas.end(); it++) {
            DtPartidaIndividual var1 = (*it);
            DtPartidaIndividual var2 = (*min);
            if (var1.getFechaHora() < var2.getFechaHora()) {
                min = it;
            }
        }
        res.push_back(*min);
        partidas.erase(min);
    }
    return res;
}

bool Jugador::videojuegoActivo(std::string juego) {
    bool ret = false;
    for (auto it = Historiales.begin(); it != Historiales.end(); it++) {
        if (juego == (*it)->obtenerVideojuego()->getName()) {
            ret = (*it)->HaySuscActiva();
        }
    }
    return ret;
}

void Jugador::addPartidaJugadorCreador(Partida* p) {
    PartidasIniciadas.insert(p);
}

void Jugador::addPMJ(PMJ* pm) {
    PartidasMultiPertenece.insert(pm);
}

void Jugador::puntuar(Videojuego* vid, int p) {
    auto auxiliar = Puntuaciones.find(vid->getId());
    if (auxiliar == Puntuaciones.end()) {
        Puntua* newp = new Puntua(vid, p, this);
        Puntuaciones.insert({vid->getId(), newp});
        vid->actualizarPuntuacion(p, 1, 0);
        vid->insertarPuntuacion(newp);
    } else {
        int viejo = Puntuaciones[vid->getId()]->getPuntaje();
        Puntuaciones[vid->getId()]->setPuntaje(p);
        vid->actualizarPuntuacion(p, 0, viejo);
    }
}

std::vector<DtPartidaMultijugador> Jugador::partidasAbandonarJug() {
    std::vector<DtPartidaMultijugador> res;
    DtPartidaMultijugador elem;

    for (auto i : PartidasMultiPertenece) {
        if (!i->getPartidaM()->getTerminada() && !i->getSalida()) {
            PartidaMultijugador* temp = i->getPartidaM();
            std::set<std::string> jugadores;

            jugadores.insert(temp->getInicia()->getNickname());
            for (auto j : temp->getParticipantes()) {
                jugadores.insert(j->getJugador()->getNickname());
            }
            elem = DtPartidaMultijugador(
                temp->getIdPartida(), temp->getFechaInicio(),
                temp->getVideojuego(), 0, temp->getInicia()->getNickname(), 0,
                0, temp->getTransmitidaEnVivo(), jugadores);
            res.push_back(elem);
        }
    }
    return res;
}

void Jugador::AbandonarJug(int id) {
    FechaSistema* fs = FechaSistema::getInstance();
    auto i = PartidasMultiPertenece.begin();
    for (; i != PartidasMultiPertenece.end() &&
           (*i)->getPartidaM()->getIdPartida() != id;
         i++) {
    }
    if (i == PartidasMultiPertenece.end() || (*i)->getSalida()) {
        throw std::invalid_argument("Hubo un problema con el ID");
    } else {
        (*i)->setHoraAbandono(fs->getFecha());
    }
}

std::set<Partida*> Jugador::getPartidasIniciadas() {
    return this->PartidasIniciadas;
}

void Jugador::unlinkPuntuacion(int id) {
    this->Puntuaciones.erase(id);
}

void Jugador::unlinkSusc(HistorialDeSuscripciones* Hist) {
    this->Historiales.erase(Hist);
}

void Jugador::unlinkPMJ(PMJ* pmjVar) {
    this->PartidasMultiPertenece.erase(pmjVar);
}

void Jugador::unlinkInicia(Partida* p) {
    this->PartidasIniciadas.erase(p);
}

Jugador::~Jugador() {
    for (auto i : Puntuaciones) {
        delete i.second;
    }
    for (auto i : Historiales) {
        delete i;
    }
}

bool Jugador::esVitalicia(std::string juego) {
    bool ret = false;
    for (auto it = Historiales.begin(); it != Historiales.end(); it++) {
        if (juego == (*it)->obtenerVideojuego()->getName()) {
            ret = (*it)->esVitaliciaLaActiva();
        }
    }
    return ret;
}
