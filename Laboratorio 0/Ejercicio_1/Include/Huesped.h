#ifndef _HUESPED_HH_
#define _HUESPED_HH_

#include <string>

class Huesped
{
private:
    std::string nombre;
    std::string email;
    bool esFinger;

public:
    void imprimir();

    std::string getNombre();
    std::string getEmail();
    bool getEsFinger();

    void setNombre(std::string nombre);
    void setEmail(std::string email);
    void setEsFinger(bool esFinger);

    Huesped(std::string, std::string, bool);
    Huesped();
    ~Huesped();
};

#endif