#include "header/ControladorEstadia.hpp"

ControladorEstadia * ControladorEstadia::instancia = nullptr;

ControladorEstadia::ControladorEstadia(){}

ControladorEstadia * ControladorEstadia::getInstancia(){
    if (instancia == nullptr){
        instancia = new ControladorEstadia();
    };
    return instancia;
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
    CR->getReserva(codigo)->setEstado(Cerrada);
    CU->getHuesped(emailHuesRecordado)->agregarEstadia(estadias[codigo]);
}

set<DTEstadia*> ControladorEstadia::obtenerTodasLasEstadiasDelSistema()
{
    set<DTEstadia*> res;
    for(map<int, Estadia*>::iterator it = estadias.begin(); it != estadias.end(); ++it){
        res.insert(new DTEstadia(it->second->getReservaEstadia()->getCodigo(), it->second->getHuespedEstadia()->getEmail(), it->second->getCheckIn(), it->second->getChechOut(), it->second->getPromo()));
    };
    return res;
}