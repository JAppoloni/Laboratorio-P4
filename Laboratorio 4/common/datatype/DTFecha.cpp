#include "header/DTFecha.hpp"
#include <iostream>
#include <stdexcept>
#include <math.h> // para usar ceil()

int DTFecha::getDia()
{
    return this->fecha->tm_mday;
}

int DTFecha::getMes()
{
    return this->fecha->tm_mon;
}

int DTFecha::getAnio()
{
    return this->fecha->tm_year;
}

int DTFecha::getHora()
{
    return this->fecha->tm_hour;
}

int DTFecha::getMinutos()
{
    return this->fecha->tm_min;
}

int DTFecha::diferenciaDias(DTFecha fchAComparar)
{
    return ceil(difftime(mktime(this->fecha), mktime(fchAComparar.fecha)) / (24 * 60 * 60));
}

DTFecha::DTFecha()
{
    this->fecha = nullptr;
}

DTFecha::~DTFecha()
{
    delete this->fecha;
}

DTFecha::DTFecha(int min, int hh, int dd, int mm, int yyyy)
{
    if ((dd > 31) || (dd < 1) || (mm > 11) || (mm < 0) || (yyyy < 1900) ||
        (hh > 23) || (hh < 0) || (min > 59) || (min < 0))
    {
        throw std::invalid_argument("Fecha invalida");
    }
    else
    {
        this->fecha = new struct tm;
        this->fecha->tm_sec= 00;
        this->fecha->tm_min = min;
        this->fecha->tm_hour = hh;
        this->fecha->tm_mday = dd;
        this->fecha->tm_mon = mm;
        this->fecha->tm_year = yyyy;
    }
}

DTFecha::DTFecha(int min, int hh, int dd, int mm, int yyyy, int wday)
{
    if ((dd > 31) || (dd < 1) || (mm > 11) || (mm < 0) || (yyyy < 1900) || (wday < 0) ||
        (hh > 23) || (hh < 0) || (min > 59) || (min < 0) || (wday > 6))
    {
        throw std::invalid_argument("Fecha invalida");
    }
    else
    {
        this->fecha = new struct tm;
        this->fecha->tm_sec= 00;
        this->fecha->tm_min = min;
        this->fecha->tm_hour = hh;
        this->fecha->tm_mday = dd;
        this->fecha->tm_mon = mm;
        this->fecha->tm_year = yyyy;
        this->fecha->tm_wday = wday;
    }
}

// DTFecha::DTFecha(int dia, int mes, int anio)
// {
//     if ((dia > 31) || (dia < 1) || (mes > 12) || (mes < 1) || (anio < 1900))
//     {
//         throw std::invalid_argument("Fecha invalida");
//     }
//     else
//     {
//         this->anio = anio;
//         this->dia = dia;
//         this->mes = mes;
//     }
// }

bool DTFecha::operator!=(const DTFecha &c) const
{
    return (this->fecha != c.fecha);
}

bool DTFecha::operator==(const DTFecha &c) const
{
    return (this->fecha == c.fecha);
}

bool DTFecha::operator>=(const DTFecha &c) const
{
    return (this->fecha >= c.fecha);
}

bool DTFecha::operator<=(const DTFecha &c) const
{

    return (this->fecha <= c.fecha);
}

bool DTFecha::operator>(const DTFecha &c) const
{
    return (this->fecha > c.fecha);
}

bool DTFecha::operator<(const DTFecha &c) const
{
    return (this->fecha < c.fecha);
}

void DTFecha::Imprimir()
{
    puts(asctime(this->fecha));
}

std::ostream &operator<<(std::ostream &out, DTFecha fch)
{
    fch.Imprimir();
    return out;
}

// bool DTFecha::operator!=(const DTFecha &c) const
// {
//     return ((this->anio != c.anio) || (this->mes != c.mes) || (this->dia != c.dia));
// }

// bool DTFecha::operator==(const DTFecha &c) const
// {
//     return ((this->anio == c.anio) && (this->mes == c.mes) && (this->dia == c.dia));
// }

// bool DTFecha::operator>=(const DTFecha &c) const
// {
//     if (this->anio > c.anio)
//         return true;
//     else if (this->anio == c.anio)
//     {
//         if (this->mes > c.mes)
//             return true;
//         else if (this->mes == c.mes)
//             if (this->dia >= c.dia)
//                 return true;
//     }
//     return false;
// }

// bool DTFecha::operator<=(const DTFecha &c) const
// {

//     return (c >= *this);
// }

// bool DTFecha::operator>(const DTFecha &c) const
// {
//     if (this->anio > c.anio)
//         return true;
//     else if (this->anio == c.anio)
//     {
//         if (this->mes > c.mes)
//             return true;
//         else if (this->mes == c.mes)
//             if (this->dia > c.dia)
//                 return true;
//     }
//     return false;
// }

// bool DTFecha::operator<(const DTFecha &c) const
// {
//     return (c > *this);
// }

// std::ostream &operator<<(std::ostream &out, DTFecha fecha)
// {
//     return out << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio();
// }