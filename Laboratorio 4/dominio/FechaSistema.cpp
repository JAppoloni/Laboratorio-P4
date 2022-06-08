#include "header\FechaSistema.hpp"

FechaSistema * FechaSistema::instancia = nullptr;

FechaSistema::FechaSistema(){}

FechaSistema * FechaSistema::getInstancia(){
    FechaSistema * res = instancia; 
    if (res == nullptr){
        res = new FechaSistema();
    };
    return res;
}