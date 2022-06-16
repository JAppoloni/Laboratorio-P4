#include "header/ControladorReserva.hpp"

ControladorReserva *ControladorReserva::instancia = nullptr;

ControladorReserva::ControladorReserva()
{
    contador_codigo = 1;
}

ControladorReserva *ControladorReserva::getInstancia()
{

    if (instancia == nullptr)
    {
        instancia = new ControladorReserva();
    };
    return instancia;
}

string hostalRecordado;
DTFecha checkInRecordado;
DTFecha checkOutRecordado;
bool esGruparRecordado;

void ControladorReserva::crearReserva(string hostal, DTFecha checkIn, DTFecha checkOut, bool esGrupal)
{
    hostalRecordado = hostal;
    checkInRecordado = checkIn;
    checkOutRecordado = checkOut;
    esGruparRecordado = esGrupal;
}

set<DTHabitacion *> ControladorReserva::listarHabitacionesDisponibles()
{
    set<DTHabitacion *> res;
    ControladorHostal *CH = ControladorHostal::getInstancia();
    res = CH->obtenerHabitacionesDeHostal(hostalRecordado);
    return res;
}

int numHabRecordado;

void ControladorReserva::asignarHabitacionAReserva(int hab)
{
    numHabRecordado = hab;
}

string correoHuespedRecordado;

void ControladorReserva::asignarHuespedQueRealizaReserva(string correoHuesped)
{
    correoHuespedRecordado = correoHuesped;
}

set<string> correosHuespedesRGRecordados;

void ControladorReserva::asignarHuespedAReservaGrupal(string correoHuesped)
{
    correosHuespedesRGRecordados.insert(correoHuesped);
}

void ControladorReserva::cancelarReserva() {}

void ControladorReserva::confirmarReserva()
{
    ControladorHostal *CH = ControladorHostal::getInstancia();
    ControladorUsuario *CU = ControladorUsuario::getInstancia();

    if (!esGruparRecordado)
    {
        reservas[contador_codigo] = new ReservaIndividual(contador_codigo, checkInRecordado, checkOutRecordado, CU->getHuesped(correoHuespedRecordado), Abierta, CH->getHostal(hostalRecordado)->getHabitacion(numHabRecordado), false);
    }
    else
    {
        list<Huesped *> huespedesRG;
        for (set<string>::iterator it = correosHuespedesRGRecordados.begin(); it != correosHuespedesRGRecordados.end(); ++it)
        {
            huespedesRG.push_front(CU->getHuesped(*it));
        };
        reservas[contador_codigo] = new ReservaGrupal(contador_codigo, checkInRecordado, checkOutRecordado, CU->getHuesped(correoHuespedRecordado), Abierta, CH->getHostal(hostalRecordado)->getHabitacion(numHabRecordado), huespedesRG);
    }
    contador_codigo++;
}

set<DTReserva *> ControladorReserva::listarReservasHuesped(string email, string nomHostal)
{
    set<DTReserva *> res;
    for (map<int, Reserva *>::iterator it = reservas.begin(); it != reservas.end(); ++it)
    {
        if (it->second->esReservaHostalHuesped(email, nomHostal) && it->second->getEstado() != Cancelada)
        {
            res.insert(it->second->getDataReserva());
        };
    };
    return res;
}

Reserva *ControladorReserva::getReserva(int codigo)
{
    return reservas[codigo];
}

set<DTReserva *> ControladorReserva::listarTodasLasReservasDelSistema()
{
    set<DTReserva *> res;
    for (map<int, Reserva *>::iterator it = reservas.begin(); it != reservas.end(); ++it)
    {
        res.insert(it->second->getDataReserva());
    };
    return res;
}

int ControladorReserva::conocerTotatalReservas()
{
    return contador_codigo;
}

void ControladorReserva::liberarRegistros()
{
    for (auto it : reservas)
    {
        if (it.second != nullptr)
        {
            delete it.second;
            it.second = nullptr;
        };
    }

    reservas.clear();

    if (instancia != nullptr)
    {
        instancia = nullptr;
    }
}

string nomHostalRecordado;

void ControladorReserva::seleccionarHostal(string nom)
{
    nomHostalRecordado = nom;
}

set<DTReserva *> ControladorReserva::listarReservas()
{
    set<DTReserva *> res;
    for (map<int, Reserva *>::iterator it = reservas.begin(); it != reservas.end(); ++it)
    {
        if (it->second->getHabitacionReserva()->getHostal()->getNombre() == nomHostalRecordado)
        {
            if (dynamic_cast<ReservaIndividual *>(it->second) != nullptr)
            {
                ReservaIndividual *aux = dynamic_cast<ReservaIndividual *>(it->second);
                DTReserva *nuevo = new DTReservaIndividual(aux->getCodigo(), aux->getCheckIn(), aux->getCheckOut(), aux->getEstado(), aux->calcularCosto(), aux->getPago());
                res.insert(nuevo);
            }
            else
            {
                ReservaGrupal *aux = dynamic_cast<ReservaGrupal *>(it->second);
                DTReserva *nuevo = new DTReservaGrupal(aux->getCodigo(), aux->getCheckIn(), aux->getCheckOut(), aux->getEstado(), aux->calcularCosto());
                res.insert(nuevo);
            };
        };
    };
    return res;
}

int codigoRecordado;

void ControladorReserva::seleccionarReservaAEliminar(int codigo)
{
    codigoRecordado = codigo;
}

void ControladorReserva::cancelarBaja() {}

void ControladorReserva::confirmarBaja()
{
}
// eliminar reserva (borrar link del controlador), estadia (eliminar del controlador y link de huesped a esatdia), calificaciones (eliminar link de empleado (notificacioin) y link de hostal), comentarios (link de empleado)
