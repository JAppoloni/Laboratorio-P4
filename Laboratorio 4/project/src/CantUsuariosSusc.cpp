#include "../include/CantUsuariosSusc.hpp"

#include <set>
#include <string>
#include "../include/ControladorUsuarios.hpp"

CantUsuariosSusc::CantUsuariosSusc(std::string name, std::string desc)
    : Estadistica(name, desc) {}

double CantUsuariosSusc::getDato(Videojuego* vj) {
    std::string nomJuego = vj->getName();
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();

    std::set<std::string> jug_suscritos = cu->obtenerJugadoresActivos(nomJuego);
    return (double)jug_suscritos.size();
}