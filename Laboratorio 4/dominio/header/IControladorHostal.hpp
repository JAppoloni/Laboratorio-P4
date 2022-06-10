#ifndef I_CONTROLADOR_HOSTAL
#define I_CONTROLADOR_HOSTAL

#include <set>
#include <string>
#include "../../common/datatype/header/DTHostal.hpp"

using namespace std;
//falta incluir Data Types

class IControladorHostal{
    public:
        virtual void agregarHostal(DTHostal hostal)=0;
        virtual set<DTHostal> obtenerHostales()=0;
        virtual void buscarHostal(string nombre)=0; 
};

#endif