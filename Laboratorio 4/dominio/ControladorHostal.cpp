#include "header/ControladorHostal.hpp"

ControladorHostal *ControladorHostal::instancia = nullptr;

ControladorHostal::ControladorHostal() {}

ControladorHostal* ::ControladorHostal::getInstancia()
{
    if (instancia == nullptr)
        instancia = new ControladorHostal();
    return instancia;
}

void ControladorHostal::agregarHostal(DTHostal hostal)
{
}

set<DTHostal> ControladorHostal::obtenerHostales()
{
    set<DTHostal> a;
    return a;
}

void ControladorHostal::buscarHostal(string nombre)
{
}
