#ifndef FECHA_SISTEMA
#define FECHA_SISTEMA

    #include <string>
    #include "IFechaSistema.hpp"

    using namespace std;

    class FechaSistema: public IFechaSistema{
        private:
            static FechaSistema * instancia;
            FechaSistema();
        public:
            static FechaSistema * getInstancia();
    };


#endif