#include "header/ControladorReserva.hpp"
/*
 * Variables de instancia
 */
ControladorReserva *ControladorReserva::instancia = nullptr;
int contador_codigo;
bool esGruparRecordado;
string _nombreRecordado_Hostal_CReserva;
string hostalRecordado;
int codigoRecordado;
DTFecha checkInRecordado;
DTFecha checkOutRecordado;
set<string> correosHuespedesRGRecordados;
string correoHuespedRecordado;
int numHabRecordado;
/*
 * Fin de variables de instancia
 */

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

void ControladorReserva::asignarHabitacionAReserva(int hab)
{
    numHabRecordado = hab;
}

void ControladorReserva::asignarHuespedQueRealizaReserva(string correoHuesped)
{
    correoHuespedRecordado = correoHuesped;
}

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
        ReservaIndividual *reserva = new ReservaIndividual(contador_codigo,
                                                           checkInRecordado,
                                                           checkOutRecordado,
                                                           CU->getHuesped(correoHuespedRecordado),
                                                           Abierta,
                                                           CH->getHostal(hostalRecordado)->getHabitacion(numHabRecordado),
                                                           false);
        reservas[contador_codigo] = reserva;
    }
    else
    {
        list<Huesped *> huespedesRG;
        for (auto it : correosHuespedesRGRecordados)
        {
            huespedesRG.push_back(CU->getHuesped(it));
        };

        ReservaGrupal *reservaGrupal = new ReservaGrupal(
            contador_codigo,
            checkInRecordado,
            checkOutRecordado,
            CU->getHuesped(correoHuespedRecordado),
            Abierta,
            CH->getHostal(hostalRecordado)->getHabitacion(numHabRecordado),
            huespedesRG);
        reservas[contador_codigo] = reservaGrupal;
    }
    correosHuespedesRGRecordados.clear();
    contador_codigo++;
}

set<DTReserva *> ControladorReserva::listarReservasHuesped(string email, string nomHostal)
{
    set<DTReserva *> res;
    for (auto it : reservas)
    {
        if (it.second->esReservaHostalHuesped(email, nomHostal) && it.second->getEstado() != Cancelada)
        {
            res.insert(it.second->getDataReserva());
        }
    }
    return res;
}

Reserva *ControladorReserva::getReserva(int codigo)
{
    return reservas[codigo];
}

set<DTReserva *> ControladorReserva::listarTodasLasReservasDelSistema()
{
    set<DTReserva *> res;

    for (auto it : reservas)
    {
        res.insert(it.second->getDataReserva());
    }

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
    correosHuespedesRGRecordados.clear();
    hostalRecordado.erase();
    _nombreRecordado_Hostal_CReserva.erase();
}

void ControladorReserva::seleccionarHostal(string nom)
{
    _nombreRecordado_Hostal_CReserva = nom;
}

set<DTReserva *> ControladorReserva::listarReservas()
{
    set<DTReserva *> res;
    if (!_nombreRecordado_Hostal_CReserva.empty())
    {
        for (auto it : reservas)
        {

            if (it.second->getHabitacionReserva()->getHostal()->getNombre() == _nombreRecordado_Hostal_CReserva)
            {
                if (dynamic_cast<ReservaIndividual *>(it.second) != nullptr)
                {
                    ReservaIndividual *aux = dynamic_cast<ReservaIndividual *>(it.second);
                    DTReserva *nuevo = new DTReservaIndividual(aux->getCodigo(),
                                                               aux->getCheckIn(),
                                                               aux->getCheckOut(),
                                                               aux->getEstado(),
                                                               aux->calcularCosto(),
                                                               aux->getPago());
                    res.insert(nuevo);
                }
                else
                {
                    ReservaGrupal *aux = dynamic_cast<ReservaGrupal *>(it.second);
                    DTReserva *nuevo = new DTReservaGrupal(aux->getCodigo(),
                                                           aux->getCheckIn(),
                                                           aux->getCheckOut(),
                                                           aux->getEstado(),
                                                           aux->calcularCosto());
                    res.insert(nuevo);
                };
            };
        };
    }

    return res;
}

void ControladorReserva::seleccionarReservaAEliminar(int codigo)
{
    codigoRecordado = codigo;
}

void ControladorReserva::cancelarBaja() {}

void ControladorReserva::confirmarBaja()
{
    if (reservas[codigoRecordado] != nullptr)
    {
        ControladorEstadia *CE = ControladorEstadia::getInstancia();
        if (dynamic_cast<ReservaIndividual *>(reservas[codigoRecordado]) != nullptr)
        {
            ReservaIndividual *aux = dynamic_cast<ReservaIndividual *>(reservas[codigoRecordado]);
            if (aux->getEstadiaReserva() != nullptr)
            {
                CE->eliminarEstadia(aux->getEstadiaReserva());
            };
        }
        else
        {
            ReservaGrupal *aux = dynamic_cast<ReservaGrupal *>(reservas[codigoRecordado]);

            if (!aux->getListaEstadia().empty())
            {
                for (auto it : aux->getListaEstadia())
                {
                    CE->eliminarEstadia(it);
                }
                aux->getListaEstadia().clear();
            }
        }
        delete reservas[codigoRecordado];
        reservas.erase(codigoRecordado);
    }
}
