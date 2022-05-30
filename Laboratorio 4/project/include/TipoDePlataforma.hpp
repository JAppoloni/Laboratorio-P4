#include <string>
#include "Categoria.hpp"

#ifndef TIPODEPLATAFORMA_HPP
#define TIPODEPLATAFORMA_HPP

class TipoDePlataforma : public Categoria {
   public:
    TipoDePlataforma(std::string, std::string);
    ~TipoDePlataforma() = default;

};

#endif
