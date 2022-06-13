#ifndef CONTROLADOR_ESTADIA
#define CONTROLADOR_ESTADIA

    #include <string>
    #include "IControladorEstadia.hpp"

    using namespace std;

    class ControladorEstadia: public IControladorEstadia{ 
        private:
            static ControladorEstadia * instancia;
            ControladorEstadia();
        public:
            static ControladorEstadia * getInstancia();
    };

#endif