#include "../include/ControladorVideojuegos.hpp"
#include <exception>
#include "../include/ControladorPartidas.hpp"
#include "../include/ControladorUsuarios.hpp"
#include "../include/Desarrollador.hpp"
#include "../include/DtVideojuego.hpp"
#include "../include/FechaSistema.hpp"
#include "../include/Jugador.hpp"
#include "../include/Usuario.hpp"
#include "../include/Videojuego.hpp"

ControladorVideojuegos* ControladorVideojuegos::instance = nullptr;

ControladorVideojuegos* ControladorVideojuegos::getInstance() {
    if (instance == nullptr) {
        instance = new ControladorVideojuegos();
    }
    return instance;
}

ControladorVideojuegos::ControladorVideojuegos() {
    ultimo_id = 1;
}

ControladorVideojuegos::~ControladorVideojuegos() {
    for (auto i : ColJuegos) {
        delete i;
    }
    for (auto i : ColGeneros) {
        delete i;
    }
    for (auto i : ColOtros) {
        delete i;
    }
    for (auto i : ColTiposDePlataforma) {
        delete i;
    }
}

std::set<DtVideojuego>
ControladorVideojuegos::obtenerVideojuegosConSuscripcionActiva() {
    std::set<DtVideojuego> res;
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Jugador* usLog = dynamic_cast<Jugador*>(cu->userLogged());
    std::set<Videojuego*> videojuegosActivos =
        usLog->obtenerVideojuegosActivos();
    for (std::set<Videojuego*>::iterator it = videojuegosActivos.begin();
         it != videojuegosActivos.end(); it++) {
        DtVideojuego elemento =
            DtVideojuego((*it)->getName(), (*it)->getDescripcion(),
                         (*it)->getCosto(), (*it)->getDtCatGenero(),
                         (*it)->getDtCatOtros(), (*it)->getDtCatPlataforma());
        res.insert(elemento);
    }
    return res;
}

std::set<DtVideojuego>
ControladorVideojuegos::obtenerVideojuegosSinSuscripcionActiva() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Jugador* usLog = dynamic_cast<Jugador*>(cu->userLogged());
    std::set<Videojuego*> videojuegosActivos =
        usLog->obtenerVideojuegosActivos();
    std::set<DtVideojuego> res;
    for (auto itJuegos : ColJuegos) {
        if (videojuegosActivos.count(itJuegos) == 0) {
            DtVideojuego elemento = DtVideojuego(
                itJuegos->getName(), itJuegos->getDescripcion(),
                itJuegos->getCosto(), itJuegos->getDtCatGenero(),
                itJuegos->getDtCatOtros(), itJuegos->getDtCatPlataforma());
            res.insert(elemento);
        }
    }
    return res;
}

std::pair<bool, bool> ControladorVideojuegos::seleccionarVideojuego(
    std::string nombre) {
    alQueSeQuiereSuscribir = nullptr;
    std::pair<bool, bool> res;
    bool suscripto = false;
    bool vitalicia = false;
    for (std::set<Videojuego*>::iterator it = ColJuegos.begin();
         it != ColJuegos.end(); it++) {
        if (nombre.compare((*it)->getName()) == 0) {
            alQueSeQuiereSuscribir = (*it);
        }
    }
    if (alQueSeQuiereSuscribir == nullptr) {
        throw std::invalid_argument("Videojuego no encontrado.");
    } else {
        ControladorUsuarios* cu = ControladorUsuarios::getInstance();
        Jugador* usLog = dynamic_cast<Jugador*>(cu->userLogged());
        suscripto = usLog->videojuegoActivo(alQueSeQuiereSuscribir->getName());
        if (suscripto) {
            vitalicia = usLog->esVitalicia(alQueSeQuiereSuscribir->getName());
        }
        res = std::make_pair(suscripto, vitalicia);
    }
    return res;
}

void ControladorVideojuegos::suscripcion(TiposSuscripcion tipoDeSuscripcion,
                                         TFormasPago tfp) {
    tipoDeSuscripcionNuevaSus = tipoDeSuscripcion;
    tFormaDePagoNuevaSus = tfp;
}

void ControladorVideojuegos::cancelarSuscripcion() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Jugador* usLog = dynamic_cast<Jugador*>(cu->userLogged());
    usLog->desactivarSuscripcion(alQueSeQuiereSuscribir);
}

