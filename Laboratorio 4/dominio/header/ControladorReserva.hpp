#ifndef CONTROLADOR_RESRVA
#define CONTROLADOR_RESERVA

    #include <string>

    using namespace std;

    class ControladorReserva{
        private:
            static ControladorReserva * instancia;
            ControladorReserva();
        public:
            static ControladorReserva * getInstancia();
    };

#endif