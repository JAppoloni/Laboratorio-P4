#ifndef I_FECHA_SISTEMA
#define I_FECHA_SISTEMA

#include "../../common/datatype/header/DTFecha.hpp"

class IFechaSistema
{
public:
    virtual DTFecha getFecha() = 0;
    virtual void setFecha(DTFecha fecha) = 0;
};

#endif