void ControladorVideojuegos::altaSuscripcion() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    FechaSistema* fs = FechaSistema::getInstance();
    Jugador* usLog = dynamic_cast<Jugador*>(cu->userLogged());
    usLog->activarSuscripcion(alQueSeQuiereSuscribir, fs->getFecha(),
                              tipoDeSuscripcionNuevaSus, tFormaDePagoNuevaSus);
}

std::set<Genero*> ControladorVideojuegos::getColGeneros() {
    return this->ColGeneros;
}

std::set<Otros*> ControladorVideojuegos::getColOtros() {
    return this->ColOtros;
}

std::set<TipoDePlataforma*> ControladorVideojuegos::getColTiposDePlataforma() {
    return this->ColTiposDePlataforma;
}

std::set<DtCategoria> ControladorVideojuegos::listarCategorias() {
    std::set<DtCategoria> res;
    for (auto it = ColGeneros.begin(); it != ColGeneros.end(); it++) {
        res.insert(
            DtCategoria((*it)->getNombre(), (*it)->getDescripcion(), genero));
    }
    for (auto it = ColOtros.begin(); it != ColOtros.end(); it++) {
        res.insert(
            DtCategoria((*it)->getNombre(), (*it)->getDescripcion(), otro));
    }
    for (auto it = ColTiposDePlataforma.begin();
         it != ColTiposDePlataforma.end(); it++) {
        res.insert(DtCategoria((*it)->getNombre(), (*it)->getDescripcion(),
                               plataforma));
    }
    return res;
}

DtCategoria ControladorVideojuegos::crearCategoria(std::string nombre,
                                                   std::string descripcion,
                                                   TipoCat tipo) {
    DtCategoria res = DtCategoria(nombre, descripcion, tipo);
    return res;
}

void ControladorVideojuegos::altaCategoria(DtCategoria categoria) {
    switch (categoria.getTipo()) {
        case plataforma: {
            TipoDePlataforma* nueva = new TipoDePlataforma(
                categoria.getNombre(), categoria.getDescripcion());
            this->ColTiposDePlataforma.insert(nueva);
        } break;
        case genero: {
            Genero* nueva =
                new Genero(categoria.getNombre(), categoria.getDescripcion());
            this->ColGeneros.insert(nueva);
        } break;
        case otro: {
            Otros* nueva =
                new Otros(categoria.getNombre(), categoria.getDescripcion());
            this->ColOtros.insert(nueva);
        } break;
    }
}

Videojuego* ControladorVideojuegos::buscarVideojuego(std::string s) {
    Videojuego* ret;
    for (auto it = ColJuegos.begin(); it != ColJuegos.end(); it++) {
        if ((*it)->getName() == s) {
            ret = (*it);
        }
    }
    return ret;
}

std::set<std::pair<std::string, std::string>>
ControladorVideojuegos::obtenerJuegos() {
    std::set<std::pair<std::string, std::string>> res;
    for (std::set<Videojuego*>::iterator it = ColJuegos.begin();
         it != ColJuegos.end(); it++) {
        std::pair<std::string, std::string> auxiliarJuego;
        auxiliarJuego =
            std::make_pair((*it)->getName(), (*it)->getDescripcion());
        res.insert(auxiliarJuego);
    }
    return res;
}

void ControladorVideojuegos::puntuarJuego(std::string nombre, int p) {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Jugador* usLog = dynamic_cast<Jugador*>(cu->userLogged());
    Videojuego* vid = nullptr;
    for (std::set<Videojuego*>::iterator it = ColJuegos.begin();
         it != ColJuegos.end(); it++) {
        if (nombre.compare((*it)->getName()) == 0) {
            vid = (*it);
        }
    }
    if (vid == nullptr) {
        throw std::invalid_argument("Videojuego no encontrado.");
    } else {
        usLog->puntuar(vid, p);
    }
}

std::set<std::string> ControladorVideojuegos::nombresVideojuegos() {
    std::set<std::string> res;
    for (std::set<Videojuego*>::iterator it = ColJuegos.begin();
         it != ColJuegos.end(); it++) {
        std::string auxiliarJuego;
        auxiliarJuego = (*it)->getName();
        res.insert(auxiliarJuego);
    }
    return res;
}

