#ifndef DTVIDEOJUEGO_HPP
#define DTVIDEOJUEGO_HPP

#include <set>
#include <string>
#include "DtCategoria.hpp"
#include "DtCosto.hpp"

class DtVideojuego {
   private:
    std::string nombre;
    std::string descripcion;
    DtCosto costos;
    std::set<DtCategoria> categoriaGenero;
    std::set<DtCategoria> categoriaOtros;
    std::set<DtCategoria> categoriaPlataformas;

   public:
    ~DtVideojuego() = default;
    DtVideojuego() = default;

    DtVideojuego(std::string nombre,
                 std::string descripcion,
                 DtCosto costos,
                 std::set<DtCategoria> categoriaGenero,
                 std::set<DtCategoria> categoriaOtros,
                 std::set<DtCategoria> categoriaPlataformas);

    std::string getNombre();
    std::string getDescripcion();
    DtCosto getCostos();
    std::set<DtCategoria> getCategoriaGenero();
    std::set<DtCategoria> getCategoriaOtros();
    std::set<DtCategoria> getCategoriaPlataformas();
    bool operator<(const DtVideojuego& param) const;
};

#endif