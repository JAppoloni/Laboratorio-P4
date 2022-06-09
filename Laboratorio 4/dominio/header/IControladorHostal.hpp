#ifndef I_CONTROLADOR_HOSTAL
#define I_CONTROLADOR_HOSTAL

#include <set>
#include <string>

using namespace std;
//falta incluir Data Types y clases

class IControladorHostal{
    public:
        virtual void agregarHostal(DTHostal hostal) = 0;

};

#endif