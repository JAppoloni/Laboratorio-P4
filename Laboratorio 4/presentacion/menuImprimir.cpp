#include "header/menuImprimir.hpp"

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
      else
      {
         cout << RED "Hostal no encontrado:" NC << endl;
      }
   }
   hostales.clear();
}

void ImprimirReservas(int cod)
{

   cout << "\n Reservas:" << endl;
   Fabrica fab = Fabrica();
   IControladorReserva *ControladorReserva = fab.getControladorReserva();
   set<DTReserva *> reservas = ControladorReserva->listarTodasLasReservasDelSistema();
   for (set<DTReserva *>::iterator it = reservas.begin(); it != reservas.end(); ++it)
   {
      if ((*it)->getCodigo() == cod)
      {
         **it << cout << endl;

         break;
      }
      else if (cod <= 0)
      {
         **it << cout << endl;
      }
      else
      {
         cout << RED "Reserva no encontrada:" NC << endl;
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
      else
      {
         cout << RED "Usuario no encontrado:" NC << endl;
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
      cout << *it << endl;
   }
   estadias.clear();
}