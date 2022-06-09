#include "header\Fabrica.hpp"

    Fabrica::Fabrica(){}

    IControladorEstadia *Fabrica::getControladorEstadia(){
        return ControladorEstadia::getInstancia();
    }

    IControladorHostal * Fabrica::getControladorHostal(){
        return ControladorHostal::getInstancia();
    }

    IControladorReserva * Fabrica::getControladorReserva(){
        return ControladorReserva::getInstancia();
    }

    IControladorUsuario * Fabrica::getControladorUsuario(){
        return ControladorUsuario::getInstancia();
    }

    IFechaSistema * Fabrica::getFechaSistema(){
        return FechaSistema::getInstancia();
    }