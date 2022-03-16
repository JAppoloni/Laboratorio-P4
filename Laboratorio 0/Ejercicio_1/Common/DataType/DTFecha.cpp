#include "../../include/DTFecha.h"
#include <iostream>

int DTFecha::getDia() { return this->dia; }
int DTFecha::getMes() { return this->mes; }
int DTFecha::getAnio() { return this->anio; }

void DTFecha::imprimir() { std::cout << this->dia << "//" << this->mes << "//" << this->anio; }

DTFecha::DTFecha(int dia, int mes, int anio)
{
    // !!! VALIDAR DATOS ANTES;

    this->anio = anio;
    this->dia = dia;
    this->mes = mes;
}
