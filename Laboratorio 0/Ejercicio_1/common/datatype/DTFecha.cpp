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
    return ((fchAComparar.anio - this->anio) * 12 * 31 + (fchAComparar.mes - this->mes) * 31 + (fchAComparar.dia - this->dia));
}

void DTFecha::imprimir()
{
    std::cout << this->dia << "//" << this->mes << "//" << this->anio;
}

DTFecha::DTFecha(int dia, int mes, int anio)
{
    if ((dia > 31) || (dia < 1) || (mes > 12) || (mes < 1) || (anio < 1900))
    {
        throw std::invalid_argument("Fecha invalida");
    }
    else
    {
        this->anio = anio;
        this->dia = dia;
        this->mes = mes;
    }
}

bool DTFecha::operator!=(const DTFecha &c) const
{
    return ((this->anio != c.anio) || (this->mes != c.mes) || (this->dia != c.dia));
}

bool DTFecha::operator==(const DTFecha &c) const
{
    return ((this->anio == c.anio) && (this->mes == c.mes) && (this->dia == c.dia));
}

bool DTFecha::operator>=(const DTFecha &c) const
{
    if (this->anio > c.anio)
        return true;
    else if (this->anio == c.anio)
    {
        if (this->mes > c.mes)
            return true;
        else if (this->mes == c.mes)
            if (this->dia >= c.dia)
                return true;
    }
    return false;
}

bool DTFecha::operator<=(const DTFecha &c) const
{
    
    return (c >= *this);
}

bool DTFecha::operator>(const DTFecha &c) const
{
    if (this->anio > c.anio)
        return true;
    else if (this->anio == c.anio)
    {
        if (this->mes > c.mes)
            return true;
        else if (this->mes == c.mes)
            if (this->dia > c.dia)
                return true;
    }
    return false;
}

bool DTFecha::operator<(const DTFecha &c) const
{
    return (c > *this );
}
