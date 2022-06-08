#ifndef CONTROLADOR_HOSTAL
#define CONTROLADOR_HOSTAL

    #include <string>

    using namespace std;

    class ControladorHostal{
        private:
            static ControladorHostal * instancia;
            ControladorHostal();
        public:
            static ControladorHostal * getInstancia();
    };

#endif