#include <unistd.h>

#include "header/menuCargarDatos.hpp"

void progress(float &iter, int tope, bool eliminar)
{
   if (eliminar)
      cout << "\x1b[2K"; // Delete current line

   double percentage = (iter / tope);
   printProgress(percentage);
   usleep(199900);
   iter++;
}

void cargarDatos(bool primeraVez)
{
   if (primeraVez == false)
   {
      cout << "Ya ha usado esta opción. No se pueden volver a cargar los datos que ya existen en el Sistema. " << endl;
      return;
   }
   //----------------------------------------------------------------------------------------------------------------------
   int tope = 11;
   float iter = 0;
   cout << "\n\n\n\n\t\t\t\t   Loading " << endl;
   progress(iter, tope, false);
   //----------------------------------------------------------------------------------------------------------------------

   Fabrica fab = Fabrica();
   IControladorHostal *controladorHostal = fab.getControladorHostal();
   // ! IControladorReserva *controladorReserva = fab.getControladorReserva();
   IControladorUsuario *controladorUsuario = fab.getControladorUsuario();
   // ! IControladorEstadia *controladorEstadia = fab.getControladorEstadia();
   // ! IFechaSistema *fechaSistema = fab.getFechaSistema();

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------

   DTEmpleado *E1 = new DTEmpleado("Emilia", "123", "emilia@mail.com", recepcion);
   DTEmpleado *E2 = new DTEmpleado("Leonardo", "123", "leo@mail.com", recepcion);
   DTEmpleado *E3 = new DTEmpleado("Alina", "123", "alina@mail.com", administracion);
   DTEmpleado *E4 = new DTEmpleado("Barliman", "123", "barli@mail.com", recepcion);

   controladorUsuario->ingresarUsuario(E1);
   controladorUsuario->confirmarAlta();
   controladorUsuario->ingresarUsuario(E2);
   controladorUsuario->confirmarAlta();
   controladorUsuario->ingresarUsuario(E3);
   controladorUsuario->confirmarAlta();
   controladorUsuario->ingresarUsuario(E4);
   controladorUsuario->confirmarAlta();

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------

   DTHuesped *H1 = new DTHuesped("Sofia", "123", " sofia@mail.com", true);
   DTHuesped *H2 = new DTHuesped("Frodo", "123", "frodo@mail.com", true);
   DTHuesped *H3 = new DTHuesped("Sam", "123", " sam@mail.com", false);
   DTHuesped *H4 = new DTHuesped("Merry", "123", " merry@mail.com", false);
   DTHuesped *H5 = new DTHuesped("Pippin", "123", "pippin@mail.com", false);
   DTHuesped *H6 = new DTHuesped("Seba", "123", " seba@mail.com", true);

   controladorUsuario->ingresarUsuario(H1);
   controladorUsuario->confirmarAlta();
   controladorUsuario->ingresarUsuario(H2);
   controladorUsuario->confirmarAlta();
   controladorUsuario->ingresarUsuario(H3);
   controladorUsuario->confirmarAlta();
   controladorUsuario->ingresarUsuario(H4);
   controladorUsuario->confirmarAlta();
   controladorUsuario->ingresarUsuario(H5);
   controladorUsuario->confirmarAlta();
   controladorUsuario->ingresarUsuario(H6);
   controladorUsuario->confirmarAlta();

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------

   DTHostal HO1 = DTHostal("La posada del finger", "Av de la playa 123, Maldonado", "099topetopetope");
   DTHostal HO2 = DTHostal("Mochileros", "Rambla Costanera 333", "Rocha 42579512");
   DTHostal HO3 = DTHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");
   DTHostal HO4 = DTHostal("Altos de Fing", "Av del Toro 1424", "099892992");
   DTHostal HO5 = DTHostal("Caverna Lujosa", "Amaya 2515", "233233235");

   controladorHostal->agregarHostal(HO1);
   controladorHostal->agregarHostal(HO2);
   controladorHostal->agregarHostal(HO3);
   controladorHostal->agregarHostal(HO4);
   controladorHostal->agregarHostal(HO5);

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------

   DTHabitacion *HA1 = new DTHabitacion(1, 40, 2); // HO1
   DTHabitacion *HA2 = new DTHabitacion(2, 10, 7); // HO1
   DTHabitacion *HA3 = new DTHabitacion(3, 30, 3); // HO1
   DTHabitacion *HA4 = new DTHabitacion(4, 5, 12); // HO1
   DTHabitacion *HA5 = new DTHabitacion(1, 3, 2);  // HO5
   DTHabitacion *HA6 = new DTHabitacion(1, 9, 5);  // HO3

   controladorHostal->buscarHostal(HO1.getNombre());
   controladorHostal->nuevaHabitacion(HA1->getNumero(), HA1->getPrecio(), HA1->getCapacidad());
   controladorHostal->crearHabitacion();
   controladorHostal->buscarHostal(HO1.getNombre());
   controladorHostal->nuevaHabitacion(HA2->getNumero(), HA2->getPrecio(), HA2->getCapacidad());
   controladorHostal->crearHabitacion();
   controladorHostal->buscarHostal(HO1.getNombre());
   controladorHostal->nuevaHabitacion(HA3->getNumero(), HA3->getPrecio(), HA3->getCapacidad());
   controladorHostal->crearHabitacion();
   controladorHostal->buscarHostal(HO1.getNombre());
   controladorHostal->nuevaHabitacion(HA4->getNumero(), HA4->getPrecio(), HA4->getCapacidad());
   controladorHostal->crearHabitacion();
   controladorHostal->buscarHostal(HO5.getNombre());
   controladorHostal->nuevaHabitacion(HA5->getNumero(), HA5->getPrecio(), HA5->getCapacidad());
   controladorHostal->crearHabitacion();
   controladorHostal->buscarHostal(HO3.getNombre());
   controladorHostal->nuevaHabitacion(HA6->getNumero(), HA6->getPrecio(), HA6->getCapacidad());
   controladorHostal->crearHabitacion();

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------

   // E1 HO1 Recepción
   // E2 HO2 Recepción
   // E3 HO2 Administración
   // E4 HO3 Recepción

   controladorUsuario->seleccionarHostal(HO1.getNombre());
   controladorUsuario->seleccionarEmpleado(E1->getNombre());
   controladorUsuario->seleccionarCargo(E1->getCargo());
   controladorUsuario->confirmarAsignacionDeEmpleadoAHostal();
   controladorUsuario->seleccionarHostal(HO2.getNombre());
   controladorUsuario->seleccionarEmpleado(E2->getNombre());
   controladorUsuario->seleccionarCargo(E2->getCargo());
   controladorUsuario->confirmarAsignacionDeEmpleadoAHostal();
   controladorUsuario->seleccionarHostal(HO2.getNombre());
   controladorUsuario->seleccionarEmpleado(E3->getNombre());
   controladorUsuario->seleccionarCargo(E3->getCargo());
   controladorUsuario->confirmarAsignacionDeEmpleadoAHostal();
   controladorUsuario->seleccionarHostal(HO3.getNombre());
   controladorUsuario->seleccionarEmpleado(E4->getNombre());
   controladorUsuario->seleccionarCargo(E4->getCargo());
   controladorUsuario->confirmarAsignacionDeEmpleadoAHostal();

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------
   // Reservas
   // Ref Hostel Habitación Tipo Check in Check out Huespedes
   // R1 HO1 HA1 Individual 01/05/22 - 2pm 10/05/22 - 10am H1
   // R2 HO3 HA6 Grupal 04/01/01 - 8pm 05/01/01 - 2am H2,H3,H4,H5
   // R3 HO1 HA3 Individual 7/06/22 - 2pm 30/06/22 - topeam H1
   // R4 HO5 HA5 Individual 10/06/22 - 2pm 30/06/22 - topeam H6

   // ! controladorReserva; // Operación No implementada

   // Se debe modificar constantemetne la fecha del sistema

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------

   // Estadías
   // Ref Reserva Huesped Check in
   // ES1 R1 H1 01/05/22 - 6pm
   // ES2 R2 H2 04/01/01 - 9pm
   // ES3 R2 H3 04/01/01 - 9pm
   // ES4 R2 H4 04/01/01 - 9pm
   // ES5 R2 H5 04/01/01 - 9pm
   // ES6 R4 H6 07/06/22 - 6pm

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------
   // Finalización de estadías
   // Estadía Huesped Check out
   // ES1 H1 10/05/22 - 9am
   // ES2 H2 05/01/01 - 2am
   // ES6 H6 15/06/22 - 10pm

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------

   // Calificar estadía
   // Ref Estadía Huesped Comentario Calificación Fecha
   // C1 ES1 H1 "Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo."  3 tope/05/22 - 6pm
   // C2 ES2 H2 "Se pone peligroso de noche, no  recomiendo. Además no hay caja fuerte para guardar anillos. " 2 05/01/01 - 3am
   // C3 ES6 H6 "Había pulgas en la habitación. Que lugar más mamarracho!!" 1 15/06/22 - topepm

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   //----------------------------------------------------------------------------------------------------------------------

   // Comentar calificación
   // Calificación Empleado Respuesta Fecha
   // C2 E4 "Desapareció y se fue sin pagar." 06/01/01 - 3pm

   //----------------------------------------------------------------------------------------------------------------------
   progress(iter, tope, true);
   cout << endl;
   presioneParaContinuar();
   //----------------------------------------------------------------------------------------------------------------------
}