std::pair<DtVideojuego, double> ControladorVideojuegos::infoDetalladaVideojuego(
    std::string nombre) {
    Videojuego* vid = nullptr;
    for (std::set<Videojuego*>::iterator it = ColJuegos.begin();
         it != ColJuegos.end(); it++) {
        if (nombre.compare((*it)->getName()) == 0) {
            vid = (*it);
        }
    }
    std::pair<DtVideojuego, double> res;
    if (vid == nullptr) {
        throw std::invalid_argument("Videojuego no encontrado.");
    } else {
        DtVideojuego dtv =
            DtVideojuego(vid->getName(), vid->getDescripcion(),
                         vid->getCostos(), vid->getDtCatGenero(),
                         vid->getDtCatOtros(), vid->getDtCatPlataforma());
        res = std::make_pair(dtv, vid->getHorasDeJuego());
    }
    return res;
}

void ControladorVideojuegos::agregarVideojuego(std::string nombre,
                                               std::string descripcion,
                                               DtCosto costo) {
    nombrerecordado = nombre;
    descripcionrecordada = descripcion;
    costorecordado = costo;
}

std::set<DtCategoria> ControladorVideojuegos::consultarCategoria(TipoCat tipo) {
    std::set<DtCategoria> res;
    if (tipo == plataforma) {
        for (std::set<TipoDePlataforma*>::iterator it =
                 ColTiposDePlataforma.begin();
             it != ColTiposDePlataforma.end(); it++) {
            std::string nombrenuevo = (*it)->getNombre();
            std::string descripcion = (*it)->getDescripcion();
            DtCategoria cat(nombrenuevo, descripcion, plataforma);
            res.insert(cat);
        }
    } else if (tipo == genero) {
        for (std::set<Genero*>::iterator it = ColGeneros.begin();
             it != ColGeneros.end(); it++) {
            std::string nombrenuevo = (*it)->getNombre();
            std::string descripcion = (*it)->getDescripcion();
            DtCategoria cat(nombrenuevo, descripcion, genero);
            res.insert(cat);
        }
    } else if (tipo == otro) {
        for (std::set<Otros*>::iterator it = ColOtros.begin();
             it != ColOtros.end(); it++) {
            std::string nombrenuevo = (*it)->getNombre();
            std::string descripcion = (*it)->getDescripcion();
            DtCategoria cat(nombrenuevo, descripcion, otro);
            res.insert(cat);
        }
    }
    return res;
}

void ControladorVideojuegos::elegirCategoriaGenero(std::string gene) {
    for (std::set<Genero*>::iterator it = ColGeneros.begin();
         it != ColGeneros.end(); it++) {
        if ((*it)->getNombre() == gene) {
            GenerosTemporal.insert((*it));
            DtCategoria nuevacat((*it)->getNombre(), (*it)->getDescripcion(),
                                 genero);
            DtGenerosTemporal.insert(nuevacat);
        }
    }
}

void ControladorVideojuegos::elegirCategoriaPlataforma(std::string plat) {
    for (std::set<TipoDePlataforma*>::iterator it =
             ColTiposDePlataforma.begin();
         it != ColTiposDePlataforma.end(); it++) {
        if ((*it)->getNombre() == plat) {
            TiposDePlataformaTemporal.insert((*it));
            DtCategoria nuevacat((*it)->getNombre(), (*it)->getDescripcion(),
                                 plataforma);
            DtTiposDePlataformaTemporal.insert(nuevacat);
        }
    }
}

void ControladorVideojuegos::elegirOtraCategoria(std::string otr) {
    for (std::set<Otros*>::iterator it = ColOtros.begin(); it != ColOtros.end();
         it++) {
        if ((*it)->getNombre() == otr) {
            OtrasTemporal.insert((*it));
            DtCategoria nuevacat((*it)->getNombre(), (*it)->getDescripcion(),
                                 otro);
            DtOtrasTemporal.insert(nuevacat);
        }
    }
}

DtVideojuego ControladorVideojuegos::obtenerDatosIngresadosVideojuego() {
    DtVideojuego dataVideojuego(nombrerecordado, descripcionrecordada,
                                costorecordado, DtGenerosTemporal,
                                DtOtrasTemporal, DtTiposDePlataformaTemporal);
    return dataVideojuego;
}

