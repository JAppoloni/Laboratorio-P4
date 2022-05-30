#include <string>
#include "Categoria.hpp"

#ifndef OTROS_HPP
#define OTROS_HPP

class Otros : public Categoria {

   public:
    Otros(std::string, std::string);
    ~Otros() = default;
};

#endif