#include "header/ReservaGrupal.hpp"
#include "header/Habitacion.hpp"
#include "header/Reserva.hpp"
#include "../datatype/header/DTFecha.hpp"
#include <iostream>

void ReservaGrupal::imprimir()
{
    std::cout << " La reserva Grupal " << this->getCodigo() << " es para el periodo ";
    this->getCheckIn().imprimir();
    std::cout << "-";
    this->getCheckOut().imprimir();
    std::cout << " y se reservó ";
    this->getHabitacionReservada().imprimir();
    std::cout << " Y su estado es " << this->estado;
    std::cout << ". \n ";
    Huesped Null = Huesped().NULL_Huesped();

    for (int i = 0; i < MAX_HUESPEDES && this->listaHuesped[i] != Null; i++)
    {
        this->listaHuesped[i].imprimir();
    }
}

ReservaGrupal::ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, Habitacion habitacionReservada, Huesped *Huesped)
{
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->habitacionReservada = habitacionReservada;
    this->listaHuesped = Huesped;
}

float ReservaGrupal::calcularCosto()
{
    int cant_Fingers = 0;
    Huesped Null = Huesped().NULL_Huesped();

    for (int i = 0; (i < MAX_HUESPEDES) && (cant_Fingers < 2) && (this->listaHuesped[i] != Null); i++)
        if (this->listaHuesped[i].getEsFinger() == true)
            cant_Fingers++;

    int rtn = this->habitacionReservada.getPrecio() * this->checkIn.calcularDias(this->checkOut);

    return (cant_Fingers == 2) ? rtn * 0.7 : rtn;
}

ReservaGrupal::~ReservaGrupal() {}
