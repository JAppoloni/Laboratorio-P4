#include "header/menuImprimir.hpp"
#include <iostream>

void menuImprimir()
{
   system("clear");
   bool salir = false;
   int cod;
   while (salir == false)
   {
      cout << "Bienvenido!!" << endl
           << endl;

      cout << "1.  ImprimirHostales (string nombre)" << endl;
      cout << "2.  ImprimirReservas(int cod, string email)" << endl;
      cout << "3.  ImprimirUsuario(string email)" << endl;
      cout << "4.  ImprimirEstadias()" << endl;
      cout << "5.  Salir" << endl;
      int opcion = leerIntIntervalo(1, 5);
      if (opcion == 1) 
      {
         string email;
         cout << "Ingrese Email:" << endl;
         getline(cin, email);
         ImprimirHostales(email);
      }
      else if (opcion == 2)
      {
         string email;
         cout << "Ingrese Email:" << endl;
         getline(cin, email);
         cout << "Cod:" << endl;
         cod = leerInt();
         ImprimirReservas(cod, email);
      }
      else if (opcion == 3)

      {
         string email;
         cout << "Ingrese Email:" << endl;
         getline(cin, email);
         ImprimirUsuario(email);
      }
      else if (opcion == 4)
      {
         ImprimirEstadias();
      }
      else if (opcion == 5)
      {
         salir = true;
         break;
      }
      else
      {
         system("clear");
      }
   }
}

void ImprimirHostales(string nombre)
{

   cout << "\n Hostales:" << endl;

   Fabrica fab = Fabrica();
   IControladorHostal *controladorHostal = fab.getControladorHostal();

   set<DTHostal *> hostales = controladorHostal->listarTodosLosHostalesDelSistema();
   for (set<DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
   {
      if ((*it)->getNombre() == nombre)
      {
         cout << **it << endl;
         break;
      }
      else if (nombre == "")
      {
         cout << **it << endl;
      }
   }
   hostales.clear();
}

void ImprimirReservas(int cod, string email)
{

   cout << "\n Reservas:" << endl;
   Fabrica fab = Fabrica();
   IControladorReserva *ControladorReserva = fab.getControladorReserva();
   set<DTReserva *> reservas = ControladorReserva->listarTodasLasReservasDelSistema();
   for (set<DTReserva *>::iterator it = reservas.begin(); it != reservas.end(); ++it)
   {
      if ((*it)->getCodigo() == cod && email == (*it)->getHuesped()->getEmail())
      {
         **it << cout << endl;

         break;
      }
      else if ((*it)->getCodigo() == cod && email == "")
      {
         **it << cout << endl;
      }
      else if (cod <= 0 && email == (*it)->getHuesped()->getEmail())
      {
         **it << cout << endl;
      }
      else if (cod <= 0 && email == "")
      {
         **it << cout << endl;
      }
   }
   reservas.clear();
}

void ImprimirUsuario(string email)
{

   cout << "\n Usuarios:" << endl;
   Fabrica fab = Fabrica();
   IControladorUsuario *ControladorUsuario = fab.getControladorUsuario();
   set<DTUsuario *> setUsuario = ControladorUsuario->obtenerTodosLosUsuariosDelSistema();
   for (set<DTUsuario *>::iterator it = setUsuario.begin(); it != setUsuario.end(); ++it)
   {
      if ((*it)->getEmail() == email)
      {
         **it << cout << endl;
         break;
      }
      else if (email == "")
      {
         **it << cout << endl;
      }
   }
   setUsuario.clear();
}

void ImprimirEstadias()
{

   cout << "\n Estadias:" << endl;
   Fabrica fab = Fabrica();
   IControladorEstadia *ControladorEstadia = fab.getControladorEstadia();
   set<DTEstadia *> estadias = ControladorEstadia->obtenerTodasLasEstadiasDelSistema();
   for (set<DTEstadia *>::iterator it = estadias.begin(); it != estadias.end(); ++it)
   {
      cout << **it << endl;
   }
   estadias.clear();
}