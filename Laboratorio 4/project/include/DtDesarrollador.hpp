#include <string>
#include "DtUsuario.hpp"

#ifndef DTDES_HPP
#define DTDES_HPP

class DtDesarrollador : public DtUsuario {
   private:
    std::string empresa;

   public:
    DtDesarrollador(std::string email,
                    std::string password,
                    std::string empresa);
    DtDesarrollador() = default;
    ~DtDesarrollador() = default;
    std::string getEmpresa();
};

#endif