#include "header/ControladorEstadia.hpp"

ControladorEstadia * ControladorEstadia::instancia = nullptr;

ControladorEstadia::ControladorEstadia(){}

ControladorEstadia * ControladorEstadia::getInstancia(){
    ControladorEstadia * res = instancia; 
    if (res == nullptr){
        res = new ControladorEstadia();
    };
    return res;
}