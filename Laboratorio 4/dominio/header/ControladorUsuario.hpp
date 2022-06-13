#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

    #include "IControladorUsuario.hpp"
    #include "ControladorHostal.hpp"

    using namespace std;

    class ControladorUsuario: public IControladorUsuario{
        private:
            static ControladorUsuario * instancia;
            ControladorUsuario();

            map<string, Empleado*> empleados;
            map<string, Huesped*> huespedes;
        public:
            static ControladorUsuario * getInstancia();

            virtual void ingresarUsuario(DTUsuario * dataUsuario);
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
    };


#endif