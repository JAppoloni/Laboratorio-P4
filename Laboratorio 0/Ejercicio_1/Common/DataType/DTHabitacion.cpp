// #ifndef _DTHABITACION_HH_
// #define _DTHABITACION_HH_

// class DTHabitacion
// {
// private:
//     int numero;
//     float precio;
//     int capacidad;

// public:
//     void imprimir();

//     int getnumero();
//     float getprecio();
//     int getcapacidad();

//     DTHabitacion(int,float,int);
// };

// #endif

#include "../../include/DTHabitacion.h"
#include <iostream>


void DTHabitacion::imprimir(){
//imprimir
}

int DTHabitacion::getnumero(){ return this->numero; }
float DTHabitacion::getprecio(){ return this->precio; }
int DTHabitacion::getcapacidad(){ return this->capacidad; }

DTHabitacion::DTHabitacion(int numero,float precio,int capacidad){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
   
}
