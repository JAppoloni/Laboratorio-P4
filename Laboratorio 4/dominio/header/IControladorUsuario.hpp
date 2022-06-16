#ifndef I_CONTROLADOR_USUARIO
#define I_CONTROLADOR_USUARIO

    #include "../../common/clases/header/Usuario.hpp"
    #include "../../common/clases/header/Empleado.hpp"
    #include "../../common/clases/header/Huesped.hpp"
    #include "../../common/datatype/header/DTUsuario.hpp"
    #include <string>
    #include <set>
    #include <map>

    using namespace std;

    class IControladorUsuario{
        public:
            virtual void ingresarUsuario(DTUsuario * dataUsuario) = 0; //alta usuario
            virtual bool confirmarEmailDisponible() = 0; // alta usuario
            virtual void cancelarAlta() = 0;//alta usuario
            virtual bool esEmailUsuario() = 0; //email del DTUsuario recordado en el caso de uso alta usuario; alta usuario
            virtual void reingresarEmail(string email) = 0;//alta usuario
            virtual void confirmarAlta() = 0;//alta usuario
            virtual void seleccionarHostal(string nombre) = 0;//asignar empleado a hostal
            virtual set<DTEmpleado *> obtenerEmpleadosSinHsotal() = 0; //asignar empleado a hostal
            virtual void seleccionarEmpleado(string email) = 0;//asignar empleado a hostal
            virtual void seleccionarCargo(Cargo cargo) = 0;//aignar empleado a hostal
            virtual void cancelarAsignacion() = 0;//asignar empleado a hostal
            virtual void confirmarAsignacionDeEmpleadoAHostal() = 0;//asignar empleado a hostal
            virtual set<DTHuesped*> listarHuespedes() = 0;//realizar reserva
            virtual Huesped* getHuesped(string email) = 0;
            virtual set<DTCalificacion*> obtenerComentariosSinResponderEmpleado(string email) = 0;//comentar calificacion
            virtual void responderCalificacion(int codigo, string email, string comentario) = 0;//comentar calificacion
            virtual set<DTUsuario *> listarUsuarios() = 0; // consulta usuario
            virtual void eliminarSuscripcion(string email) = 0; //eliminar suscripcion
            virtual set<DTCalificacion*> listarNotificacionesEmpleado(string email) = 0; //listar Notificaciones Empleado
            virtual void suscribirseNotificacion(string email) = 0; //suscribirse a notificacion
            //para pruebas
            virtual set<DTUsuario*> obtenerTodosLosUsuariosDelSistema() = 0;
    };
    
#endif