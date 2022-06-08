#include "header\Fabrica.hpp"

    Fabrica::Fabrica(){}

    ControladorEstadia *Fabrica::getControladorEstadia(){
        return ControladorEstadia::getInstancia();
    }

    ControladorHostal * Fabrica::getControladorHostal(){
        return ControladorHostal::getInstancia();
    }

    ControladorReserva * Fabrica::getControladorReserva(){
        return ControladorReserva::getInstancia();
    }

    ControladorUsuario * Fabrica::getControladorUsuario(){
        return ControladorUsuario::getInstancia();
    }
