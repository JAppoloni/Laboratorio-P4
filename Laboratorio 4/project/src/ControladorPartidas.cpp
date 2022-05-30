#include "../include/ControladorPartidas.hpp"
#include "../include/ControladorUsuarios.hpp"
#include "../include/ControladorVideojuegos.hpp"
#include "../include/DtPartida.hpp"
#include "../include/FechaSistema.hpp"
#include "../include/Jugador.hpp"
#include "../include/Partida.hpp"
#include "../include/PartidaIndividual.hpp"
#include "../include/PartidaMultijugador.hpp"
#include "../include/Usuario.hpp"

ControladorPartidas* ControladorPartidas::instance = nullptr;

ControladorPartidas* ControladorPartidas::getInstance() {
    if (instance == nullptr)
        instance = new ControladorPartidas();
    return instance;
}

ControladorPartidas::ControladorPartidas() {
    UltimoId = 1;
}

ControladorPartidas::~ControladorPartidas() {
    for (auto i : partidasSis) {
        delete i.second;
    }
}

std::set<std::string>
ControladorPartidas::obtenerVideojuegosConSuscripcionActiva() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Usuario* usLog = cu->userLogged();
    std::set<Videojuego*> juegosPunt =
        dynamic_cast<Jugador*>(usLog)->obtenerVideojuegosActivos();
    std::set<std::string> juegos;
    for (auto it = juegosPunt.begin(); it != juegosPunt.end(); it++) {
        juegos.insert((*it)->getName());
    }
    return juegos;
}

void ControladorPartidas::selectGame(std::string J) {
    this->JuegoRecordado = J;
}

std::vector<DtPartidaIndividual> ControladorPartidas::listarPartidasIndiv() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Jugador* usLog = dynamic_cast<Jugador*>(cu->userLogged());
    std::vector<DtPartidaIndividual> res = usLog->PartidasIndiv(JuegoRecordado);
    return res;
}

void ControladorPartidas::crearPartidaIndividual(int id) {
    esIndiv = true;
    IdContinuacion = id;
}

std::set<std::string> ControladorPartidas::listarJugadoresActivos() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    return cu->obtenerJugadoresActivos(JuegoRecordado);
}

DtPartidaIndividual ControladorPartidas::getDtPartidaI() {
    FechaSistema* fs = FechaSistema::getInstance();
    DtIndiv =
        DtPartidaIndividual(UltimoId, fs->getFecha(), JuegoRecordado, 0, "", 0,
                            0, (IdContinuacion != -1), IdContinuacion);
    return DtIndiv;
}

DtPartidaMultijugador ControladorPartidas::getDtPartidaM() {
    FechaSistema* fs = FechaSistema::getInstance();
    DtMulti = DtPartidaMultijugador(UltimoId, fs->getFecha(), JuegoRecordado, 0,
                                    "", 0, 0, vivoRec, SetJug);
    return DtMulti;
}

void ControladorPartidas::altaPartida() {
    Partida* part;
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    ControladorVideojuegos* cv = ControladorVideojuegos::getInstance();
    Videojuego* juego;
    Jugador* UsuarioLoged = dynamic_cast<Jugador*>(cu->userLogged());
    if (esIndiv) {
        juego = cv->buscarVideojuego(DtIndiv.getVideojuego());
        PartidaIndividual* cont = NULL;
        if (DtIndiv.getEsContinuacion()) {
            for (auto it = partidasSis.begin(); it != partidasSis.end(); it++) {
                if (it->second->getIdPartida() == DtIndiv.getIdCont()) {
                    cont = dynamic_cast<PartidaIndividual*>(it->second);
                }
            }
        }
        part = new PartidaIndividual(DtIndiv, UsuarioLoged, cont, juego);
    } else {
        juego = cv->buscarVideojuego(DtMulti.getVideojuego());
        part = new PartidaMultijugador(DtMulti, UsuarioLoged, juego);
    }
    juego->addPartida(part);
    partidasSis.insert(std::pair<int, Partida*>(UltimoId, part));
    UltimoId++;
    cu->addPartida(part,
                   (dynamic_cast<Jugador*>(cu->userLogged())->getNickname()));
}

