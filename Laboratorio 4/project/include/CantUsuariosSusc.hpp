#include <string>
#include "Estadistica.hpp"

#ifndef CANTUSUARIOSSUSC_HPP
#define CANTUSUARIOSSUSC_HPP

class CantUsuariosSusc : public Estadistica {
   public:
    CantUsuariosSusc(std::string name, std::string desc);
    ~CantUsuariosSusc() = default;
    double getDato(Videojuego*);
};

#endif