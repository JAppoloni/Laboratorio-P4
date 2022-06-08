#ifndef CONTROLADOR_HOSTAL
#define CONTROLADOR_HOSTAL

    #include <string>
    #include "IControladorHostal.hpp"
    using namespace std;

    class ControladorHostal: public IControladorHostal{
        private:
            static ControladorHostal * instancia;
            ControladorHostal();
        public:
            static ControladorHostal * getInstancia();
    };

#endif