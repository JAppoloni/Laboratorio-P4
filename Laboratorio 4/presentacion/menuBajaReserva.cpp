
#include "header/menuBajaReserva.hpp"
#include <string>
void menuBajaReserva()
{
   Fabrica fabrica = Fabrica();
   IControladorHostal *contoraladoraHostal = fabrica.getControladorHostal();
   IControladorReserva *controladorReserva = fabrica.getControladorReserva();
   list<DTHostal *> listaHostales = contoraladoraHostal->obtenerHostales();

   int minElem = 1;
   int maxElem = 1;

   cout << "Hostales: " << endl;
   for (auto it : listaHostales)
   {
      cout << GRN << maxElem << NC << ". " << it->getNombre() << endl;
      maxElem++;
   }
   cout << "Ingrese el numero del hostal: ( " << RED << minElem << " - " << maxElem << NC << " )" << endl;
   int numHostal = leerIntIntervalo(minElem, maxElem);

   string nombreHostal;
   for (auto it : listaHostales)
   {
      if (minElem == maxElem)
      {
         nombreHostal = it->getNombre();
         break;
      }
      minElem++;
   }
   cout << "El hostal seleccionado es: " << nombreHostal << endl;
   controladorReserva->seleccionarHostal(nombreHostal);

   set<DTReserva *> listaReservas = controladorReserva->listarReservas();

   minElem = 1;
   maxElem = 1;
   cout << "Reservas: " << endl;
   for (auto it : listaReservas)
   {
      cout << GRN << maxElem << NC << ".  " << it->getCodigo() << endl;
      maxElem++;
   }
   cout << "Ingrese el numero de la reserva: ( " << RED << minElem << " - " << maxElem << NC << " )" << endl;
   int numReserva = leerIntIntervalo(minElem, maxElem);
   string codigoReserva;
   for (auto it : listaReservas)
   {
      if (minElem == maxElem)
      {
         codigoReserva = it->getCodigo();
         break;
      }
      minElem++;
   }
   cout << "La reserva seleccionada es: " << codigoReserva << endl;
   controladorReserva->borrarReserva(codigoReserva);
}

// //controlador hostal
// list<DTHostal *> obtenerHostales()
// //controlador reserva
// void seleccionarHostal(string nom)
// set<DTReserva *> listarReservas()
// void seleccionarReservaAEliminar(int codigo)
// void cancelarBaja()
// void confirmarBaja()

/*El caso de uso comienza cuando un usuario desea eliminar una reserva del sistema.
Para ello, el sistema lista todos los hostales y el usuario selecciona uno de ellos. A
continuación, el sistema retorna la lista de todas las reservas y el empleado selecciona
la reserva que desea eliminar ingresando su código. El usuario indica si confirma la
baja o cancela. En caso de confirmar, se elimina la reserva del sistema junto a toda la
información asociada a ella, entre la que se encuentra las estadías, consumiciones y
calificaciones asociadas.*/