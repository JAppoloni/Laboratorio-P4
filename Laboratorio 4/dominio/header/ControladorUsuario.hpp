#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

    #include <string>

    using namespace std;

    class ControladorUsuario{
        private:
            static ControladorUsuario * instancia;
            ControladorUsuario();
        public:
            static ControladorUsuario * getInstancia();
    };


#endif