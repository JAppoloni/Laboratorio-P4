#ifndef _DTHUESPED_HH_
#define _DTHUESPED_HH_

#include "../../clases/header/Huesped.hpp"
#include <string>

class DTHuesped
{
private:
    std::string nombre;
    std::string email;
    bool esFinger;

public:
    DTHuesped(std::string nombre, std::string mail, bool esFinger);
    DTHuesped(Huesped *);

    void imprimir();

    std::string getNombre();
    std::string getEmail();
    bool getEsFinger();
    bool esVacia();
};

std::ostream &operator<<(std::ostream &out, DTHuesped &huesped);

#endif
