#ifndef ESTADISTICA_HPP
#define ESTADISTICA_HPP

#include <string>
#include "Videojuego.hpp"

class Videojuego;

class Estadistica {
   private:
    std::string name;
    std::string desc;

   public:
    Estadistica(std::string name, std::string desc);
    virtual ~Estadistica() = default;
    virtual double getDato(Videojuego*) = 0;

    void setName(std::string);
    void setDesc(std::string);
    std::string getName();
    std::string getDesc();
};

#endif