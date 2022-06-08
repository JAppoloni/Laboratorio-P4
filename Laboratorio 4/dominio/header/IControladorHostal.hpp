#ifndef I_CONTROLADOR_HOSTAL
#define I_CONTROLADOR_HOSTAL

#include <set>
#include <string>

using namespace std;
//falta incluir Data Types

class IControladorHostal{
    public:
        virtual void agregarHostal(DTHostal hostal);
        virtual set<DTHostal> obtenerHostales();
        virtual void buscarHostal(string nombre); 
};

#endif