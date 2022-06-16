#ifndef CONTROLADOR_RESERVA
#define CONTROLADOR_RESERVA

#include "IControladorReserva.hpp"
#include "ControladorHostal.hpp"
#include "ControladorUsuario.hpp"

using namespace std;

class ControladorReserva : public IControladorReserva
{
private:
    static ControladorReserva *instancia;
    ControladorReserva();

    map<int, Reserva *> reservas;
    int contador_codigo;

public:
    static ControladorReserva *getInstancia();

    virtual void crearReserva(string hostal, DTFecha checkIn, DTFecha checkOut, bool esGrupal);
    virtual set<DTHabitacion *> listarHabitacionesDisponibles();
    virtual void asignarHabitacionAReserva(int hab);
    virtual void asignarHuespedQueRealizaReserva(string correoHuesped);
    virtual void asignarHuespedAReservaGrupal(string correoHuesped);
    virtual void cancelarReserva();
    virtual void confirmarReserva();

    set<DTReserva *> listarReservasHuesped(string email, string nomHostal);
    Reserva *getReserva(int codigo);

    // para pruebas
    virtual set<DTReserva *> listarTodasLasReservasDelSistema();
    virtual int conocerTotatalReservas();

    // para eliminar datos
    virtual void liberarRegistros();
};

#endif