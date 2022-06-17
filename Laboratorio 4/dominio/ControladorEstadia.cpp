#include "header/ControladorEstadia.hpp"

/*
 * Variables de instancia
 */
int codResEstRecordado;
int codigoResEstRecordado;
string nomHosRecordado;
string emailHuesRecordado;

/*
 * Variables de instancia
 */

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

void ControladorEstadia::seleccionarHostal(string nom)
{
    nomHosRecordado = nom;
}

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
    for (auto it : estadias)
    {
        DTFecha *aux = (it->getFinalizacion()) ? new DTFecha(it->getChechOut()) : nullptr;
        DTEstadia *estadiaAgregar = new DTEstadia(it->getReservaEstadia()->getCodigo(),
                                                  it->getHuespedEstadia()->getEmail(),
                                                  it->getCheckIn(),
                                                  aux,
                                                  it->getPromo());
        res.insert(estadiaAgregar);
    }

    return res;
}

set<DTEstadia *> ControladorEstadia::buscarEstadiasAbiertasPorCorreo(string email)
{
    emailHuesRecordado = email;
    set<DTEstadia *> res;

    if (!estadias.empty())
    {
        for (auto it : estadias)
        {
            string it_nombreHost = it->getReservaEstadia()->getHabitacionReserva()->getHostal()->getNombre();
            if (it->getHuespedEstadia()->getEmail() == email && it_nombreHost == nomHosRecordado && !(it->getFinalizacion()))
            {
                DTEstadia *estadiaAgregar = new DTEstadia(it->getReservaEstadia()->getCodigo(),
                                                          it->getHuespedEstadia()->getEmail(),
                                                          it->getCheckIn(),
                                                          nullptr,
                                                          it->getPromo());
                res.insert(estadiaAgregar);
            }
        }
    }
    return res;
}

void ControladorEstadia::seleccionarUnEstadiaAFinalizar(int codigoResEst)
{
    codigoResEstRecordado = codigoResEst;
}

void ControladorEstadia::finalizarEstadia()
{
    if (!estadias.empty())
    {
        for (auto it : estadias)
        {
            if (it->getReservaEstadia()->getCodigo() == codigoResEstRecordado && it->getHuespedEstadia()->getEmail() == emailHuesRecordado)
            {
                FechaSistema *FS = FechaSistema::getInstancia();
                DTFecha aux = DTFecha(FS->getFecha());
                it->setChechOut(&aux);

                break;
            }
        }
    }
}

set<DTEstadia *> ControladorEstadia::indicarEmail(string email)
{
    emailHuesRecordado = email;
    set<DTEstadia *> res;

    if (!estadias.empty())
    {
        for (auto it : estadias)
        {
            string it_nombreHost = it->getReservaEstadia()->getHabitacionReserva()->getHostal()->getNombre();
            if (it->getHuespedEstadia()->getEmail() == email && it->getFinalizacion() && it_nombreHost == nomHosRecordado)
            {
                DTFecha *aux = new DTFecha(it->getChechOut());
                DTEstadia *estadiaAgregar = new DTEstadia(it->getReservaEstadia()->getCodigo(),
                                                          it->getHuespedEstadia()->getEmail(),
                                                          it->getCheckIn(),
                                                          aux,
                                                          it->getPromo());
                res.insert(estadiaAgregar);
                break;
            }
        }
    }
    return res;
}

void ControladorEstadia::seleccionarEstadia(int codigo)
{
    codResEstRecordado = codigo;
}

void ControladorEstadia::ingresarCalificacion(int puntaje, string comentario)
{
    if (!estadias.empty())
    {
        for (auto it : estadias)
        {
            if (it->getReservaEstadia()->getCodigo() == codResEstRecordado && it->getHuespedEstadia()->getEmail() == emailHuesRecordado)
            {
                FechaSistema *FS = FechaSistema::getInstancia();
                Calificacion *nueva = new Calificacion(puntaje, comentario, FS->getFecha(), it);
                it->setCalificacionEstadia(nueva);
                it->getReservaEstadia()->getHabitacionReserva()->getHostal()->agregarCalificacion(nueva);
                break;
            }
        }
    }
}

void ControladorEstadia::notificarNuevaCalificacion() {}

