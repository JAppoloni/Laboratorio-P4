#include "presentacion/header/menu.hpp"
#include "persistencia/header/Collection.hpp"
#include "common/datatype/header/DTReservaIndividual.hpp"
#include "common/datatype/header/DTReservaGrupal.hpp"

int main()
{
    Sistema *systemData = new Sistema();

    //DATOS DE PRUEBA

    systemData->agregarHuesped("Renzo Tissoni", "p1", true);
    systemData->agregarHuesped("p2", "p2", false);
    systemData->agregarHuesped("p3", "p3", true);
    systemData->agregarHuesped("p4", "p4", false);
    systemData->agregarHuesped("p5", "p5", true);

    systemData->agregarHabitacion(0, 567, 8);
    systemData->agregarHabitacion(1, 7576, 7);
    systemData->agregarHabitacion(2, 67, 9);
    systemData->agregarHabitacion(101, 10.5, 5);
    systemData->agregarHabitacion(102, 15.0, 6);

    DTReservaIndividual *individual = new DTReservaIndividual(0, DTFecha(12, 12, 2052), DTFecha(12, 12, 2053), Abierta, 0, 101, true);
    systemData->registrarReserva("p1", individual);
    DTReservaIndividual *individual2 = new DTReservaIndividual(0, DTFecha(31, 3, 2002), DTFecha(1, 4, 2002), Abierta, 3456, 0, false);
    systemData->registrarReserva("p2", individual2);

    DTHuesped **listaHuespedes = new DTHuesped *[2];
    listaHuespedes[0] = new DTHuesped("p2", "p2", false);
    listaHuespedes[1] = nullptr;
    DTReservaGrupal *grupal = new DTReservaGrupal(0, DTFecha(6, 6, 2022), DTFecha(1, 12, 2022), Abierta, 0, 102, listaHuespedes);
    systemData->registrarReserva("p1", grupal);
    DTHuesped **listaHuespedes2 = new DTHuesped *[3];
    listaHuespedes2[0] = new DTHuesped("p3", "p3", true);
    listaHuespedes2[1] = new DTHuesped("p4", "p4", false);
    listaHuespedes2[2] = nullptr;
    DTReserva *grupal2 = new DTReservaGrupal(0, DTFecha(26, 3, 2022), DTFecha(27, 3, 2022), Cancelada, 567, 0, listaHuespedes2);
    systemData->registrarReserva("p1", grupal2);

    mainMenu(systemData);

    delete systemData;

    return 0;
}
