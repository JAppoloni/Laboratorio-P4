#ifndef I_CONTROLADOR_ESTADIA
#define I_CONTROLADOR_ESTADIA

    #include <string>
    #include <map>
    #include <set>
    #include "../../common/clases/header/Estadia.hpp"
    #include "../../common/datatype/header/DTEstadia.hpp"

    using namespace std;

    class IControladorEstadia{
        public:
            virtual void seleccionarHostal(string nom) = 0;//registrar estadia
            virtual set<DTReserva *> obtenerReservaHuesped(string email) = 0;//registrar estadia
            virtual void registrarEstadiaHuesped(int codigo) = 0;//registrar estadia

            //para pruebas
            virtual set<DTEstadia*> obtenerTodasLasEstadiasDelSistema() = 0;
    };

#endif