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
    map<int, Reserva *> reservas;
    ControladorReserva();

public:
    static ControladorReserva *getInstancia();
    virtual void crearReserva(string hostal, DTFecha checkIn, DTFecha checkOut, bool esGrupal);
    virtual set<DTHabitacion *> listarHabitacionesDisponibles( string nombHost, DTFecha in, DTFecha fin);
    virtual void asignarHabitacionAReserva(int hab);
    virtual void asignarHuespedQueRealizaReserva(string correoHuesped);
    virtual void asignarHuespedAReservaGrupal(string correoHuesped);
    virtual void cancelarReserva();
    virtual void confirmarReserva();
    virtual void seleccionarHostal(string nom);
    virtual set<DTReserva *> listarReservas();
    virtual void seleccionarReservaAEliminar(int codigo);
    virtual void cancelarBaja();
    virtual void confirmarAccion();

    bool habitacionDisponibleFecha(Habitacion * hab, DTFecha in, DTFecha out);
    set<DTReserva *> listarReservasHuesped(string email, string nomHostal);
    Reserva *getReserva(int codigo);

    // para pruebas
    virtual set<DTReserva *> listarTodasLasReservasDelSistema();
    virtual int conocerTotatalReservas();

    // para eliminar datos
    virtual void liberarRegistros();
};

#endif