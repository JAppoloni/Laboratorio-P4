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

list<DTHostal *> ControladorHostal::obtenerHostales()
{
    list<DTHostal *> res;

    if (!hostales.empty())
    {
        for (auto itHostales : hostales)
        {

            float promedio = 0;

            if (!itHostales.second->getCalificaciones().empty())
            {
                int cont = 0;
                for (auto itClaificacion : itHostales.second->getCalificaciones())
                {
                    promedio += itClaificacion->getPuntaje();
                    cont++;
                }
                promedio = promedio / cont;
            }
            DTHostal *nuevoHost = new DTHostal(itHostales.first, itHostales.second->getDireccion(), itHostales.second->getTelefono(), promedio);
            res.push_back(nuevoHost);
        }
    }
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
    if (!hostales[nom]->getHabitaciones().empty())
    {
        for (auto it : hostales[nom]->getHabitaciones())
        {
            DTHabitacion *nueva = new DTHabitacion(it->getNumero(), it->getPrecio(), it->getCapacidad());
            res.insert(nueva);
        }
    }
    return res;
}

list<DTHostal *> ControladorHostal::calcularTopTres()
{
    list<DTHostal *> topTresHostales;

    if (!hostales.empty())
    {
        list<DTHostal> topHostales;

        for (auto it : hostales)
        {
            float promedio = 0;
            if (!it.second->getCalificaciones().empty())
            {
                int cont = 0;
                for (auto itClaificacion : it.second->getCalificaciones())
                {
                    promedio += itClaificacion->getPuntaje();
                    cont++;
                }
                promedio = promedio / cont;
            }
            DTHostal agregarAlista = DTHostal(it.first, it.second->getDireccion(), it.second->getTelefono(), promedio);

            if (!topHostales.empty())
            {
                bool insertado = false;
                for (auto itTop : topHostales)
                {
                    if (itTop.getPromedioCalificaciones() < promedio)
                    {
                        topHostales.push_front(agregarAlista);
                        insertado = true;
                        break;
                    }
                }
                if (!insertado)
                {
                    topHostales.push_back(agregarAlista);
                }
            }
            else
            {
                topHostales.push_back(agregarAlista);
            }
        }
        int contador = 0;
        for (auto it : topHostales)
        {
            if (contador > 3)
                break;

            DTHostal *nuevoHost = new DTHostal(it.getNombre(), it.getDireccion(), it.getTelefono(), it.getPromedioCalificaciones());
            topTresHostales.push_back(nuevoHost);
        }
    }
    return topTresHostales;
}

set<DTCalificacion *> ControladorHostal::consultarHostal(string nom)
{
    set<DTCalificacion *> res;

    for (auto it : hostales[nom]->getCalificaciones())
    {
        DTCalificacion *nueva = new DTCalificacion(-1, "", it->getPuntaje(), it->getFecha(), it->getComentario());
        res.insert(nueva);
    }
    return res;
}

set<DTHostal *> ControladorHostal::listarTodosLosHostalesDelSistema()
{
    set<DTHostal *> res;
    if (!hostales.empty())
    {
        for (auto it : hostales)
        {
            float promedio = 0;
            if (!it.second->getCalificaciones().empty())
            {
                int cont = 0;
                for (auto itClaificacion : it.second->getCalificaciones())
                {
                    promedio += itClaificacion->getPuntaje();
                    cont++;
                }
                promedio = promedio / cont;
            }
            DTHostal *nuevoHost = new DTHostal(it.first, it.second->getDireccion(), it.second->getTelefono(), promedio);
            res.insert(nuevoHost);
        }
    }
    return res;
}

void ControladorHostal::liberarRegistros()
{
    for (auto it : hostales)
    {
        if (it.second != nullptr)
        {
            delete it.second;
            it.second = nullptr;
        }
    }
    hostales.clear();

    if (instancia != nullptr)
    {
        instancia = nullptr;
    }
}
