#ifndef CONTROLADOR_ESTADIA
#define CONTROLADOR_ESTADIA

#include "IControladorEstadia.hpp"
#include "ControladorReserva.hpp"
#include "FechaSistema.hpp"
#include "Observer.hpp"
#include "FechaSistema.hpp"

using namespace std;

class ControladorEstadia : public IControladorEstadia
{
private:
    static ControladorEstadia *instancia;
    ControladorEstadia();
    set<Observer *> empleados; //Empleados suscriptos
    set<Estadia *> estadias;

public:
    static ControladorEstadia *getInstancia();
    virtual void seleccionarHostal(string nom);
    virtual set<DTReserva *> obtenerReservaHuesped(string email);
    virtual void registrarEstadiaHuesped(int codigo);
    virtual set<DTEstadia *> buscarEstadiasAbiertasPorCorreo(string email);
    virtual void seleccionarUnEstadiaAFinalizar(int codigoResEst);
    virtual void finalizarEstadia();
    virtual set<DTEstadia *> indicarEmail(string email);
    virtual void seleccionarEstadia(int codigo);
    virtual void ingresarCalificacion(int puntaje, string comentario);
    virtual void notificarNuevaCalificacion();
    Calificacion *obtenerCalificacion(int codigo, string email);
    void eliminarEstadia(Estadia *estadia);

    virtual set<DTEstadia *> listarEstadias();
    virtual void seleccionarEstadia(int id, string email);
    virtual DTCalificacion* buscarCalificacion();
    virtual DTComentario* buscarComentario();
    virtual DTReserva* buscarInformacionReserva();
    virtual void liberarMemoria();
    virtual void eliminar(Observer *o);
    virtual void agregar(Observer *o);

    // para pruebas
    virtual set<DTEstadia *> obtenerTodasLasEstadiasDelSistema();

    // para eliminar datos
    virtual void liberarRegistros();
};

#endif