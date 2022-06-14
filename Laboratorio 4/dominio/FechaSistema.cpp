#include "header/FechaSistema.hpp"

FechaSistema *FechaSistema::instancia = nullptr;

FechaSistema::FechaSistema()
{
    time_t tiempoActual = time(0); // get time now
    tm *tiempoTranscurrido = localtime(&tiempoActual);
    _tiepoActual = *tiempoTranscurrido;
    _fecha = DTFecha(*tiempoTranscurrido);
}

FechaSistema *FechaSistema::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new FechaSistema();
    };
    return instancia;
}

DTFecha FechaSistema::getFecha()
{
    time_t tiempoActual = time(0); // get time now
    tm *tiempoTranscurrido = localtime(&tiempoActual);
    tm difftime;

    difftime.tm_sec = tiempoTranscurrido->tm_sec - _tiepoActual.tm_sec;
    difftime.tm_min = tiempoTranscurrido->tm_min - _tiepoActual.tm_min;
    difftime.tm_hour = tiempoTranscurrido->tm_hour - _tiepoActual.tm_hour;
    difftime.tm_mday = tiempoTranscurrido->tm_mday - _tiepoActual.tm_mday;
    difftime.tm_mon = tiempoTranscurrido->tm_mon - _tiepoActual.tm_mon;
    difftime.tm_year = tiempoTranscurrido->tm_year - _tiepoActual.tm_year;
    difftime.tm_wday = tiempoTranscurrido->tm_wday - _tiepoActual.tm_wday;
    difftime.tm_yday = tiempoTranscurrido->tm_yday - _tiepoActual.tm_yday;

    this->_fecha = this->_fecha + difftime;
    _tiepoActual = *tiempoTranscurrido;
    return this->_fecha;
}
void FechaSistema::setFecha(DTFecha fecha)
{
    time_t tiempoActual = time(0); // get time now
    tm *tiempo_en_TM = localtime(&tiempoActual);
    _tiepoActual = *tiempo_en_TM;

    this->_fecha = fecha;
}