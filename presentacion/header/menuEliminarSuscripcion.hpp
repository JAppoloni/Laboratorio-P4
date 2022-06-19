#ifndef MENU_ELIMINAR_SUSCRIPCION
#define MENU_ELIMINAR_SUSCRIPCION

#include "utils.hpp"
#include "../../dominio/header/Fabrica.hpp"
#include <iostream>
#include <string>

DTEmpleado* consultarEmpladoExiste(set<DTEmpleado*> empleados, string email);
void eliminarSuscripcion();

#endif