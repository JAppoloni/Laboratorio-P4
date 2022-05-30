#include "../include/DtJugador.hpp"

DtJugador::DtJugador(std::string email, std::string password, std::string nick)
    : DtUsuario(email, password) {
    this->nick = nick;
}

std::string DtJugador::getNick() {
    return nick;
}