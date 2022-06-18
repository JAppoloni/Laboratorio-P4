#include <iostream>
#include "header/EstadoReserva.hpp"

void imprimirEstadoReserva(EstadoReserva estado)
{
   switch (estado)
   {
   case Abierta:
      std::cout << "Abierta";
      break;
   case Cerrada:
      std::cout << "Cerrada";
      break;
   case Cancelada:
      std::cout << "Cancelada";
      break;
   default:
      break;
   }
}