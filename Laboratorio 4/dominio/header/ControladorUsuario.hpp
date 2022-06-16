#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

#include "IControladorUsuario.hpp"
#include "ControladorHostal.hpp"
#include "ControladorEstadia.hpp"

using namespace std;

class ControladorUsuario: public IControladorUsuario
{
    private:
        static ControladorUsuario * instancia;
        ControladorUsuario();
        string nomHostalRecordado;

        map<string, Empleado*> empleados;
        map<string, Huesped*> huespedes;
    public:
        static ControladorUsuario * getInstancia();

        virtual void ingresarUsuario(DTUsuario * dataUsuario);
        virtual bool confirmarEmailDisponible();
        virtual bool esEmailUsuario();
        virtual void cancelarAlta();
        virtual void reingresarEmail(string email);
        virtual void confirmarAlta();
        virtual void seleccionarHostal(string nombre);
        virtual set<DTEmpleado *> obtenerEmpleadosSinHsotal(); 
        virtual void seleccionarEmpleado(string email);
        virtual void seleccionarCargo(Cargo cargo); 
        virtual void cancelarAsignacion();
        virtual void confirmarAsignacionDeEmpleadoAHostal();
        virtual set<DTHuesped*> listarHuespedes();
        virtual Huesped* getHuesped(string correo);
        virtual set<DTCalificacion*> obtenerComentariosSinResponderEmpleado(string email);
        virtual void responderCalificacion(int codigo, string email, string comentario);

        virtual set<DTUsuario *> listarUsuarios(); 
        virtual void eliminarSuscripcion(string email);
        virtual set<DTCalificacion*> listarNotificacionesEmpleado(string email);
        virtual void suscribirseNotificacion(string email);

        virtual set<DTUsuario*> obtenerTodosLosUsuariosDelSistema();
};

#endif
