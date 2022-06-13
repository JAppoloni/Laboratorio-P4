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

DTFecha::DTFecha(tm fch)
{
    this->fecha = new struct tm;
    this->fecha->tm_sec = fch.tm_sec;
    this->fecha->tm_min = fch.tm_min;
    this->fecha->tm_hour = fch.tm_hour;
    this->fecha->tm_mday = fch.tm_mday;
    this->fecha->tm_mon = fch.tm_mon;
    this->fecha->tm_year = fch.tm_year;
    this->fecha->tm_wday = fch.tm_wday;
    this->fecha->tm_yday = fch.tm_yday;
    this->fecha->tm_isdst = fch.tm_isdst;
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
        this->fecha->tm_sec = 00;
        this->fecha->tm_min = min;
        this->fecha->tm_hour = hh;
        this->fecha->tm_mday = dd;
        this->fecha->tm_mon = mm;
        this->fecha->tm_year = yyyy;
    }
}

DTFecha DTFecha::operator+(const tm &fch)
{
    DTFecha res;
    res.fecha = new struct tm;
    res.fecha->tm_sec = this->fecha->tm_sec + fch.tm_sec;
    res.fecha->tm_min = this->fecha->tm_min + fch.tm_min;
    res.fecha->tm_hour = this->fecha->tm_hour + fch.tm_hour;
    res.fecha->tm_mday = this->fecha->tm_mday + fch.tm_mday;
    res.fecha->tm_mon = this->fecha->tm_mon + fch.tm_mon;
    res.fecha->tm_year = this->fecha->tm_year + fch.tm_year;
    res.fecha->tm_wday = this->fecha->tm_wday + fch.tm_wday;
    res.fecha->tm_yday = this->fecha->tm_yday + fch.tm_yday;
    mktime(res.fecha);
    return res;
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
        this->fecha = new tm;
        this->fecha->tm_sec = 00;
        this->fecha->tm_min = min;
        this->fecha->tm_hour = hh;
        this->fecha->tm_mday = dd;
        this->fecha->tm_mon = mm;
        this->fecha->tm_year = yyyy;
        this->fecha->tm_wday = wday;
    }
}

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

DTFecha &DTFecha::operator=(const DTFecha &assign)
{
    this->fecha = new tm;
    this->fecha->tm_sec = assign.fecha->tm_sec;
    this->fecha->tm_min = assign.fecha->tm_min;
    this->fecha->tm_hour = assign.fecha->tm_hour;
    this->fecha->tm_mday = assign.fecha->tm_mday;
    this->fecha->tm_mon = assign.fecha->tm_mon;
    this->fecha->tm_year = assign.fecha->tm_year;
    this->fecha->tm_wday = assign.fecha->tm_wday;
    return *this;
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