#include "header/Habitacion.hpp"
#include <iostream>

int Habitacion::getNumero()
{
    return this->numero;
}

void Habitacion::setNumero(int numero)
{
    this->numero = numero;
}

float Habitacion::getPrecio()
{
    return this->precio;
}

void Habitacion::setPrecio(float precio)
{
    this->precio = precio;
}

int Habitacion::getCapacidad()
{
    return this->capacidad;
}

void Habitacion::setCapacidad(int capacidad)
{
    this->capacidad = capacidad;
}

Habitacion::~Habitacion(){}


Habitacion::Habitacion(int numero, float precio, int capacidad)
{
    this->numero = numero;
    this->capacidad = capacidad;
    this->precio = precio;
}

void Habitacion::imprimir()
{
    std::cout << " La habitación número" << this->numero << " cuenta con una capacidad de " << this->capacidad << " a un precio de  $ " << this->precio << ".";
}
