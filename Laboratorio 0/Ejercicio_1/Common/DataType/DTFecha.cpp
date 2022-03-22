#include "header/DTFecha.hpp"
#include <iostream>
#include <stdexcept>

int DTFecha::getDia()
{
    return this->dia;
}

int DTFecha::getMes()
{
    return this->mes;
}

int DTFecha::getAnio()
{
    return this->anio;
}

int DTFecha::calcularDias(DTFecha fchAComparar)
{
    return ((fchAComparar.anio - this->anio) * 12 * 30 + (fchAComparar.mes - this->mes) * 30 + (fchAComparar.dia - this->dia));
}

void DTFecha::imprimir()
{
    std::cout << this->dia << "//" << this->mes << "//" << this->anio;
}

DTFecha::DTFecha(int dia, int mes, int anio)
{
    if ((dia > 31) || (dia < 1) || (mes > 12) || (mes < 1) || (anio < 1900)) {
        throw std::invalid_argument("Fecha invalida");
    } else {
        this->anio = anio;
        this->dia = dia;
        this->mes = mes;
    }
}

bool DTFecha::operator == (const DTFecha &fecha) const 
{
    return this->mes == fecha.mes && this->anio == fecha.anio && this->dia==fecha.dia;
}