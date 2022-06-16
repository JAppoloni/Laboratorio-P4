#ifndef FECHA_SISTEMA
#define FECHA_SISTEMA

#include <string>
#include "IFechaSistema.hpp"
#include "../../common/datatype/header/DTFecha.hpp"

using namespace std;

class FechaSistema : public IFechaSistema
{
private:
    tm _tiepoActual;
    DTFecha _fecha;
    static FechaSistema *instancia;
    FechaSistema();

public:
    static FechaSistema *getInstancia();
    DTFecha getFecha();
    void setFecha(DTFecha fecha);
    virtual void liberarRegistros();
};

#endif