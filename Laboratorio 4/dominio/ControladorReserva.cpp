#include "header/ControladorReserva.hpp"

ControladorReserva * ControladorReserva::instancia = nullptr;

ControladorReserva::ControladorReserva()
{
    contador_codigo = 0;
}

ControladorReserva * ControladorReserva::getInstancia(){
    ControladorReserva * res = instancia; 
    if (res == nullptr){
        res = new ControladorReserva();
    };
    return res;
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
    ControladorHostal * CH = ControladorHostal::getInstancia();
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

void ControladorReserva::cancelarReserva(){}

void ControladorReserva::confirmarReserva()
{
    ControladorHostal * CH = ControladorHostal::getInstancia();
    //CH->getHostal()->getHabitacion()
    ControladorUsuario * CU = ControladorUsuario::getInstancia();
    //CU->getHuesped(correoHuespedRecordado)
    if(!esGruparRecordado){
        reservas[contador_codigo] = new ReservaIndividual(contador_codigo, checkInRecordado, checkOutRecordado, CU->getHuesped(correoHuespedRecordado), Abierta, CH->getHostal(hostalRecordado)->getHabitacion(numHabRecordado), false);
    } else{
        list<Huesped *> huespedesRG;
        for(set<string>::iterator it = correosHuespedesRGRecordados.begin(); it != correosHuespedesRGRecordados.end(); ++it){
            huespedesRG.push_front(CU->getHuesped(*it));
        };
        reservas[contador_codigo] = new ReservaGrupal(contador_codigo, checkInRecordado, checkOutRecordado, CU->getHuesped(correoHuespedRecordado), Abierta, CH->getHostal(hostalRecordado)->getHabitacion(numHabRecordado), huespedesRG);
    }
    contador_codigo++;
}