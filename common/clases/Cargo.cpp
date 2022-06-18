#include <iostream>
#include "header/Cargo.hpp"

void imprimirCargo(Cargo c)
{
   switch (c)
   {
   case administracion:
      std::cout << "Administracion";
      break;
   case limpieza:
      std::cout << "Limpieza";
      break;
   case recepcion:
      std::cout << "Recepcion";
      break;
   case infraestructura:
      std::cout << "Infraestructura";
      break;
   default:
      break;
   }
}