#include "header/menuConsultaEstadia.hpp"

void menuConsultaEstadia()
{

   Fabrica fab = Fabrica();
   IControladorHostal *controladorHostal = fab.getControladorHostal();
   set<DTHostal *> hostales = controladorHostal->listarTodosLosHostalesDelSistema();

   if (hostales.empty())
   {
      cout << "No hay hostales cargados" << endl;
   }
   else
   {
      int minElem = 1;
      int maxElem = 0;

      cout << "Hostales: " << endl;
      for (auto it : hostales)
      {
         maxElem++;
         cout << GRN << maxElem << NC << ". " << it->getNombre() << endl;
      }
      cout << "Ingrese el numero del hostal ( " << RED << minElem << " - " << maxElem << NC << " ) :";

      int numHostal = leerIntIntervalo(minElem, maxElem);
      string nombreHostal;

      for (auto it : hostales)
      {
         if (minElem == numHostal)
         {
            nombreHostal = it->getNombre();
         }
         minElem++;
         delete it;
         it = nullptr;
      }
      hostales.clear();

      cout << "El hostal seleccionado es: " << nombreHostal << endl;

      IControladorEstadia *controladorEstadia = fab.getControladorEstadia();
      controladorEstadia->seleccionarHostal(nombreHostal);
      set<DTEstadia *> estadias = controladorEstadia->listarEstadias();

      if (!estadias.empty())
      {
         minElem = 1;
         maxElem = 0;
         cout << "Estadias: " << endl;
         for (auto it : estadias)
         {
            maxElem++;
            cout << GRN << maxElem << NC << ".  ID Reserva: " << it->getID() << " - Correo:" << it->getEmail()
                 << " - Fecha Inicio: " << it->getCheckIn().getHora() << " " << it->getCheckIn().getDia() << "/" << it->getCheckIn().getMes() << "/" << it->getCheckIn().getAnio() << " - Fecha Fin: ";
            if (it->getCheckOut() != nullptr)
            {
               cout << (*it->getCheckOut()).getHora() << " " << (*it->getCheckOut()).getDia() << "/" << (*it->getCheckOut()).getMes() << "/" << (*it->getCheckOut()).getAnio();
            }
            else
            {
               cout << "No se ha realizado el checkout";
            }
            cout << endl;
         }
         cout << "Ingrese el numero de la estadia ( " << RED << minElem << " - " << maxElem << NC << " ) :";
         int numEstadia = leerIntIntervalo(minElem, maxElem);

         string email;
         int idReserva;

         for (auto it : estadias)
         {
            if (minElem == numEstadia)
            {
               email = it->getEmail();
               idReserva = it->getID();
               cout << "La estadia seleccionada tiene el ID Reserva: " << it->getID() << " - Correo:" << it->getEmail()
                 << " - Fecha Inicio: " << it->getCheckIn().getHora() << " " << it->getCheckIn().getDia() << "/" << it->getCheckIn().getMes() << "/" << it->getCheckIn().getAnio() << " - Fecha Fin: ";
            if (it->getCheckOut() != nullptr)
            {
               cout << (*it->getCheckOut()).getHora() << " " << (*it->getCheckOut()).getDia() << "/" << (*it->getCheckOut()).getMes() << "/" << (*it->getCheckOut()).getAnio();
            }
            else
            {
               cout << "No se ha realizado el checkout";
            }
            cout << endl;
               
            }
            delete it;
            it = nullptr;
            minElem++;
         }
         estadias.clear();

         controladorEstadia->seleccionarEstadia(idReserva, email);
         bool salir = false;
         while (!salir)
         {

            cout << "Desea ver el comentario y la respuesta (si existe) (S/N): ";
            string respuesta = leerString();

            if (respuesta == "S" || respuesta == "s")
            {
               salir = true;
               DTCalificacion calif = controladorEstadia->buscarCalificacion();
               if (calif.getIDReserva() > 0)
               {
                  cout << calif << endl;
               }
               else
               {
                  cout << "No hay calificaciones para esta estadia" << endl;
               }
            }
            else if (respuesta == "N" || respuesta == "n")
            {
               salir = true;
            }
            else
            {
               cout << "Opcion incorrecta" << endl;
            }
         }
         
         salir = false;
         while (!salir)
         {

            cout << "Desea ver la Reserva (S/N): ";
            string respuesta = leerString();

            if (respuesta == "S" || respuesta == "s")
            {
               salir = true;

               DTReserva *reserva = controladorEstadia->buscarInformacionReserva();

               if (dynamic_cast<DTReservaGrupal *>(reserva) != nullptr)
               {
                  *dynamic_cast<DTReservaGrupal *>(reserva) << cout << endl;
                  delete dynamic_cast<DTReservaGrupal *>(reserva);
                  reserva = nullptr;
               }
               else if (dynamic_cast<DTReservaIndividual *>(reserva) != nullptr)
               {
                  *dynamic_cast<DTReservaIndividual *>(reserva) << cout << endl;
                  delete dynamic_cast<DTReservaIndividual *>(reserva);
                  reserva = nullptr;
               }
            }
            else if (respuesta == "N" || respuesta == "n")
            {
               salir = true;
            }
            else
            {
               cout << "Opcion incorrecta" << endl;
            }
         }
         controladorEstadia->liberarMemoria();
         controladorEstadia = nullptr;
      }
      else
      {
         cout << "No hay estadias para el hostal seleccionado" << endl;
      }
   }
   controladorHostal = nullptr;
   presioneParaContinuar();
}
