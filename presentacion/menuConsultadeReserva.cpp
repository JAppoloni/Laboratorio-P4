#include "header/menuConsultadeReserva.hpp"
#include <string>
void menuConsultadeReserva()
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
        cout << "No hay Reservas cargadas para el hostal seleccionado" << endl;
    }
    else
    {
        minElem = 1;
        maxElem = 0;
        cout << "Reservas: " << endl;
        for (auto it : listaReservas)
        {
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
      for(auto it : listaReservas)
      {
        delete it;
      }
      listaReservas.clear();
  }
  presioneParaContinuar();
}
