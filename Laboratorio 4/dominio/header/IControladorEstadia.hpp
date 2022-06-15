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
            virtual void seleccionarHostal(string nom) = 0;//registrar estadia; finalizar estadia; calificar estadia
            virtual set<DTReserva *> obtenerReservaHuesped(string email) = 0;//registrar estadia
            virtual void registrarEstadiaHuesped(int codigo) = 0;//registrar estadia
            virtual set<DTEstadia*> buscarEstadiasAbiertasPorCorreo(string email) = 0;//finalizar estadia
            virtual void seleccionarUnEstadiaAFinalizar(int codigoResEst) = 0;//finalizar estadia
            virtual void finalizarEstadia() = 0;//finalizar estadia
            virtual set<DTEstadia*> indicarEmail(string email) = 0;//calificar estadia

            //para pruebas
            virtual set<DTEstadia*> obtenerTodasLasEstadiasDelSistema() = 0;
    };

#endif