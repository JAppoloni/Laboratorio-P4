#include "header/DTFecha.hpp"
#include <iostream>
#include <stdexcept>
#include <math.h> // para usar ceil()

int DTFecha::getDia()
{
    return this->fecha.tm_mday;
}

int DTFecha::getMes()
{
    return this->fecha.tm_mon;
}

int DTFecha::getAnio()
{
    return this->fecha.tm_year + 1900;
}

int DTFecha::getHora()
{
    return this->fecha.tm_hour;
}

int DTFecha::getSegundos()
{
    return this->fecha.tm_sec;
}

int DTFecha::getDweek()
{
    return this->fecha.tm_wday;
}

int DTFecha::getMinutos()
{
    return this->fecha.tm_min;
}

int DTFecha::diferenciaDias(DTFecha fchAComparar)
{
    DTFecha aux = DTFecha(this->fecha);
    time_t fecha1 = mktime(&aux.fecha);
    DTFecha aux2 = DTFecha(fchAComparar);
    time_t fecha2 = mktime(&aux2.fecha);
    double diffTime = difftime(fecha2, fecha1);
    return ceil(abs(diffTime / ((float)24 * 60 * 60)));
}

DTFecha::DTFecha()
{
    this->fecha.tm_mday = 0;
    this->fecha.tm_mon = 0;
    this->fecha.tm_year = 0;
    this->fecha.tm_hour = 0;
    this->fecha.tm_min = 0;
    this->fecha.tm_sec = 0;
    this->fecha.tm_wday = 0;
    this->fecha.tm_yday = 0;
    this->fecha.tm_isdst = 0;
    this->fecha.tm_gmtoff = 0;
    this->fecha.tm_zone = nullptr;
}
DTFecha::DTFecha(const DTFecha &fch)
{
    this->fecha = fch.fecha;
}

DTFecha::DTFecha(DTFecha *fch)
{
    if (fch != nullptr)
    {
        this->fecha = fch->fecha;
    }
}

DTFecha::~DTFecha() {}

DTFecha::DTFecha(tm fch)
{
    this->fecha.tm_sec = fch.tm_sec;
    this->fecha.tm_min = fch.tm_min;
    this->fecha.tm_hour = fch.tm_hour;
    this->fecha.tm_mday = fch.tm_mday;
    this->fecha.tm_mon = fch.tm_mon;
    this->fecha.tm_year = fch.tm_year;
    this->fecha.tm_wday = fch.tm_wday;
    this->fecha.tm_yday = fch.tm_yday;
    this->fecha.tm_isdst = fch.tm_isdst;
    this->fecha.tm_gmtoff = fch.tm_gmtoff;
    this->fecha.tm_zone = nullptr;
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
        this->fecha.tm_sec = 00;
        this->fecha.tm_min = min;
        this->fecha.tm_hour = hh;
        this->fecha.tm_mday = dd;
        this->fecha.tm_mon = mm;
        this->fecha.tm_year = yyyy - 1900;
        this->fecha.tm_wday = 0;
        this->fecha.tm_yday = 0;
        this->fecha.tm_isdst = 0;
        this->fecha.tm_gmtoff = 0;
        this->fecha.tm_zone = nullptr;
    }
}

