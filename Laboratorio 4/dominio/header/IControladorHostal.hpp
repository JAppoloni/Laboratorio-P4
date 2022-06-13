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
        virtual void agregarHostal(DTHostal hostal) = 0;//alta hostal
        virtual set<DTHostal *> obtenerHostales() = 0;//alta habitacion; asignar empleado a hostal 
        virtual void buscarHostal(string nombre) = 0;//alta habitacion
        virtual void nuevaHabitacion(int numero, int capacidad, float costo) = 0;//alta habitacion
        virtual void crearHabitacion() = 0;//alta habitacion
        virtual void liberarMemoria() = 0;//alta habitacion
};

#endif