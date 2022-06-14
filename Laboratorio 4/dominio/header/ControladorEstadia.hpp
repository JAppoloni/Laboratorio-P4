#ifndef CONTROLADOR_ESTADIA
#define CONTROLADOR_ESTADIA

    #include "IControladorEstadia.hpp"
    #include "ControladorReserva.hpp"
    #include "ControladorUsuario.hpp"
    #include "FechaSistema.hpp"

    using namespace std;

    class ControladorEstadia: public IControladorEstadia{ 
        private:
            static ControladorEstadia * instancia;
            ControladorEstadia();

            map<int, Estadia*> estadias; //la clave es el codigo de la reserva
        public:
            static ControladorEstadia * getInstancia();

            virtual void seleccionarHostal(string nom);
            virtual set<DTReserva *> obtenerReservaHuesped(string email);
            virtual void registrarEstadiaHuesped(int codigo);
    };

#endif