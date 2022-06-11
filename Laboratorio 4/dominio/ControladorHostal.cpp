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

set<DTHostal *> ControladorHostal::obtenerHostales()
{
    set<DTHostal *> res;
    for(map<string, Hostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it){
        res.insert(new DTHostal(it->second->getNombre(), it->second->getDireccion(), it->second->getTelefono()));
    };
    return res;
}

string nomHostalRecordado;

void ControladorHostal::buscarHostal(string nombre)
{
    nomHostalRecordado = nombre;
}

DTHabitacion * habRecordada;

void ControladorHostal::nuevaHabitacion(int numero, int capacidad, float costo)
{
    habRecordada = new DTHabitacion(numero, costo, capacidad);
}

void ControladorHostal::crearHabitacion()
{
    Habitacion * nueva = new Habitacion(habRecordada->getNumero(), habRecordada->getPrecio(), habRecordada->getCapacidad());
    hostales[nomHostalRecordado]->agregarHabitacion(nueva);
    delete habRecordada;
}

void ControladorHostal::liberarMemoria()
{
    delete habRecordada;
}
