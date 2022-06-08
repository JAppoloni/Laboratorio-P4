#ifndef CONTROLADOR_RESRVA
#define CONTROLADOR_RESERVA

    #include <string>
    #include "IControladorReserva.hpp"
    using namespace std;

    class ControladorReserva: public IControladorReserva{
        private:
            static ControladorReserva * instancia;
            ControladorReserva();
        public:
            static ControladorReserva * getInstancia();
    };

#endif