#include "header/ControladorUsuario.hpp"

/*
 * Variables de instancia
 */

string _nombreRecordado_Hostal_IUsuario;
ControladorUsuario *ControladorUsuario::instancia = nullptr;
DTUsuario *usuarioRecordado;

/*
 * Fin de variables de instancia
 */

ControladorUsuario::ControladorUsuario()
{
}

ControladorUsuario *ControladorUsuario::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new ControladorUsuario();
    }
    return instancia;
}

void ControladorUsuario::ingresarUsuario(DTUsuario *dataUsuario)
{
    if (dynamic_cast<DTEmpleado *>(dataUsuario) != nullptr)
    {
        DTEmpleado *aux = dynamic_cast<DTEmpleado *>(dataUsuario);
        usuarioRecordado = new DTEmpleado(dataUsuario->getNombre(), dataUsuario->getContrasenya(), dataUsuario->getEmail(), aux->getCargo());
    }
    else
    {
        DTHuesped *aux = dynamic_cast<DTHuesped *>(dataUsuario);
        usuarioRecordado = new DTHuesped(dataUsuario->getNombre(), dataUsuario->getContrasenya(), dataUsuario->getEmail(), aux->getEsFinger());
    }
}

void ControladorUsuario::cancelarAlta()
{
    if (usuarioRecordado != nullptr)
    {
        delete usuarioRecordado;
        usuarioRecordado = nullptr;
    }
}

bool ControladorUsuario::confirmarEmailDisponible()
{
    if (usuarioRecordado == nullptr)
    {
        return false;
    }

    string email = usuarioRecordado->getEmail();

    if (dynamic_cast<DTEmpleado *>(usuarioRecordado) != nullptr)
    {
        return empleados.find(email) == empleados.end();
    }
    else
    {
        return huespedes.find(email) == huespedes.end();
    }
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
    }
}

void ControladorUsuario::confirmarAlta()
{
    if (dynamic_cast<DTEmpleado *>(usuarioRecordado) != nullptr)
    {
        DTEmpleado *aux = dynamic_cast<DTEmpleado *>(usuarioRecordado);
        empleados[aux->getEmail()] = new Empleado(aux->getNombre(), aux->getEmail(), aux->getContrasenya(), aux->getCargo());
    }
    else
    {
        DTHuesped *aux = dynamic_cast<DTHuesped *>(usuarioRecordado);
        huespedes[aux->getEmail()] = new Huesped(aux->getNombre(), aux->getEmail(), aux->getContrasenya(), aux->getEsFinger());
    }
    cancelarAlta();
}

bool ControladorUsuario::esEmailUsuario()
{
    return empleados[usuarioRecordado->getEmail()] != nullptr || huespedes[usuarioRecordado->getEmail()] != nullptr;
}

void ControladorUsuario::seleccionarHostal(string nombre)
{
    _nombreRecordado_Hostal_IUsuario = nombre;
}