void ControladorVideojuegos::abortarPublicacion() {
    TiposDePlataformaTemporal.erase(TiposDePlataformaTemporal.begin(),
                                    TiposDePlataformaTemporal.end());
    GenerosTemporal.erase(GenerosTemporal.begin(), GenerosTemporal.end());
    OtrasTemporal.erase(OtrasTemporal.begin(), OtrasTemporal.end());
    DtTiposDePlataformaTemporal.erase(DtTiposDePlataformaTemporal.begin(),
                                      DtTiposDePlataformaTemporal.end());
    DtGenerosTemporal.erase(DtGenerosTemporal.begin(), DtGenerosTemporal.end());
    DtOtrasTemporal.erase(DtOtrasTemporal.begin(), DtOtrasTemporal.end());
}

void ControladorVideojuegos::confirmarPublicacion() {
    ControladorUsuarios* cu;
    cu = ControladorUsuarios::getInstance();
    Usuario* us = cu->userLogged();
    Desarrollador* d = dynamic_cast<Desarrollador*>(us);
    Videojuego* vj = new Videojuego(
        ultimo_id, nombrerecordado, descripcionrecordada, costorecordado,
        GenerosTemporal, OtrasTemporal, TiposDePlataformaTemporal, d);
    ColJuegos.insert(vj);
    cu->asociarVideojuegoDesarrollador(d, ultimo_id, vj);
    TiposDePlataformaTemporal.erase(TiposDePlataformaTemporal.begin(),
                                    TiposDePlataformaTemporal.end());
    GenerosTemporal.erase(GenerosTemporal.begin(), GenerosTemporal.end());
    OtrasTemporal.erase(OtrasTemporal.begin(), OtrasTemporal.end());
    DtTiposDePlataformaTemporal.erase(DtTiposDePlataformaTemporal.begin(),
                                      DtTiposDePlataformaTemporal.end());
    DtGenerosTemporal.erase(DtGenerosTemporal.begin(), DtGenerosTemporal.end());
    DtOtrasTemporal.erase(DtOtrasTemporal.begin(), DtOtrasTemporal.end());
    ultimo_id++;
}

std::set<std::string>
ControladorVideojuegos::getNombreVideojuegosSinPartidaEnCurso() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Desarrollador* usLog = dynamic_cast<Desarrollador*>(cu->userLogged());
    std::set<std::string> res =
        usLog->getVideojuegosDesarrolladorSinActivas(usLog);
    return res;
}

void ControladorVideojuegos::seleccionarVideojuegoEliminar(std::string vid) {
    std::string nombre;
    bool existejuego = false;
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Desarrollador* usLog = dynamic_cast<Desarrollador*>(cu->userLogged());
    for (std::set<Videojuego*>::iterator it = ColJuegos.begin();
         it != ColJuegos.end(); it++) {
        nombre = (*it)->getName();
        if (vid == nombre && (*it)->getDesarrollador() == usLog) {
            juegoeliminar = (*it);
            existejuego = true;
            break;
        }
    }
    if (!existejuego) {
        throw std::invalid_argument("Videojuego no encontrado");
    }
}

void ControladorVideojuegos::eliminarVideojuego() {
    juegoeliminar->preEliminacion();
    ColJuegos.erase(juegoeliminar);
    delete juegoeliminar;
}

std::set<DtCategoria> ControladorVideojuegos::listarCatsGenero() {
    std::set<DtCategoria> ret;
    for (auto i : ColGeneros) {
        ret.insert(DtCategoria(i->getNombre(), i->getDescripcion(), genero));
    }
    return ret;
}

std::set<DtCategoria> ControladorVideojuegos::listarCatsPlataforma() {
    std::set<DtCategoria> ret;
    for (auto i : ColTiposDePlataforma) {
        ret.insert(
            DtCategoria(i->getNombre(), i->getDescripcion(), plataforma));
    }
    return ret;
}

std::set<DtCategoria> ControladorVideojuegos::listarCatsOtra() {
    std::set<DtCategoria> ret;
    for (auto i : ColOtros) {
        ret.insert(DtCategoria(i->getNombre(), i->getDescripcion(), otro));
    }
    return ret;
}

double ControladorVideojuegos::getPuntaje(std::string nombre) {
    return buscarVideojuego(nombre)->getPuntajePromedio();
}