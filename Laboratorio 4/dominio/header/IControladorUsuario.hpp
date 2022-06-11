#ifndef I_CONTROLADOR_USUARIO
#define I_CONTROLADOR_USUARIO

    #include "../../common/datatype/header/DTUsuario.hpp"
    #include <string>

    using namespace std;

    class IControladorUsuario{
        public:
            virtual void ingresarUsuario(DTUsuario * dataUsuario) = 0;
            virtual void cancelarAlta() = 0;
            virtual void reingresarEmail(string email) = 0;
    };
    
#endif