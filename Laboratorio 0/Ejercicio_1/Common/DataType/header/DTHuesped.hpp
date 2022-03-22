#ifndef _DTHUESPED_HH_
#define _DTHUESPED_HH_

#include "../../clases/header/Huesped.hpp"
#include <string>

class DTHuesped {
private:
    std::string nombre;
    std::string email;
    bool esFinger;

public:
    void imprimir();

    std::string getNombre();
    std::string getEmail();
    bool getEsFinger();

    DTHuesped(std::string, std::string, bool);
    DTHuesped(Huesped*);
};

std::ostream& operator<<(std::ostream& out, DTHuesped &huesped);

#endif