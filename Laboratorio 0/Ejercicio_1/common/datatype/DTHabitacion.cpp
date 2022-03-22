
#include "header/DTHabitacion.hpp"
#include <iostream>

void DTHabitacion::imprimir(){
    std::cout << " Habitacion: " << this->numero << "\n";
    std::cout << " Costo: $" << this->precio  << "\n";
    std::cout << " Capacidad: " << this->capacidad  << "\n";
}

int DTHabitacion::getnumero() { 
    return this->numero; 
}

float DTHabitacion::getprecio() { 
    return this->precio; 
}

int DTHabitacion::getcapacidad() { 
    return this->capacidad; 
}

DTHabitacion::DTHabitacion(int numero,float precio,int capacidad) {
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}