set<DTEmpleado *> ControladorUsuario::obtenerEmpleadosSinHsotal()
{
    set<DTEmpleado *> res;
    for (auto it : empleados)
    {
        if (it.second->getHostal() == nullptr)
        {
            res.insert(new DTEmpleado(it.second->getNombre(), it.second->getContrasena(), it.second->getEmail(), it.second->getCargo()));
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

void ControladorUsuario::cancelarAsignacion() {}

void ControladorUsuario::confirmarAsignacionDeEmpleadoAHostal()
{
    ControladorHostal *CH = ControladorHostal::getInstancia();
    if (empleados[emailEmpRecordado] == nullptr)
        throw invalid_argument("El empleado no existe");

    empleados[emailEmpRecordado]->setHostal(CH->getHostal(_nombreRecordado_Hostal_IUsuario));
    empleados[emailEmpRecordado]->setCargo(cargoRecordado);
}

set<DTHuesped *> ControladorUsuario::listarHuespedes()
{
    set<DTHuesped *> res;
    for (auto it : huespedes)
    {
        res.insert(it.second->getDatatypeptr());
    };
    return res;
}

Huesped *ControladorUsuario::getHuesped(string correo)
{
    for (auto it : huespedes)
    {
        if (it.second->getEmail() == correo)
        {
            return it.second;
        };
    };
    return nullptr;
}

set<DTUsuario *> ControladorUsuario::obtenerTodosLosUsuariosDelSistema()
{
    set<DTUsuario *> res;
    for (auto it : huespedes)
    {
        res.insert(it.second->getDatatypeptr());
    };
    for (auto it : empleados)
    {
        res.insert(new DTEmpleado(it.second->getNombre(), it.second->getContrasena(), it.second->getEmail(), it.second->getCargo()));
    };
    return res;
}

void ControladorUsuario::liberarRegistros()
{
    

    for (auto it : huespedes)
    {
        if (it.second != nullptr)
        {
            delete it.second;
            it.second = nullptr;
        }
    }
    huespedes.clear();

    for (auto it : empleados)
    {
        if (it.second != nullptr)
        {
            delete it.second;
            it.second = nullptr;
        }
    }
    empleados.clear();
}
set<DTCalificacion *> ControladorUsuario::obtenerComentariosSinResponderEmpleado(string EmailEMPLEADO)
{
    emailEmpRecordado = EmailEMPLEADO;
    for (auto it : empleados)
    {
        if (it.second->getEmail() == EmailEMPLEADO)
        {
            return it.second->getHostal()->obtenerComentariosSinResponder();
        };
    };
    set<DTCalificacion *> vacio;
    return vacio;
}

void ControladorUsuario::responderCalificacion(int codigo, string emailHuesped, string comentario)
{
    ControladorEstadia *CE = ControladorEstadia::getInstancia();
    Empleado *emp = empleados[emailEmpRecordado];

    if (emp == nullptr)
    {
        emp = nullptr;
        throw invalid_argument("El empleado no existe");
    }
    else
    {
        Calificacion *auxCalif = CE->obtenerCalificacion(codigo, emailHuesped);
        if (auxCalif == nullptr)
        {
            emp = nullptr;
            throw invalid_argument("La calificación no existe");
        }
        else
        {
            emp->agregarComentario(comentario, auxCalif);
            emp = nullptr;
        }
    }
}

void ControladorUsuario::suscribirseNotificacion(string email)
{
    Empleado *e = empleados.find(email)->second;
    ControladorEstadia *CE = CE->getInstancia();
    CE->agregar(e);
}

void ControladorUsuario::eliminarSuscripcion(string email)
{
    Empleado *e = empleados.find(email)->second;
    ControladorEstadia *CE = CE->getInstancia();
    CE->eliminar(e);
}

set<DTCalificacion *> ControladorUsuario::listarNotificacionesEmpleado(string email)
{
    set<DTCalificacion *> res;
    Empleado *e = empleados.find(email)->second;

    for (auto it : e->getNotificaciones())
    {
        res.insert(new DTCalificacion(it->obtenerID(), it->getEstadiaComentario()->getHuespedEstadia()->getEmail(), it->getPuntaje(), it->getFecha(), it->getComentario()));
    }
    e->eliminarNotificaciones();
    return res;
}

// listar usuarios
list<DTUsuario *> ControladorUsuario::listarUsuarios()
{
    list<DTUsuario *> res;
    for (auto it : huespedes)
    {
        res.push_back(it.second->getDatatypeptr());
    };
    for (auto it : empleados)
    {
        res.push_back(it.second->getDatatypeptr());
    };
    return res;
}

DTUsuario *ControladorUsuario::seleccionarUsuario(string email)
{
    if (empleados[email] != nullptr)
    {
        return empleados[email]->getDatatypeptr();
    }
    else if (huespedes[email])
    {
        return huespedes[email]->getDatatypeptr();
    }
    else
    {
        throw std::invalid_argument("no hay usuarios con ese email");
    }
}

void ControladorUsuario::eliminarNotificacion(Calificacion *calif)
{
    for (auto it : empleados)
    {
        it.second->eliminarNotificacion(calif);
    }
}

void ControladorUsuario::eliminarComentarioEmpleado(Comentario *com)
{
    for (auto it : empleados)
    {
        it.second->eliminarComentario(com);
    }
}

set<DTEmpleado *> ControladorUsuario::listarEmpleados()
{
    set<DTEmpleado *> res;
    if (!empleados.empty())
    {
        for (auto it : empleados)
        {
            res.insert(new DTEmpleado(it.second->getNombre(), it.second->getContrasena(), it.second->getEmail(), it.second->getCargo()));
        }
    }
    return res;
}