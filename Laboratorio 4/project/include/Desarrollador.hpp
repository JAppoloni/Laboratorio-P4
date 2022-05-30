#ifndef DESARROLLADOR_HPP
#define DESARROLLADOR_HPP

#include <map>
#include <set>
#include <string>
#include "Estadistica.hpp"
#include "EstadisticasDev.hpp"
#include "Usuario.hpp"
#include "Videojuego.hpp"

class Videojuego;
class EstadisticasDev;
class Estadistica;

class Desarrollador : public Usuario {
   private:
    std::string nombre_empresa;
    std::map<int, Videojuego*> VideojuegosCreados;
    EstadisticasDev* EstadisticasDes;

   public:
    Desarrollador(int,
                  std::string email,
                  std::string contrasena,
                  std::string empresa);
    ~Desarrollador(); 
    std::set<std::string> getNombresJuegos();
    void desasociarVideojuegoConDesarrollador(Videojuego*);
    void asociarVideojuegoDesarrollador(int, Videojuego*);
    Videojuego* buscarJuegoPorNombre(std::string);
    std::set<Estadistica*> getEstadisticasDes();
    std::set<std::string> getVideojuegosDesarrolladorSinActivas(Desarrollador*);
    EstadisticasDev* getEstDev();
    std::string getEmpresa();
};

#endif