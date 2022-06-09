#include "header/ControladorUsuario.hpp"

ControladorUsuario * ControladorUsuario::instancia = nullptr;

ControladorUsuario::ControladorUsuario(){}

ControladorUsuario * ControladorUsuario::getInstancia(){
    ControladorUsuario * res = instancia; 
    if (res == nullptr){
        res = new ControladorUsuario();
    };
    return res;
}