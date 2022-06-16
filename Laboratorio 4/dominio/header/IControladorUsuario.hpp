#ifndef I_CONTROLADOR_USUARIO
#define I_CONTROLADOR_USUARIO

#include "../../common/clases/header/Usuario.hpp"
#include "../../common/clases/header/Empleado.hpp"
#include "../../common/clases/header/Huesped.hpp"
#include "../../common/datatype/header/DTUsuario.hpp"
#include <string>
#include <set>
#include <map>

using namespace std;

class IControladorUsuario
{
public:
    virtual void ingresarUsuario(DTUsuario *dataUsuario) = 0;  // alta usuario
    virtual bool confirmarEmailDisponible() = 0;               // alta usuario
    virtual void cancelarAlta() = 0;                           // alta usuario
    virtual bool esEmailUsuario() = 0;                         // email del DTUsuario recordado en el caso de uso alta usuario; alta usuario
    virtual void reingresarEmail(string email) = 0;            // alta usuario
    virtual void confirmarAlta() = 0;                          // alta usuario
    virtual void seleccionarHostal(string nombre) = 0;         // asignar empleado a hostal
    virtual set<DTEmpleado *> obtenerEmpleadosSinHsotal() = 0; // asignar empleado a hostal
    virtual void seleccionarEmpleado(string email) = 0;        // asignar empleado a hostal
    virtual void seleccionarCargo(Cargo cargo) = 0;            // aignar empleado a hostal
    virtual void cancelarAsignacion() = 0;                     // asignar empleado a hostal
    virtual void confirmarAsignacionDeEmpleadoAHostal() = 0;   // asignar empleado a hostal
    virtual set<DTHuesped *> listarHuespedes() = 0;            // realizar reserva
    virtual Huesped *getHuesped(string email) = 0;

    // para pruebas
    virtual set<DTUsuario *> obtenerTodosLosUsuariosDelSistema() = 0;

    // para eliminar datos
    virtual void liberarRegistros() = 0;
};

#endif