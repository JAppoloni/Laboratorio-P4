#ifndef CONTROLADOR_HOSTAL
#define CONTROLADOR_HOSTAL

    #include <string>
    #include <set>
    #include "IControladorHostal.hpp"

    using namespace std;

    class ControladorHostal: public IControladorHostal{
        private:
            static ControladorHostal * instancia;
            ControladorHostal();

            //set<Hostal> hostales;
        public:
            static ControladorHostal * getInstancia();

            //operaciones
            virtual void agregarHostal(DTHostal hostal);
    };

#endif