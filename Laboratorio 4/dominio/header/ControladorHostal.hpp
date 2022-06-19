#ifndef CONTROLADOR_HOSTAL
#define CONTROLADOR_HOSTAL

#include "IControladorHostal.hpp"
#include "ControladorReserva.hpp"
using namespace std;

class ControladorHostal : public IControladorHostal
{
private:
    static ControladorHostal *instancia;
    map<string, Hostal *> hostales;
    ControladorHostal();

public:
    static ControladorHostal *getInstancia();

    virtual void agregarHostal(DTHostal hostal);
    virtual list<DTHostal *> obtenerHostales();
    virtual void buscarHostal(string nombre);
    virtual void nuevaHabitacion(int numero, int capacidad, float costo);
    virtual void crearHabitacion();
    virtual void liberarMemoria();
    virtual list<DTHostal *> calcularTopTres();
    virtual list<DTCalificacion *> consultarHostal(string nom);

    Hostal *getHostal(string nom);
    set<DTHabitacion *> obtenerHabitacionesDeHostal(string nom);
    set<DTHabitacion *> obtenerHabitacionesDisponiblesDeHostal(string nom, DTFecha in, DTFecha out);

    // para pruebas
    virtual set<DTHostal *> listarTodosLosHostalesDelSistema();

    // para eliminar datos
    virtual void liberarRegistros();
};

#endif