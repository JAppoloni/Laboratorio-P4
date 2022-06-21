#include "header/menuRealizarReserva.hpp"

int leerIntIntervaloxString(int menor, int mayor, string numero)
{
   int num;
   bool valido = false;
   try
   {
      num = stoi(numero);
   }
   catch (const std::exception &e)
   {
      std::cout << "\n Ingrese un número correcto: ";

      while (valido == false)
      {
         try
         {
            string aux;
            getline(cin, aux);
            num = stoi(aux);
            if (num < menor || num > mayor)
            {
               std::cout << "\n Ingrese un número entre " << RED << menor << NC << " y " << RED << mayor << NC << ": ";
            }
            else
            {
               valido = true;
            }
         }
         catch (const std::exception &e)
         {
            std::cout << "\n Ingrese un número correcto: ";
         }
      }
   }
   return num;
}

void menuRealizarReserva()
{
   cout << "Realizar Reserva" << endl;

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

      DTFecha fechaInicio;
      DTFecha fechaFin;

      cout << " Ingrese la fecha de CheckIN (dd/mm/yyyy hh:mm D): ";
      fechaInicio = ingresarFecha();

      bool opcionCorrecta = false;

      while (!opcionCorrecta)
      {
         cout << " Ingrese la fecha de CheckOUT (dd/mm/yyyy hh:mm D): ";
         fechaFin = ingresarFecha();
         if (fechaFin < fechaInicio)
         {
            cout << "La fecha de CheckOUT debe ser mayor a la fecha de CheckIN" << endl;
         }
         else
         {
            opcionCorrecta = true;
         }
      }

      bool esReservaGrupal = false;
      opcionCorrecta = false;
      while (!opcionCorrecta)
      {
         cout << "Es reserva grupal? (S/N): ";
         string seleccion = leerString();
         if (seleccion != "S" && seleccion != "s" && seleccion != "N" && seleccion != "n")
         {
            cout << "Seleccione una de las opciones disponibles." << endl;
         }
         else
         {
            if (seleccion == "S" || seleccion == "s")
               esReservaGrupal = true;
            opcionCorrecta = true;
         }
      }

      controladorReserva->crearReserva(nombreHostal, fechaInicio, fechaFin, esReservaGrupal);
      set<DTHabitacion *> habitacionesDisponibles = controladorReserva->listarHabitacionesDisponibles(nombreHostal, fechaInicio, fechaFin);

      if (!habitacionesDisponibles.empty())
      {
         cout << "Habitaciones disponibles: " << endl;
         minElem = 1;
         maxElem = 0;
         for (auto it : habitacionesDisponibles)
         {
            maxElem++;
            cout << GRN << maxElem << NC << ". " << it->getNumero() << endl;
         }
         cout << "Ingrese el numero de la habitacion ( " << RED << minElem << " - " << maxElem << NC << " ) :";
         int opcion = leerIntIntervalo(minElem, maxElem);
         int numeroHabitacion;
         for (auto it : habitacionesDisponibles)
         {
            if (minElem == opcion)
            {
               numeroHabitacion = it->getNumero();
            }
            minElem++;
            delete it;
            it = nullptr;
         }
         habitacionesDisponibles.clear();
         cout << "La habitacion seleccionada es: " << numeroHabitacion << endl;
         controladorReserva->asignarHabitacionAReserva(numeroHabitacion);

         IControladorUsuario *controladorUsuario = fabrica.getControladorUsuario();
         set<DTHuesped *> listaHuespedes = controladorUsuario->listarHuespedes();
         controladorUsuario = nullptr;

         if (!listaHuespedes.empty())
         {
            cout << "Huesped que Realiza la reserva: " << endl;
            minElem = 1;
            maxElem = 0;
            for (auto it : listaHuespedes)
            {
               maxElem++;
               cout << GRN << maxElem << NC << ". " << it->getEmail() << endl;
            }
            cout << "Ingrese el numero del huesped ( " << RED << minElem << " - " << maxElem << NC << " ) :";
            opcion = leerIntIntervalo(minElem, maxElem);
            string nombreHuesped;

            set<DTHuesped *>::iterator huesp;
            for (set<DTHuesped *>::iterator it = listaHuespedes.begin(); it != listaHuespedes.end(); it++)
            {
               if (minElem == opcion)
               {
                  nombreHuesped = (*it)->getEmail();
                  huesp = it;
                  break;
               }
               minElem++;
            }
            listaHuespedes.erase(*huesp);
            delete (*huesp);

            cout << "El huesped seleccionado es: " << nombreHuesped << endl;
            controladorReserva->asignarHuespedQueRealizaReserva(nombreHuesped);

            if (esReservaGrupal)
            {
               opcionCorrecta = false;

               while (!opcionCorrecta)
               {
                  if (!listaHuespedes.empty())
                  {
                     string nombreHuespedGrupal;

                     cout << "Huespedes que asisten a la reserva: " << endl;
                     minElem = 1;
                     maxElem = 0;
                     for (auto it : listaHuespedes)
                     {
                        maxElem++;
                        cout << GRN << maxElem << NC << ". " << it->getEmail() << endl;
                     }
                     cout << "Ingrese el numero del huesped ( " << RED << minElem << " - " << maxElem << NC << " o C para salir ) :";
                     nombreHuespedGrupal = leerString();

                     if (nombreHuespedGrupal == "C" || nombreHuespedGrupal == "c")
                     {
                        opcionCorrecta = true;
                     }
                     else
                     {
                        opcion = leerIntIntervaloxString(minElem, maxElem, nombreHuespedGrupal);

                        for (set<DTHuesped *>::iterator it = listaHuespedes.begin(); it != listaHuespedes.end(); it++)
                        {
                           if (minElem == opcion)
                           {
                              nombreHuespedGrupal = (*it)->getEmail();
                              huesp = it;
                              break;
                           }
                           minElem++;
                        }
                        listaHuespedes.erase(*huesp);
                        delete (*huesp);
                        cout << "El huesped seleccionado es: " << nombreHuespedGrupal << endl;
                        controladorReserva->asignarHuespedAReservaGrupal(nombreHuespedGrupal);
                     }
                  }
                  else
                  {
                     cout << "No hay huespedes disponibles" << endl;
                     opcionCorrecta = true;
                  }
               }
            }

            if (!listaHuespedes.empty())
            {
               for (auto it : listaHuespedes)
               {
                  delete it;
                  it = nullptr;
               }
            }

            if (confirmarAccion("realizar reserva"))
            {
               controladorReserva->confirmarReserva();
            }
            else
            {
               controladorReserva->cancelarReserva();
            }
         }
         else
         {
            cout << "No hay huespedes cargados" << endl;
            controladorReserva->cancelarReserva();
         }
      }
      else
      {
         cout << "No hay habitaciones disponibles" << endl;
         controladorReserva->cancelarReserva();
      }
   }

   contoraladoraHostal = nullptr;
   controladorReserva = nullptr;
   cin.ignore();
   presioneParaContinuar();
}