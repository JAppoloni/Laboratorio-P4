#include "header/ControladorReserva.hpp"

ControladorReserva * ControladorReserva::instancia = nullptr;

ControladorReserva::ControladorReserva(){}

ControladorReserva * ControladorReserva::getInstancia(){
    ControladorReserva * res = instancia; 
    if (res == nullptr){
        res = new ControladorReserva();
    };
    return res;
}