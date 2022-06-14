#include "header/ControladorUsuario.hpp"

ControladorUsuario *ControladorUsuario::instancia = nullptr;

ControladorUsuario::ControladorUsuario() {}

ControladorUsuario *ControladorUsuario::getInstancia()
{
    ControladorUsuario *res = instancia;
    if (res == nullptr)
    {
        res = new ControladorUsuario();
    };
    return res;
}

DTUsuario *usuarioRecordado;

void ControladorUsuario::ingresarUsuario(DTUsuario *dataUsuario)
{
    usuarioRecordado = dataUsuario;
}

void ControladorUsuario::cancelarAlta()
{
    delete usuarioRecordado;
}

void ControladorUsuario::reingresarEmail(string email)
{
    if (dynamic_cast<DTEmpleado *>(usuarioRecordado) != nullptr)
    {
        DTEmpleado *aux = dynamic_cast<DTEmpleado *>(usuarioRecordado);
        usuarioRecordado = new DTEmpleado(aux->getNombre(), aux->getContrasenya(), email, aux->getCargo());
        delete aux;
    }
    else
    {
        DTHuesped *aux = dynamic_cast<DTHuesped *>(usuarioRecordado);
        usuarioRecordado = new DTHuesped(aux->getNombre(), aux->getContrasenya(), email, aux->getEsFinger());
        delete aux;
    };
}

void ControladorUsuario::confirmarAlta()
{
    if (dynamic_cast<DTEmpleado *>(usuarioRecordado) != nullptr){
        DTEmpleado * aux = dynamic_cast<DTEmpleado *>(usuarioRecordado);
        empleados[aux->getEmail()] = new Empleado(aux->getNombre(), aux->getEmail(), aux->getContrasenya(), aux->getCargo());
    } else{
        DTHuesped * aux = dynamic_cast<DTHuesped *>(usuarioRecordado);
        huespedes[aux->getEmail()] = new Huesped(aux->getNombre(), aux->getEmail(), aux->getContrasenya(), aux->getEsFinger());
    };
}

bool ControladorUsuario::esEmailUsuario()
{
    return empleados[usuarioRecordado->getEmail()] != nullptr || huespedes[usuarioRecordado->getEmail()] != nullptr;
}



void ControladorUsuario::seleccionarHostal(string nombre)
{
    nomHostalRecordado = nombre;
}

set<DTEmpleado *> ControladorUsuario::obtenerEmpleadosSinHsotal()
{
    set<DTEmpleado *> res;
    for (map<string, Empleado*>::iterator it = empleados.begin(); it != empleados.end(); ++it){
        if (it->second->getHostal() == nullptr){
            res.insert(new DTEmpleado(it->second->getNombre(), it->second->getContrasena(), it->second->getEmail(), it->second->getCargo()));
        };
    }; 
    return res;
}

string emailEmpRecordado;

void ControladorUsuario::seleccionarEmpleado(string email)
{
    emailEmpRecordado = email;
}

Cargo cargoRecordado;

void ControladorUsuario::seleccionarCargo(Cargo cargo)
{
    cargoRecordado = cargo;
} 

void ControladorUsuario::cancelarAsignacion(){}

void ControladorUsuario::confirmarAsignacionDeEmpleadoAHostal()
{
    ControladorHostal * CH = ControladorHostal::getInstancia();
    empleados[emailEmpRecordado]->setHostal(CH->getHostal(nomHostalRecordado));
    empleados[emailEmpRecordado]->setCargo(cargoRecordado);
}

set<DTHuesped*> ControladorUsuario::listarHuespedes()
{
    set<DTHuesped*> res;
    for(map<string, Huesped *>::iterator it = huespedes.begin(); it != huespedes.end(); ++it){
        res.insert(it->second->getDatatypeptr());
    };
    return res;
}

Huesped * ControladorUsuario::getHuesped(string correo)
{
    for(map<string, Huesped*>::iterator it = huespedes.begin(); it != huespedes.end(); ++it){
        if(it->second->getEmail() == correo){
            return it->second;
        };
    };
    return nullptr;
}