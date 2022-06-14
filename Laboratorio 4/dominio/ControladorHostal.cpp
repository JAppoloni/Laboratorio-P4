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
    for (map<string, Hostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
    {
        int promedio = 0;
        int cont = 0;
        for (list<Calificacion *>::iterator aux = it->second->getCalificaciones().begin(); aux != it->second->getCalificaciones().end(); ++aux)
        {
            cont++;
            promedio = promedio + (*aux)->getPuntaje();
        };
        if (cont != 0)
        {
            promedio = promedio / cont;
        };
        res.insert(new DTHostal(it->second->getNombre(), it->second->getDireccion(), it->second->getTelefono(), promedio));
    };
    return res;
}

void ControladorHostal::buscarHostal(string nombre)
{
    nomHostalRecordado = nombre;
}

DTHabitacion *habRecordada;

void ControladorHostal::nuevaHabitacion(int numero, int capacidad, float costo)
{
    habRecordada = new DTHabitacion(numero, costo, capacidad);
}

void ControladorHostal::crearHabitacion()
{
    Habitacion *nueva = new Habitacion(habRecordada->getNumero(), habRecordada->getPrecio(), habRecordada->getCapacidad(), hostales[nomHostalRecordado]);
    hostales[nomHostalRecordado]->agregarHabitacion(nueva);
    delete habRecordada;
}

void ControladorHostal::liberarMemoria()
{
    delete habRecordada;
}

Hostal *ControladorHostal::getHostal(string nom)
{
    return hostales[nom];
}

set<DTHabitacion *> ControladorHostal::obtenerHabitacionesDeHostal(string nom)
{
    set<DTHabitacion *> res;
    for (list<Habitacion *>::iterator it = hostales[nom]->getHabitaciones().begin(); it != hostales[nom]->getHabitaciones().end(); ++it)
    {
        res.insert(new DTHabitacion((*it)->getNumero(), (*it)->getPrecio(), (*it)->getCapacidad()));
    };
    return res;
}

list<DTHostal *> ControladorHostal::calcularTopTres()
{
    map<int, DTHostal *> topHostales;
    for (map<string, Hostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
    {
        int promedio = 0;
        int cont = 0;
        for (list<Calificacion *>::iterator aux = it->second->getCalificaciones().begin(); aux != it->second->getCalificaciones().end(); ++aux)
        {
            promedio = promedio + (*aux)->getPuntaje();
        };
        if (cont != 0)
        {
            promedio = promedio / cont;
        };
        topHostales[promedio] = new DTHostal(it->second->getNombre(), it->second->getDireccion(), it->second->getTelefono(), promedio);
    };
    list<DTHostal *> res;
    int cont = 0;
    for (map<int, DTHostal *>::iterator it = topHostales.end(); it != topHostales.begin() && cont < 3; --it)
    {
        res.push_back(it->second);
    };
    return res;
}

set<DTCalificacion *> ControladorHostal::consultarHostal(string nom)
{
    set<DTCalificacion *> res;
    for (list<Calificacion *>::iterator it = hostales[nom]->getCalificaciones().begin(); it != hostales[nom]->getCalificaciones().end(); ++it)
    {
        res.insert(new DTCalificacion(-1, "", (*it)->getPuntaje(), (*it)->getFecha(), (*it)->getComentario()));
    };
    return res;
}

set<DTHostal *> ControladorHostal::listarTodosLosHostalesDelSistema()
{
    set<DTHostal *> res;
    for (map<string, Hostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
    {
        int promedio = 0;
        int cont = 0;

        if (it->second->getCalificaciones().size() != 0)
        {
            for (list<Calificacion *>::iterator aux = it->second->getCalificaciones().begin(); aux != it->second->getCalificaciones().end(); ++aux)
            {
                if ((*aux) == nullptr)
                    break;

                cont++;
                promedio = promedio + (*aux)->getPuntaje();
            };
            if (cont != 0)
            {
                promedio = promedio / cont;
            };
        }
        res.insert(new DTHostal(it->second->getNombre(), it->second->getDireccion(), it->second->getTelefono(), promedio));
    };
    return res;
}