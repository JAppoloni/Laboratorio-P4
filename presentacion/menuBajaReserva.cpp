
#include "header/menuBajaReserva.hpp"
#include <string>

void menuBajaReserva()
{
   Fabrica fabrica = Fabrica();
   IControladorHostal *contoraladoraHostal = fabrica.getControladorHostal();
   IControladorReserva *controladorReserva = fabrica.getControladorReserva();
   list<DTHostal *> listaHostales = contoraladoraHostal->obtenerHostales();

   if (listaHostales.empty())
   {
      cout << "No hay hostales cargados" << endl;
   }
   else
   {
      int minElem = 1;
      int maxElem = 0;

      cout << "Hostales: " << endl;
      for (auto it : listaHostales)
      {
         maxElem++;
         cout << GRN << maxElem << NC << ". " << it->getNombre() << endl;
      }
      cout << "Ingrese el numero del hostal ( " << RED << minElem << " - " << maxElem << NC << " ) :";

      int numHostal = leerIntIntervalo(minElem, maxElem);
      string nombreHostal;

      for (auto it : listaHostales)
      {
         if (minElem == numHostal)
         {
            nombreHostal = it->getNombre();
         }
         minElem++;
         delete it;
         it = nullptr;
      }
      listaHostales.clear();

      cout << "El hostal seleccionado es: " << nombreHostal << endl;
      controladorReserva->seleccionarHostal(nombreHostal);
      set<DTReserva *> listaReservas = controladorReserva->listarReservas();

      if (listaReservas.empty())
      {
         cout << "No hay Reservas cargadas" << endl;
      }
      else
      {
         minElem = 1;
         maxElem = 0;
         cout << "Reservas: " << endl;
         for (auto it : listaReservas)
         {
            maxElem++;
            cout << GRN << maxElem << NC << ". Codigo: " << it->getCodigo() << " - Fecha Inicio: " << it->getCheckIn().getHora() << " " << it->getCheckIn().getDia() << "/" << it->getCheckIn().getMes() << "/" << it->getCheckIn().getAnio() << " - Fecha Fin: " << it->getCheckOut().getHora() << " " << it->getCheckOut().getDia() << "/" << it->getCheckOut().getMes() << "/" << it->getCheckOut().getAnio() << endl;
         }

         cout << "Ingrese el numero de la reserva ( " << RED << minElem << " - " << maxElem << NC << " ) :"; // << endl;
         int numReserva = leerIntIntervalo(minElem, maxElem);
         int codigoReserva;

         for (auto it : listaReservas)
         {
            if (minElem == numReserva)
            {
               codigoReserva = it->getCodigo();
            }
            minElem++;
            delete it;
            it = nullptr;
         }
         listaReservas.clear();

         cout << "La reserva seleccionada es: " << codigoReserva << endl;

         controladorReserva->seleccionarReservaAEliminar(codigoReserva);

         try
         {
            if (confirmarAccion("la baja"))
            {
               controladorReserva->confirmarAccion();
            }
            else
            {
               controladorReserva->cancelarBaja();
            }
         }
         catch (const std::exception &e)
         {
            std::cerr << RED "\n ERROR: " << e.what() << NC << '\n';
         }
         cin.ignore();
      }
   }
   contoraladoraHostal = nullptr;
   controladorReserva = nullptr;
   presioneParaContinuar();
}