void ControladorEstadia::eliminarEstadia(Estadia *estadia)
{
    estadia->getHuespedEstadia()->elimirarEstadia(estadia);
    if (estadia->getCalificacionEstadia() != nullptr)
    {
        ControladorUsuario *CU = ControladorUsuario::getInstancia();
        CU->eliminarNotificacion(estadia->getCalificacionEstadia());

        estadia->getReservaEstadia()->getHabitacionReserva()->getHostal()->eliminarCalificacion(estadia->getCalificacionEstadia());

        if (estadia->getCalificacionEstadia()->getRespuestaComentario() != nullptr)
        {
            ControladorUsuario *CU = ControladorUsuario::getInstancia();
            CU->eliminarComentarioEmpleado(estadia->getCalificacionEstadia()->getRespuestaComentario());
        };
    }
    estadias.erase(estadia);
}

Calificacion *ControladorEstadia::obtenerCalificacion(int codigo, string email)
{
    Calificacion *retorno = nullptr;

    if (!estadias.empty())
    {
        for (auto it : estadias)
        {
            if (it->getReservaEstadia()->getCodigo() == codigo && it->getHuespedEstadia()->getEmail() == email)
            {
                retorno = it->getCalificacionEstadia();
                break;
            }
        }
    }

    return retorno;
}

// notificaciones
void ControladorEstadia::eliminar(Observer *o)
{
    empleados.erase(o);
}

void ControladorEstadia::agregar(Observer *o)
{
    empleados.insert(o);
}

set<DTHostal *> ControladorEstadia::listarHostales()
{
    ControladorHostal *CH = CH->getInstancia();
    set<DTHostal *> hostales = CH->listarTodosLosHostalesDelSistema();
    return hostales;
}
set<DTEstadia *> ControladorEstadia::listarEstadias()
{
    set<DTEstadia *> res;
    if (!estadias.empty())
    {
        for (auto it : estadias)
        {
            DTFecha *fchCheckout = new DTFecha(it->getChechOut());
            DTEstadia *estadiaAgregar = new DTEstadia(it->getReservaEstadia()->getCodigo(),
                                                      it->getHuespedEstadia()->getEmail(),
                                                      it->getCheckIn(),
                                                      fchCheckout,
                                                      it->getPromo());
            res.insert(estadiaAgregar);
        }
    }
    return res;
}

DTEstadia *estadiaRecordada;
void ControladorEstadia::seleccionarEstadia(DTEstadia *estadia)
{
    estadiaRecordada = estadia;
}

DTCalificacion ControladorEstadia::buscarCalificacion()
{
}

DTComentario ControladorEstadia::buscarComentario()
{
}

DTReserva *ControladorEstadia::buscarInformacionReserva()
{
    Estadia *e;
    Reserva *r = e->getReservaEstadia();
    DTReserva *res = r->getDataReserva();
    return res;
}

void ControladorEstadia::liberarMemoria()
{
    if (estadiaRecordada != nullptr)
    {
        delete estadiaRecordada;
        estadiaRecordada = nullptr;
    }
}

void ControladorEstadia::liberarRegistros()
{
    if (!estadias.empty())
    {
        for (auto it : estadias)
        {
            Reserva *itReserva = it->getReservaEstadia();

            if (dynamic_cast<ReservaIndividual *>(itReserva) != nullptr)
            {
                ReservaIndividual *aux = dynamic_cast<ReservaIndividual *>(itReserva);
                aux->setEstadia(nullptr);
            }
            else
            {
                ReservaGrupal *aux = dynamic_cast<ReservaGrupal *>(itReserva);
                aux->setEstadia(it);
            }

            it->getHuespedEstadia()->elimirarEstadia(it);
            if (it->getCalificacionEstadia() != nullptr)
            {
                ControladorUsuario *CU = ControladorUsuario::getInstancia();
                CU->eliminarNotificacion(it->getCalificacionEstadia());
                it->getReservaEstadia()->getHabitacionReserva()->getHostal()->eliminarCalificacion(it->getCalificacionEstadia());

                if (it->getCalificacionEstadia()->getRespuestaComentario() != nullptr)
                {
                    ControladorUsuario *CU = ControladorUsuario::getInstancia();
                    CU->eliminarComentarioEmpleado(it->getCalificacionEstadia()->getRespuestaComentario());
                };
            }
            delete it;
            it = nullptr;
        }
        estadias.clear();
    }

    if (!empleados.empty())
    {
        for (auto it : empleados)
        {
            delete it;
            it = nullptr;
        }
        empleados.clear();
    }
}