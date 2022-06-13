
#ifndef MENUCARGARDATOS_MENU_H
#define MENUCARGARDATOS_MENU_H

#include <iostream>
#include <stdlib.h>
#include "utils.hpp"
#include "../../common/clases/header/Cargo.hpp"
#include "../../common/clases/header/EstadoReserva.hpp"
#include "../../common/datatype/header/DTEmpleado.hpp"
#include "../../common/datatype/header/DTHuesped.hpp"
#include "../../common/datatype/header/DTHostal.hpp"
#include "../../common/datatype/header/DTHabitacion.hpp"
#include "../../dominio/header/Fabrica.hpp"
#include "../../dominio/header/IControladorEstadia.hpp"
#include "../../dominio/header/IControladorHostal.hpp"
#include "../../dominio/header/IControladorReserva.hpp"
#include "../../dominio/header/IControladorUsuario.hpp"
#include "../../dominio/header/FechaSistema.hpp"

using namespace std;


void cargarDatos(bool primeraVez);

#endif
