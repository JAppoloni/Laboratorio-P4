#ifndef FABRICA
#define FABRICA

#include "ControladorEstadia.hpp"
#include "ControladorHostal.hpp"
#include "ControladorReserva.hpp"
#include "ControladorUsuario.hpp"
#include "FechaSistema.hpp"

class Fabrica{
    public:
        Fabrica();
        IControladorEstadia * getControladorEstadia();
        IControladorHostal * getControladorHostal();
        IControladorReserva * getControladorReserva();
        IControladorUsuario * getControladorUsuario();
        IFechaSistema * getFechaSistema();
};

#endif