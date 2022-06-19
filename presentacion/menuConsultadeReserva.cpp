#include "header/menuConsultadeReserva.hpp"
#include <string>
void menuConsultadeReserva()
{
   Fabrica fabrica = Fabrica();
   IControladorHostal *controladorHostal = fabrica.getControladorHostal();
   IControladorReserva *controladorReserva = fabrica.getControladorReserva();
   list<DTHostal *> listaHostales = controladorHostal->obtenerHostales();
   int minElem = 1;
   int maxElem = 1;
     cout << "Hostales: " << endl;
   for (auto it : listaHostales) {
      cout << GRN << maxElem << NC << ". " << it->getNombre() << endl;
      maxElem++;
    }
   cout << "Ingrese el numero del hostal: ( " << RED << minElem << " - " << maxElem << NC << " )" << endl;
   int numHostal = leerIntIntervalo(minElem, maxElem);
   string nombreHostal;
   for (auto it : listaHostales) {
      if (minElem == maxElem) {
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
   for (auto it : listaReservas){
      cout << GRN << maxElem << NC << ".  " << it->getCodigo() <<endl;
      cout << GRN << "Habitacion: "<< it->getHabitacion()->getNumero() <<endl;
      cout << GRN <<  "Costo: "<< it->getCosto() <<endl;
      if (it->getEstado() == 0)
        cout << GRN << "Estado de reserva: abierta"<<endl;
      if (it->getEstado() == 1){
        cout << GRN << "Estado de reserva: cerrada"<<endl;
        cout <<  GRN <<  "Fecha CheckIn:";
        it->getCheckIn().Imprimir();
        cout<<endl;
      }
      if (it->getEstado() == 2)
        cout << GRN << "Estado de reserva: cancelada"<<endl;

      if (dynamic_cast<DTReservaGrupal *>(it) != nullptr){
        DTReservaGrupal* aux = dynamic_cast<DTReservaGrupal*>(it);
        list<DTHuesped>* l = aux->getListaHuesped();
        cout << GRN << "Huespedes: ";
        for (list<DTHuesped>::iterator t = l->begin(); t!= l->end();++t) {
            cout << maxElem << (*t).getNombre()<< ", ";
        }
        cout<<endl;
      }
      else {
        cout << "Huesped: " << it->getHuesped()->getNombre() <<endl; //nombre
      }

      maxElem++;

    }

}
/*
El caso de uso comienza cuando un usuario desea consultar la información de una
reserva registrada. El sistema lista todos los hostales registrados y el usuario
selecciona uno. A continuación, el sistema lista las reservas que se han hecho en ese
hostal, sea cual sea su estado, incluyendo la información básica, el número de
habitación para el que se hizo la reserva y los nombres de los huéspedes en caso de ser
una reserva grupal.

listarhostales()
seleccionarhostal
listarReservas



*/