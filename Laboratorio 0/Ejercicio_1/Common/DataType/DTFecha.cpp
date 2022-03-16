#include "header/DTFecha.hpp"
#include <iostream>

int DTFecha::getDia() { 
    return this->dia; 
}

int DTFecha::getMes() { 
    return this->mes; 
}

int DTFecha::getAnio() { 
    return this->anio; 
}

void DTFecha::imprimir() { 
    std::cout << this->dia << "//" << this->mes << "//" << this->anio; 
}

DTFecha::DTFecha(int dia, int mes, int anio) {
    if ((dia > 31) || (dia < 1) || (mes > 12) || (mes < 1) || (anio < 1900) )
        throw std::invalid_argument("Fecha invalida");
    else {
        this->anio = anio;
        this->dia = dia;
        this->mes = mes;
    }
}
