#include <string>

#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP

class Categoria {
   private:
    std::string nombre;
    std::string descripcion;

   protected:
    Categoria(std::string, std::string);

   public:
    virtual ~Categoria() = default;

    std::string getNombre();
    std::string getDescripcion();
};

#endif
