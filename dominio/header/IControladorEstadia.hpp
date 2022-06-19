#ifndef I_CONTROLADOR_ESTADIA
#define I_CONTROLADOR_ESTADIA

#include <string>
#include <map>
#include <set>
#include "../../common/clases/header/Estadia.hpp"
#include "../../common/datatype/header/DTEstadia.hpp"
#include "Observer.hpp"

using namespace std;

class IControladorEstadia
{
public:
    virtual void seleccionarHostal(string nom) = 0;                             // registrar estadia; finalizar estadia; calificar estadia; consulta de estadia
    virtual set<DTReserva *> obtenerReservaHuesped(string email) = 0;           // registrar estadia
    virtual void registrarEstadiaHuesped(int codigo) = 0;                       // registrar estadia
    virtual set<DTEstadia *> buscarEstadiasAbiertasPorCorreo(string email) = 0; // finalizar estadia
    virtual void seleccionarUnEstadiaAFinalizar(int codigoResEst) = 0;          // finalizar estadia
    virtual void finalizarEstadia() = 0;                                        // finalizar estadia
    virtual set<DTEstadia *> indicarEmail(string email) = 0;                    // calificar estadia
    virtual void seleccionarEstadia(int codigo) = 0;                            // calificar estadia
    virtual void ingresarCalificacion(int puntaje, string comentario) = 0;      // calificar estadia
    virtual void notificarNuevaCalificacion() = 0;                              // calificar estadia

    virtual set<DTEstadia *> listarEstadias() = 0;           // Consulta de Estadia
    virtual void seleccionarEstadia(int id, string email) = 0; // Consulta de Estadia
    virtual DTCalificacion buscarCalificacion() = 0;         // Consulta de Estadia
    virtual DTReserva *buscarInformacionReserva() = 0;       // Consulta de Estadia
    virtual void liberarMemoria() = 0;                       // Consulta de Estadia
    
    // para notificaciones
    virtual void eliminar(Observer *o) = 0; // eliminar observador
    virtual void agregar(Observer *o) = 0;  // agregar observador

    // para pruebas
    virtual set<DTEstadia *> obtenerTodasLasEstadiasDelSistema() = 0;

    // para eliminar datos
    virtual void liberarRegistros() = 0;
};

#endif