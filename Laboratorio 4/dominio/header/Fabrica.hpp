#ifndef FABRICA
#define FABRICA

#include "ControladorEstadia.hpp"
#include "ControladorHostal.hpp"
#include "ControladorReserva.hpp"
#include "ControladorUsuario.hpp"

class Fabrica{
    public:
        Fabrica();
        ControladorEstadia * getControladorEstadia();
        ControladorHostal * getControladorHostal();
        ControladorReserva * getControladorReserva();
        ControladorUsuario * getControladorUsuario();
}

#endif