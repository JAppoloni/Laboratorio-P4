#include "header/ControladorEstadia.hpp"

ControladorEstadia * ControladorEstadia::instancia = nullptr;

ControladorEstadia::ControladorEstadia(){}

ControladorEstadia * ControladorEstadia::getInstancia(){
    ControladorEstadia * res = instancia; 
    if (res == nullptr){
        res = new ControladorEstadia();
    };
    return res;
}

string nomHosRecordado;

void ControladorEstadia::seleccionarHostal(string nom)
{
    nomHosRecordado = nom;
}

string emailHuesRecordado;

set<DTReserva *> ControladorEstadia::obtenerReservaHuesped(string email)
{
    emailHuesRecordado = email;
    ControladorReserva * CR = ControladorReserva::getInstancia();
    return CR->listarReservasHuesped(emailHuesRecordado, nomHosRecordado);
}

void ControladorEstadia::registrarEstadiaHuesped(int codigo)
{
    ControladorReserva * CR = ControladorReserva::getInstancia();
    ControladorUsuario * CU = ControladorUsuario::getInstancia();
    FechaSistema * FS = FechaSistema::getInstancia();

    estadias[codigo] = new Estadia(FS->getFecha(), "", CR->getReserva(codigo), CU->getHuesped(emailHuesRecordado));
    CR->getReserva(codigo)->agregarEstadia(estadias[codigo]);
    CU->getHuesped(emailHuesRecordado)->agregarEstadia(estadias[codigo]);
}