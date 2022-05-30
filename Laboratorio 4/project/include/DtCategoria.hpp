#include <string>
#include "TipoCat.hpp"

#ifndef DTCATEGORIA_HPP
#define DTCATEGORIA_HPP

class DtCategoria {
   private:
    std::string nombre;
    std::string descripcion;
    TipoCat tipo;

   public:
    DtCategoria(std::string nombre, std::string descripcion, TipoCat tipo);

    ~DtCategoria() = default;
    std::string getNombre();
    std::string getDescripcion();
    TipoCat getTipo();
    bool operator<(const DtCategoria& param) const;
};

#endif