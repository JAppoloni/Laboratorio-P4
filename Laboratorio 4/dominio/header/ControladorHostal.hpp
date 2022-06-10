#ifndef CONTROLADOR_HOSTAL
#define CONTROLADOR_HOSTAL

#include "IControladorHostal.hpp"
using namespace std;

class ControladorHostal : public IControladorHostal
{
private:
    static ControladorHostal *instancia;
    ControladorHostal();

public:
    static ControladorHostal *getInstancia();

     void agregarHostal(DTHostal hostal);
     set<DTHostal> obtenerHostales();
     void buscarHostal(string nombre);
};

#endif