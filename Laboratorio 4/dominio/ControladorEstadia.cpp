#include "header/ControladorEstadia.hpp"

ControladorEstadia *ControladorEstadia::instancia = nullptr;

ControladorEstadia::ControladorEstadia() {}

ControladorEstadia *ControladorEstadia::getInstancia()
{
    if (instancia == nullptr)
    {
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
    ControladorReserva *CR = ControladorReserva::getInstancia();
    return CR->listarReservasHuesped(emailHuesRecordado, nomHosRecordado);
}

void ControladorEstadia::registrarEstadiaHuesped(int codigo)
{
    ControladorReserva *CR = ControladorReserva::getInstancia();
    ControladorUsuario *CU = ControladorUsuario::getInstancia();
    FechaSistema *FS = FechaSistema::getInstancia();

    Estadia *nueva = new Estadia(FS->getFecha(), "", CR->getReserva(codigo), CU->getHuesped(emailHuesRecordado));
    estadias.insert(nueva);
    CR->getReserva(codigo)->agregarEstadia(nueva);
    CR->getReserva(codigo)->setEstado(Cerrada);
    CU->getHuesped(emailHuesRecordado)->agregarEstadia(nueva);
}

set<DTEstadia *> ControladorEstadia::obtenerTodasLasEstadiasDelSistema()
{
    set<DTEstadia *> res;
    for (set<Estadia *>::iterator it = estadias.begin(); it != estadias.end(); ++it)
    {
        DTFecha *aux = ((*it)->getChechOut() == nullptr) ? nullptr : new DTFecha((*it)->getChechOut());
        res.insert(new DTEstadia((*it)->getReservaEstadia()->getCodigo(), (*it)->getHuespedEstadia()->getEmail(), (*it)->getCheckIn(), aux, (*it)->getPromo()));
    };
    return res;
}

set<DTEstadia *> ControladorEstadia::buscarEstadiasAbiertasPorCorreo(string email)
{
    emailHuesRecordado = email;
    set<DTEstadia *> res;
    for (set<Estadia *>::iterator it = estadias.begin(); it != estadias.end(); ++it)
    {
        if ((*it) == nullptr)
        {
            break;
        };
        if ((*it)->getHuespedEstadia()->getEmail() == email && (*it)->getReservaEstadia()->getHabitacionReserva()->getHostal()->getNombre() == nomHosRecordado && (*it)->getChechOut() == nullptr)
        {
            res.insert(new DTEstadia((*it)->getReservaEstadia()->getCodigo(), (*it)->getHuespedEstadia()->getEmail(), (*it)->getCheckIn(), nullptr, (*it)->getPromo()));
        };
    };
    return res;
}

int codigoResEstRecordado;

void ControladorEstadia::seleccionarUnEstadiaAFinalizar(int codigoResEst)
{
    codigoResEstRecordado = codigoResEst;
}

void ControladorEstadia::finalizarEstadia()
{
    for (set<Estadia *>::iterator it = estadias.begin(); it != estadias.end(); ++it)
    {
        if ((*it) == nullptr)
        {
            break;
        };
        if ((*it)->getHuespedEstadia()->getEmail() == emailHuesRecordado && (*it)->getReservaEstadia()->getCodigo() == codigoResEstRecordado)
        {
            FechaSistema *FS = FechaSistema::getInstancia();
            DTFecha *aux = new DTFecha(FS->getFecha());
            (*it)->setChechOut(aux);
            break;
        };
    };
}

set<DTEstadia *> ControladorEstadia::indicarEmail(string email)
{
    emailHuesRecordado = email;
    set<DTEstadia *> res;
    for (set<Estadia *>::iterator it = estadias.begin(); it != estadias.end(); ++it)
    {
        if ((*it) == nullptr)
        {
            break;
        };
        if ((*it)->getHuespedEstadia()->getEmail() == email && (*it)->getChechOut() != nullptr && (*it)->getReservaEstadia()->getHabitacionReserva()->getHostal()->getNombre() == nomHosRecordado)
        {
            DTFecha *aux = new DTFecha((*it)->getChechOut());
            res.insert(new DTEstadia((*it)->getReservaEstadia()->getCodigo(), (*it)->getHuespedEstadia()->getEmail(), aux, (*it)->getChechOut(), (*it)->getPromo()));
        };
    };
    return res;
}

int codResEstRecordado;

void ControladorEstadia::seleccionarEstadia(int codigo)
{
    codResEstRecordado = codigo;
}

void ControladorEstadia::ingresarCalificacion(int puntaje, string comentario)
{
    for (set<Estadia *>::iterator it = estadias.begin(); it != estadias.end(); ++it)
    {
        if ((*it) == nullptr)
        {
            break;
        };
        if ((*it)->getHuespedEstadia()->getEmail() == emailHuesRecordado && (*it)->getReservaEstadia()->getCodigo() == codResEstRecordado)
        {
            FechaSistema *FS = FechaSistema::getInstancia();
            Calificacion *nueva = new Calificacion(puntaje, comentario, FS->getFecha(), *it);
            (*it)->setCalificacionEstadia(nueva);
            (*it)->getReservaEstadia()->getHabitacionReserva()->getHostal()->agregarCalificacion(nueva);
            break;
        };
    };
}

void ControladorEstadia::notificarNuevaCalificacion()
{
}

Calificacion *ControladorEstadia::obtenerCalificacion(int codigo, string email)
{
    for (set<Estadia *>::iterator it = estadias.begin(); it != estadias.end(); ++it)
    {
        if ((*it) == nullptr)
        {
            break;
        }
        if ((*it)->getReservaEstadia()->getCodigo() == codigo && (*it)->getHuespedEstadia()->getEmail() == email)
        {
            return (*it)->getCalificacionEstadia();
        };
    };
    return nullptr;
}

//notificaciones 
 void ControladorEstadia::eliminar(Observer* o){
    empleados.erase(o);
 }

 void ControladorEstadia::agregar(Observer* o){
     empleados.insert(o);
}


set<DTHostal*> ControladorEstadia::listarHostales(){
    ControladorHostal*  CH = CH->getInstancia();
    set<DTHostal*> hostales = CH->listarTodosLosHostalesDelSistema(); 
    return hostales;
}
 set<DTEstadia*> ControladorEstadia::listarEstadias(){
    set<DTEstadia*> res;
    for(set<Estadia*>::iterator it = estadias.begin(); it != estadias.end(); ++it){
        res.insert(new DTEstadia((*it)->obtenerID(),(*it)->getHuespedEstadia()->getEmail(),(*it)->getCheckIn(),(*it)->getChechOut(),(*it)->getPromo()));
    }
    return res;

}

 DTEstadia* estadiaRecordada;
 void ControladorEstadia::seleccionarEstadia(DTEstadia* estadia){
    estadiaRecordada = estadia;
 }
 
 //DTCalificacion ControladorEstadia::buscarCalificacion(){

 //}
 //DTComentario ControladorEstadia::buscarComentario(){

 //}
 //DTReserva* ControladorEstadia::buscarInformacionReserva() {
   // Estadia* e; 
   // Reserva* r = e->getReservaEstadia();
   // DTReserva* res =  r->getDataReserva();
   // return res;
 //}

void ControladorEstadia::liberarMemoria(){
  if ( estadiaRecordada != nullptr) {
    delete estadiaRecordada;
    estadiaRecordada = nullptr;
 }

}
