#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

    #include <string>
    #include <map>
    #include "IControladorUsuario.hpp"
    #include "../../common/clases/header/Usuario.hpp"
    #include "../../common/clases/header/Empleado.hpp"
    #include "../../common/clases/header/Huesped.hpp"

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
            virtual void cancelarAlta();
            virtual void reingresarEmail(string email);
    };


#endif