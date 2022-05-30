#include "../include/ControladorEstadisticas.hpp"

#include "../include/ControladorUsuarios.hpp"
#include "../include/Desarrollador.hpp"

ControladorEstadisticas* ControladorEstadisticas::instance = nullptr;

ControladorEstadisticas::ControladorEstadisticas() {
    setEstSis.insert(new CantUsuariosSusc(
        "Cantidad de Usuarios suscritos",
        "Cuenta de la cantidad de usuarios con suscripciones activas a "
        "determinado juego."));

    setEstSis.insert(new HorasTotalesJuego(
        "Cantidad de horas de juego",
        "Cuenta de la cantidad de horas cumulativas de juego a alguno "
        "determinado."));
}

ControladorEstadisticas* ControladorEstadisticas::getInstance() {
    if (instance == nullptr) {
        instance = new ControladorEstadisticas();
    }
    return instance;
}

ControladorEstadisticas::~ControladorEstadisticas() {
    for (auto i : setEstSis) {
        delete i;
    }
}

/* ### OPS ### */

std::set<std::string>
ControladorEstadisticas::listarVideojuegosDesarrollador() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Desarrollador* des = dynamic_cast<Desarrollador*>(cu->userLogged());
    return des->getNombresJuegos();
}

// Catchear exception en main
void ControladorEstadisticas::selVideojuego(std::string vj_sel) {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Desarrollador* des = dynamic_cast<Desarrollador*>(cu->userLogged());
    videojuego_sel = des->buscarJuegoPorNombre(vj_sel);
}

DtEstadistica ControladorEstadisticas::crearDtEst(std::string name,
                                                  double dato) {
    return DtEstadistica(name, dato);
}

std::set<DtEstadistica> ControladorEstadisticas::obtenerEstadisticas() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Desarrollador* des = dynamic_cast<Desarrollador*>(cu->userLogged());
    std::set<Estadistica*> setEst = des->getEstadisticasDes();

    std::set<DtEstadistica> setDtEst;
    for (auto i : setEst) {
        setDtEst.insert(crearDtEst(i->getName(), i->getDato(videojuego_sel)));
    }
    return setDtEst;
}

std::vector<std::pair<std::string, std::string>>
ControladorEstadisticas::listarEstadisticas() {
    std::vector<std::pair<std::string, std::string>> ret;

    for (auto e : setEstSis) {
        ret.push_back(
            std::pair<std::string, std::string>(e->getName(), e->getDesc()));
    }

    return ret;
}

void ControladorEstadisticas::seleccionarEstadistica(std::string vj) {
    Estadistica* estSel = nullptr;
    for (auto e : setEstSis) {
        if (vj == e->getName()) {
            estSel = e;
            break;
        }
    }

    if (estSel == nullptr) {
        throw std::invalid_argument("Estadistica no encontrada");
    }

    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Desarrollador* des = dynamic_cast<Desarrollador*>(cu->userLogged());

    des->getEstDev()->addEstadistica(estSel);
}
