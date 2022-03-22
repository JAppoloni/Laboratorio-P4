#include "header/Sistema.hpp"
#include <iostream>

Sistema::Sistema() {}

Sistema::~Sistema() {}

void Sistema::agregarHuesped(std::string nombre, std::string email, bool esFinger) {
    Huesped* huesped = new Huesped(nombre, email, esFinger);

    huespedes.add(huesped);
}

DTHuesped** Sistema::obtenerHuespedes(int &cantidad) {
    cantidad = huespedes.size();

    DTHuesped** result = new DTHuesped*[cantidad];
    
    int index = 0;
    while (index < cantidad) {
        result[index] = new DTHuesped(huespedes.values()[index]);
        index++;
    }

    return result;
}
