#ifndef DTUSUARIO_HPP
#define DTUSUARIO_HPP

#include <string>

class DtUsuario {
   private:
    std::string email;
    std::string password;

   protected:
    DtUsuario(std::string email, std::string password);  // clase abstracta
    DtUsuario() = default;

   public:
    ~DtUsuario() = default;
    std::string getEmail();
    std::string getPassword();
};

#endif