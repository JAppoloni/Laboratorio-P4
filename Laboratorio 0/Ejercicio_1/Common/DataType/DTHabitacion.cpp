
#include "header/DTHabitacion.hpp"

int DTHabitacion::getNumero() { 
    return this->numero; 
}

float DTHabitacion::getPrecio() { 
    return this->precio; 
}

int DTHabitacion::getCapacidad() { 
    return this->capacidad; 
}

DTHabitacion::DTHabitacion(int numero, float precio,int capacidad) {
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}

std::ostream& operator<<(std::ostream& out, DTHabitacion &habitacion) {
    out << "Numero: " << habitacion.getNumero() << std::endl;   
    out << "Costo: " << habitacion.getPrecio() << std::endl;
    out << "Capacidad: " << habitacion.getCapacidad() << " personas." << std::endl;
    out << "-----------------------" << std::endl;

    return out;
}
