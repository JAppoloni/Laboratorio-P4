#ifndef I_CONTROLADOR_HOSTAL
#define I_CONTROLADOR_HOSTAL

#include <set>
#include <map>
#include <string>
#include "../../common/datatype/header/DTHostal.hpp"
#include "../../common/clases/header/Hostal.hpp"

using namespace std;

class IControladorHostal
{
public:
    virtual void agregarHostal(DTHostal hostal) = 0;                          // alta hostal
    virtual list<DTHostal *> obtenerHostales() = 0;                           // alta habitacion; asignar empleado a hostal; realizar reserva(imprimri también prom. calif.); registrar estadia; finalizar estadia; calificar estadia; Consulta de Estadia
    virtual void buscarHostal(string nombre) = 0;                             // alta habitacion
    virtual void nuevaHabitacion(int numero, int capacidad, float costo) = 0; // alta habitacion
    virtual void crearHabitacion() = 0;                                       // alta habitacion
    virtual void liberarMemoria() = 0;                                        // alta habitacion
    virtual list<DTHostal *> calcularTopTres() = 0;                           // consultar top 3 hostales
    virtual list<DTCalificacion *> consultarHostal(string nom) = 0;           // consultar top 3 hostales

    // para pruebas
    virtual set<DTHostal *> listarTodosLosHostalesDelSistema() = 0;

    // para eliminar datos
    virtual void liberarRegistros() = 0;
};

#endif