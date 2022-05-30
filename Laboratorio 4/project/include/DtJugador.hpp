#ifndef DTJUG_HPP
#define DTJUG_HPP

#include <string>
#include "DtUsuario.hpp"

class DtJugador : public DtUsuario {
   private:
    std::string nick;

   public:
    DtJugador(std::string email, std::string password, std::string nick);
    DtJugador() = default;
    ~DtJugador() = default;
    std::string getNick();
};

#endif