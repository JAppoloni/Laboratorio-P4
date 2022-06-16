#ifndef CONTROLADOR_ESTADIA
#define CONTROLADOR_ESTADIA

#include "IControladorEstadia.hpp"
#include "ControladorReserva.hpp"
#include "FechaSistema.hpp"

using namespace std;

class ControladorEstadia : public IControladorEstadia
{
private:
    static ControladorEstadia *instancia;
    ControladorEstadia();

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

    // para pruebas
    virtual set<DTEstadia *> obtenerTodasLasEstadiasDelSistema();

    // para eliminar datos
    virtual void liberarRegistros();
};

#endif