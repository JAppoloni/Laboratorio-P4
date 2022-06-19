#include "header/menuModificarFechaSistema.hpp"

void modificarFechaSistema()
{
    cout << "Intrese una fecha (dd/mm/yyyy hh:mm D): ";
    DTFecha fecha = ingresarFecha();
    IFechaSistema * FS = Fabrica().getFechaSistema();
    FS->setFecha(fecha);
    cout << "Fecha del sistema modificada con exito" << endl;
    presioneParaContinuar();
}