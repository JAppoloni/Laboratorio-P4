#include "presentacion/header/menu.hpp"
#include "Persistencia/header/Collection.hpp"

int main() {
    Sistema* systemData = systemData->GetInstance();

    systemData->agregarHuesped("Renzo Tissoni", "renzo.tissoni@fing.edu.uy", true);
    systemData->agregarHuesped("John Doe", "john.doe@gmail.com", false);

    mainMenu(systemData);

    delete systemData;

    return 0;
}
