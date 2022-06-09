#include "header\ControladorHostal.hpp"

ControladorHostal * ControladorHostal::instancia = nullptr;

ControladorHostal::ControladorHostal(){}

ControladorHostal * ControladorHostal::getInstancia(){
    ControladorHostal * res = instancia; 
    if (res == nullptr){
        res = new ControladorHostal();
    };
    return res;
}