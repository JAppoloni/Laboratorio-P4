#include <string>
#include "Categoria.hpp"

#ifndef GENERO_HPP
#define GENERO_HPP

class Genero : public Categoria {

   public:
    ~Genero() = default;
    Genero(std::string, std::string);

};

#endif
