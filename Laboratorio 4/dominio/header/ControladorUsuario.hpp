#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

    #include <string>
    #include "IControladorUsuario.hpp"

    using namespace std;

    class ControladorUsuario: public IControladorUsuario{
        private:
            static ControladorUsuario * instancia;
            ControladorUsuario();
        public:
            static ControladorUsuario * getInstancia();
    };


#endif