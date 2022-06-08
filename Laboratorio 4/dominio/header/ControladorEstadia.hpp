#ifndef CONTROLADOR_ESTADIA
#define CONTROLADOR_ESTADIA

    #include <string>

    using namespace std;

    class ControladorEstadia{
        private:
            static ControladorEstadia * instancia;
            ControladorEstadia();
        public:
            static ControladorEstadia * getInstancia();
    };

#endif