DTFecha DTFecha::operator+(const tm &fch)
{
    tm *auxfch = new struct tm;

    auxfch->tm_sec = this->fecha.tm_sec + fch.tm_sec;
    auxfch->tm_min = this->fecha.tm_min + fch.tm_min;
    auxfch->tm_hour = this->fecha.tm_hour + fch.tm_hour;
    auxfch->tm_mday = this->fecha.tm_mday + fch.tm_mday;
    auxfch->tm_mon = this->fecha.tm_mon + fch.tm_mon;
    auxfch->tm_year = this->fecha.tm_year + fch.tm_year;
    auxfch->tm_wday = this->fecha.tm_wday + fch.tm_wday;
    auxfch->tm_yday = this->fecha.tm_yday + fch.tm_yday;
    auxfch->tm_isdst = fch.tm_isdst;
    auxfch->tm_gmtoff = 0;
    auxfch->tm_zone = nullptr;
    DTFecha rtnFecha = DTFecha(*auxfch);
    delete auxfch;
    return rtnFecha;
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
        this->fecha.tm_sec = 00;
        this->fecha.tm_min = min;
        this->fecha.tm_hour = hh;
        this->fecha.tm_mday = dd;
        this->fecha.tm_mon = mm;
        this->fecha.tm_year = yyyy - 1900;
        this->fecha.tm_wday = wday;
        this->fecha.tm_yday = 0;
        this->fecha.tm_isdst = 0;
        this->fecha.tm_gmtoff = 0;
        this->fecha.tm_zone = nullptr;
    }
}

bool DTFecha::operator!=(const DTFecha &c) const
{
    return !(&fecha == &c.fecha);
}

bool DTFecha::operator==(const DTFecha &c) const
{
    if (&fecha.tm_year == &c.fecha.tm_year && &fecha.tm_mon == &c.fecha.tm_mon && &fecha.tm_mday == &c.fecha.tm_mday && &fecha.tm_hour == &c.fecha.tm_hour && &fecha.tm_min == &c.fecha.tm_min && &fecha.tm_sec == &c.fecha.tm_sec)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DTFecha::operator>=(const DTFecha &c) const
{
    if (this->fecha.tm_year > c.fecha.tm_year)
    {
        return true;
    }
    else if (this->fecha.tm_year == c.fecha.tm_year)
    {
        if (this->fecha.tm_mon > c.fecha.tm_mon)
        {
            return true;
        }
        else if (this->fecha.tm_mon == c.fecha.tm_mon)
        {
            if (this->fecha.tm_mday > c.fecha.tm_mday)
            {
                return true;
            }
            else if (this->fecha.tm_mday == c.fecha.tm_mday)
            {
                if (this->fecha.tm_hour > c.fecha.tm_hour)
                {
                    return true;
                }
                else if (this->fecha.tm_hour == c.fecha.tm_hour)
                {
                    if (this->fecha.tm_min > c.fecha.tm_min)
                    {
                        return true;
                    }
                    else if (this->fecha.tm_min == c.fecha.tm_min)
                    {
                        if (this->fecha.tm_sec >= c.fecha.tm_sec)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool DTFecha::operator<=(const DTFecha &c) const
{

    return (&c.fecha >= &fecha);
}

bool DTFecha::operator>(const DTFecha &c) const
{
    if (&fecha == &c.fecha)
        return false;

    return (&fecha >= &c.fecha);
}

bool DTFecha::operator<(const DTFecha &c) const
{
    return (&c.fecha > &fecha);
}

void DTFecha::Imprimir()
{
    tm *fch = &(this->fecha);
    std::cout << asctime(fch);
}

std::ostream &operator<<(std::ostream &out, DTFecha fch)
{
    fch.Imprimir();
    return out;
}

DTFecha &DTFecha::operator=(const DTFecha &assign)
{
    this->fecha.tm_sec = assign.fecha.tm_sec;
    this->fecha.tm_min = assign.fecha.tm_min;
    this->fecha.tm_hour = assign.fecha.tm_hour;
    this->fecha.tm_mday = assign.fecha.tm_mday;
    this->fecha.tm_mon = assign.fecha.tm_mon;
    this->fecha.tm_year = assign.fecha.tm_year;
    this->fecha.tm_wday = assign.fecha.tm_wday;
    this->fecha.tm_yday = assign.fecha.tm_yday;
    this->fecha.tm_isdst = assign.fecha.tm_isdst;
    this->fecha.tm_gmtoff = assign.fecha.tm_gmtoff;
    this->fecha.tm_zone = assign.fecha.tm_zone;
    return *this;
}