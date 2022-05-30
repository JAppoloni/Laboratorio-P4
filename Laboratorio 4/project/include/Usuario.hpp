#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario {
   private:
    int idUser;
    std::string email;
    std::string contrasena;

   protected:
    Usuario(int idUser, std::string email, std::string contrasena);

   public:
    virtual ~Usuario() = default;
    int getId();
    std::string getEmail();
    std::string getContrasena();
};

#endif