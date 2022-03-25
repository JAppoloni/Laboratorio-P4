#include "presentacion/header/menu.hpp"
#include "persistencia/header/Collection.hpp"
#include "common/datatype/header/DTReservaIndividual.hpp"
#include "common/datatype/header/DTReservaGrupal.hpp"

int main()
{
    Sistema *systemData = new Sistema();

    systemData->agregarHuesped("Renzo Tissoni", "renzo.tissoni@fing.edu.uy", true);
    systemData->agregarHuesped("John Doe", "john.doe@gmail.com", false);
    systemData->agregarHabitacion(101, 10.5, 2);
    systemData->agregarHabitacion(102, 15.0, 3);

    DTReservaIndividual *individual = new DTReservaIndividual(1, DTFecha(12, 12, 2052), DTFecha(12, 12, 2053), Abierta, 0, 101, true);
    systemData->registrarReserva("renzo.tissoni@fing.edu.uy", individual);

    DTHuesped **listaHuespedes = new DTHuesped *[2];
    listaHuespedes[0] = new DTHuesped("John Doe", "john.doe@gmail.com", false);
    listaHuespedes[1] = NULL;
    DTReservaGrupal *grupal = new DTReservaGrupal(2, DTFecha(6, 6, 2022), DTFecha(1, 12, 2022), Abierta, 0, 102, listaHuespedes);
    systemData->registrarReserva("renzo.tissoni@fing.edu.uy", grupal);

    mainMenu(systemData);

    delete systemData;

    return 0;
}
