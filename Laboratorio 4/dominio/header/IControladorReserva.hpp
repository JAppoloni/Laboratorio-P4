#ifndef I_CONTROLADOR_RESERVA
#define I_CONTROLADOR_RESERVA
    
    #include <set>
    #include <map>
    #include <string>
    #include "../../common/clases/header/Reserva.hpp"
    #include "../../common/clases/header/ReservaIndividual.hpp"
    #include "../../common/clases/header/ReservaGrupal.hpp"
    #include "../../common/datatype/header/DTReserva.hpp"
    
    using namespace std;

    class IControladorReserva{
        public:
            virtual void crearReserva(string hostal, DTFecha checkIn, DTFecha checkOut, bool esGrupal) = 0;//realizar reserva
            virtual set<DTHabitacion *> listarHabitacionesDisponibles() = 0;//realizar reserva
            virtual void asignarHabitacionAReserva(int hab) = 0;//relaizar reserva
            virtual void asignarHuespedQueRealizaReserva(string correoHuesped) = 0;//realizar reserva
            virtual void asignarHuespedAReservaGrupal(string correoHuesped) = 0;//realizar reserva
            virtual void cancelarReserva() = 0;//realizar reserva
            virtual void confirmarReserva() = 0;//realizar reserva
            virtual void seleccionarHostal(string nom) = 0;//baja reserva
            virtual set<DTReserva*> listarReservas() = 0;//baja reserva
            virtual void seleccionarReservaAEliminar(int codigo) = 0;//baja reserva
            virtual void cancelarBaja() = 0;//baja reserva
            virtual void confirmarBaja() = 0;//baja reserva

            //para pruebas
            virtual set<DTReserva *> listarTodasLasReservasDelSistema() = 0;
            virtual int conocerTotatalReservas() = 0;
    };

#endif