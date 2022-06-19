#include "header/menuAsignarEmpleadoAHostal.hpp"

void menuAsignarEmpleadoAHostal()
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

      IControladorUsuario *controladorUsuario = fab.getControladorUsuario();
      controladorUsuario->seleccionarHostal(nombreHostal);
      set<DTEmpleado *> empleados = controladorUsuario->obtenerEmpleadosSinHsotal();

      if (empleados.empty())
      {
         cout << "No hay empleados cargados" << endl;
      }
      else
      {
         minElem = 1;
         maxElem = 0;

         cout << "Empleados: " << endl;
         for (auto it : empleados)
         {
            maxElem++;
            cout << GRN << maxElem << NC << ". " << it->getEmail() << endl;
         }
         cout << "Ingrese el numero del empleado ( " << RED << minElem << " - " << maxElem << NC << " ) :";
         int numEmpleado = leerIntIntervalo(minElem, maxElem);
         string nombreEmpleado;
         for (auto it : empleados)
         {
            if (minElem == numEmpleado)
            {
               nombreEmpleado = it->getEmail();
            }
            minElem++;
            delete it;
            it = nullptr;
         }
         empleados.clear();
         cout << "El empleado seleccionado es: " << nombreEmpleado << endl;
         controladorUsuario->seleccionarEmpleado(nombreEmpleado);
         cout << "Ingrese el Cargo del Empleado (0 - Administración, 1 -Limpieza, 2 - Recepción, 3 - Infraestructura ):";

         Cargo empCargo = (Cargo) leerIntIntervalo(0, 3);

         controladorUsuario->seleccionarCargo(empCargo);

         if (confirmarAccion("la asignación" ))
         {
            controladorUsuario->confirmarAsignacionDeEmpleadoAHostal();
         }
         else
         {
            controladorUsuario->cancelarAsignacion();
         }
      }
      controladorUsuario = nullptr;
   }

   controladorHostal = nullptr;
   cin.ignore();
   presioneParaContinuar();
}
