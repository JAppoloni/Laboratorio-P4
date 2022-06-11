#include "header/ControladorHostal.hpp"

ControladorHostal *ControladorHostal::instancia = nullptr;

ControladorHostal::ControladorHostal() {}

ControladorHostal * ::ControladorHostal::getInstancia()
{
    if (instancia == nullptr)
        instancia = new ControladorHostal();
    return instancia;
}

void ControladorHostal::agregarHostal(DTHostal hostal)
{
    if (hostales[hostal.getNombre()] == nullptr)
    {
        Hostal *nuevo = new Hostal(hostal.getNombre(), hostal.getDireccion(), hostal.getTelefono());
        hostales[hostal.getNombre()] = nuevo;
    };
}
