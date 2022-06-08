#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include <string>

class Usuario
{
protected:
    std::string nombre;
    std::string email;
    std::string contrasena;

public:
    Usuario(std::string, std::string, std::string);
    Usuario();

    virtual ~Usuario();
    void imprimir();

    std::string getNombre();
    std::string getEmail();
    std::string getContrasena();

    void setNombre(std::string nombre);
    void setEmail(std::string email);
    void setContrasena(std::string contrasena);

    bool operator==(const Usuario &c) const;
    bool operator==(const Usuario *&c) const;
};
#endif