void ControladorPartidas::terminarPartida(int idPartida) {
    FechaSistema* fs = FechaSistema::getInstance();
    DtFechaHora fechaActual = fs->getFecha();
    auto busqueda = this->partidasSis.find(idPartida);
    Partida* p = busqueda->second;
    DtFechaHora fInicio = p->getFechaInicio();
    float d = fechaActual - fInicio;
    float totalHoras = d;

    p->setDuracion(d);
    p->setTerminada(true);

    PartidaMultijugador* pMul = dynamic_cast<PartidaMultijugador*>(p);
    if (pMul != NULL) {
        // p era una PartidaMultijugador
        std::set<PMJ*> participantes = pMul->getParticipantes();
        for (std::set<PMJ*>::iterator it = participantes.begin();
             it != participantes.end(); it++) {
            if (!(*it)->getSalida()) {
                (*it)->setHoraAbandono(fechaActual);
                totalHoras += d;
            } else {
                totalHoras += (*it)->getHoraAbandono() - p->getFechaInicio();
            }
        }
    }

    p->getVideojuegoObj()->addHorasJuego((double)totalHoras);
}

void ControladorPartidas::agregarJugador(std::set<std::string> s, bool v) {
    esIndiv = false;
    this->SetJug = s;
    this->vivoRec = v;
}

std::set<DtPartidaIndividual> ControladorPartidas::consultarPartidasActivasI() {
    std::set<DtPartidaIndividual> res;
    ControladorUsuarios* cu;
    cu = ControladorUsuarios::getInstance();
    Usuario* us = cu->userLogged();
    Jugador* j = dynamic_cast<Jugador*>(us);
    std::set<Partida*> partidas = j->getPartidasIniciadas();

    for (auto it : partidas) {
        if (!it->getTerminada()) {
            int id = it->getVideojuegoObj()->getId();
            PartidaIndividual* pInd = dynamic_cast<PartidaIndividual*>(it);
            if (pInd != NULL) {
                int idCont = (pInd->getContinuaPartida())
                                 ? pInd->getContinuacion()->getIdPartida()
                                 : 0;
                DtPartidaIndividual dt = DtPartidaIndividual(
                    pInd->getIdPartida(), pInd->getFechaInicio(),
                    pInd->getVideojuego(), pInd->getDuracion(),
                    pInd->getInicia()->getNickname(), pInd->getTerminada(), id,
                    pInd->getContinuaPartida(), idCont);

                res.insert(dt);
            }
        }
    }
    return res;
}

std::set<DtPartidaMultijugador>
ControladorPartidas::consultarPartidasActivasM() {
    std::set<DtPartidaMultijugador> res;
    ControladorUsuarios* cu;
    cu = ControladorUsuarios::getInstance();
    Usuario* us = cu->userLogged();
    Jugador* j = dynamic_cast<Jugador*>(us);
    std::set<Partida*> partidas = j->getPartidasIniciadas();

    for (auto it : partidas) {
        if (!it->getTerminada()) {
            int id = it->getVideojuegoObj()->getId();
            PartidaMultijugador* pMul = dynamic_cast<PartidaMultijugador*>(it);
            if (pMul != NULL) {
                std::set<std::string> participantes;
                std::set<PMJ*> p = pMul->getParticipantes();
                for (auto k : p) {
                    participantes.insert(k->getJugador()->getNickname());
                }
                DtPartidaMultijugador dt = DtPartidaMultijugador(
                    pMul->getIdPartida(), pMul->getFechaInicio(),
                    pMul->getVideojuego(), pMul->getDuracion(),
                    pMul->getInicia()->getNickname(), pMul->getTerminada(), id,
                    pMul->getTransmitidaEnVivo(), participantes);
                res.insert(dt);
            }
        }
    }
    return res;
}

std::vector<DtPartidaMultijugador> ControladorPartidas::partidasAbandonar() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Jugador* jug = dynamic_cast<Jugador*>(cu->userLogged());
    return jug->partidasAbandonarJug();
}

void ControladorPartidas::Abandonar(int id) {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Jugador* jug = dynamic_cast<Jugador*>(cu->userLogged());
    jug->AbandonarJug(id);
}

void ControladorPartidas::quitarPartida(int part) {
    partidasSis.erase(part);
}