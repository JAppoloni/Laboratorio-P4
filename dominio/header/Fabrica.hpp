#ifndef FABRICA
#define FABRICA

#include "ControladorEstadia.hpp"
#include "ControladorHostal.hpp"
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
        void liberarMemoria();
};

#endif