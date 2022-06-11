#ifndef I_CONTROLADOR_HOSTAL
#define I_CONTROLADOR_HOSTAL

#include <set>
#include <map>
#include <string>
#include "../../common/datatype/header/DTHostal.hpp"
#include "../../common/clases/header/Hostal.hpp"

using namespace std;

class IControladorHostal{
    public:
        virtual void agregarHostal(DTHostal hostal)=0;
        // virtual set<DTHostal> obtenerHostales()=0;
        // virtual void buscarHostal(string nombre)=0; 
};

#endif