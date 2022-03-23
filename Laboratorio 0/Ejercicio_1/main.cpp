#include "presentacion/header/menu.hpp"
#include "persistencia/header/Collection.hpp"

int main() {
    Sistema* systemData = new Sistema();

    systemData->agregarHuesped("Renzo Tissoni", "renzo.tissoni@fing.edu.uy", true);
    systemData->agregarHuesped("John Doe", "john.doe@gmail.com", false);
    systemData->agregarHabitacion(101, 10.5, 2);
    systemData->agregarHabitacion(102, 15.0, 3);

    mainMenu(systemData);

    delete systemData;

    return 0;
}
