#include "../common/clases/header/Cargo.hpp"
#include "../common/clases/header/EstadoReserva.hpp"
#include "../common/datatype/header/DTEmpleado.hpp"
#include "../common/datatype/header/DTHuesped.hpp"
#include "../common/datatype/header/DTHostal.hpp"
#include "../common/datatype/header/DTHabitacion.hpp"
#include "../dominio/header/Fabrica.hpp"
#include "../dominio/header/IControladorEstadia.hpp"
#include "../dominio/header/IControladorHostal.hpp"
#include "../dominio/header/IControladorReserva.hpp"
#include "../dominio/header/IControladorUsuario.hpp"
#include "../dominio/header/FechaSistema.hpp"

void cargarDatos()
{
   DTEmpleado *E1 = new DTEmpleado("Emilia", "123", "emilia@mail.com", recepcion);
   DTEmpleado *E2 = new DTEmpleado("Leonardo", "123", "leo@mail.com", recepcion);
   DTEmpleado *E3 = new DTEmpleado("Alina", "123", "alina@mail.com", administracion);
   DTEmpleado *E4 = new DTEmpleado("Barliman", "123", "barli@mail.com", recepcion);

   DTHuesped *H1 = new DTHuesped("Sofia", "123", " sofia@mail.com", true);
   DTHuesped *H2 = new DTHuesped("Frodo", "123", "frodo@mail.com", true);
   DTHuesped *H3 = new DTHuesped("Sam", "123", " sam@mail.com", false);
   DTHuesped *H4 = new DTHuesped("Merry", "123", " merry@mail.com", false);
   DTHuesped *H5 = new DTHuesped("Pippin", "123", "pippin@mail.com", false);
   DTHuesped *H6 = new DTHuesped("Seba", "123", " seba@mail.com", true);

   DTHostal *HO1 = new DTHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111");
   DTHostal *HO2 = new DTHostal("Mochileros", "Rambla Costanera 333", "Rocha 42579512");
   DTHostal *HO3 = new DTHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");
   DTHostal *HO4 = new DTHostal("Altos de Fing", "Av del Toro 1424", "099892992");
   DTHostal *HO5 = new DTHostal("Caverna Lujosa", "Amaya 2515", "233233235");

   DTHabitacion *HA1 = new DTHabitacion(1, 4, 25); // HO1
   DTHabitacion *HA2 = new DTHabitacion(2, 1, 75); // HO1
   DTHabitacion *HA3 = new DTHabitacion(3, 3, 35); // HO1
   DTHabitacion *HA4 = new DTHabitacion(4, 5, 15); // HO1
   DTHabitacion *HA5 = new DTHabitacion(1, 3, 25); // HO5
   DTHabitacion *HA6 = new DTHabitacion(1, 9, 55); // HO3

   Fabrica fab = Fabrica();
   IControladorEstadia *controladorEstadia = fab.getControladorEstadia();
   IControladorHostal *controladorHostal = fab.getControladorHostal();
   IControladorReserva *controladorReserva = fab.getControladorReserva();
   IControladorUsuario *controladorUsuario = fab.getControladorUsuario();
   IFechaSistema *fechaSistema = fab.getFechaSistema();



// controladorUsuario;
//    seleccionarHostal(string nombre)
//        seleccionarEmpleado(string email)
//            seleccionarCargo(Cargo cargo)
//                confirmarAsignacionDeEmpleadoAHostal()
}