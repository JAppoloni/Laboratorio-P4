#include "header/ControladorUsuario.hpp"

ControladorUsuario *ControladorUsuario::instancia = nullptr;

ControladorUsuario::ControladorUsuario()
{
    nomHostalRecordado = "";
}

ControladorUsuario *ControladorUsuario::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new ControladorUsuario();
    }
    return instancia;
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
    for (map<string, Empleado *>::iterator it = empleados.begin(); it != empleados.end(); ++it)
    {
        if (it->second->getHostal() == nullptr)
        {
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

void ControladorUsuario::cancelarAsignacion() {}

void ControladorUsuario::confirmarAsignacionDeEmpleadoAHostal()
{
    ControladorHostal *CH = ControladorHostal::getInstancia();
    if (empleados[emailEmpRecordado] == nullptr)
        throw invalid_argument("El empleado no existe");

    empleados[emailEmpRecordado]->setHostal(CH->getHostal(nomHostalRecordado));
    empleados[emailEmpRecordado]->setCargo(cargoRecordado);
}

set<DTHuesped *> ControladorUsuario::listarHuespedes()
{
    set<DTHuesped *> res;
    for (map<string, Huesped *>::iterator it = huespedes.begin(); it != huespedes.end(); ++it)
    {
        res.insert(it->second->getDatatypeptr());
    };
    return res;
}

Huesped *ControladorUsuario::getHuesped(string correo)
{
    for (map<string, Huesped *>::iterator it = huespedes.begin(); it != huespedes.end(); ++it)
    {
        if (it->second->getEmail() == correo)
        {
            return it->second;
        };
    };
    return nullptr;
}

set<DTUsuario *> ControladorUsuario::obtenerTodosLosUsuariosDelSistema()
{
    set<DTUsuario *> res;
    for (map<string, Huesped *>::iterator it = huespedes.begin(); it != huespedes.end(); ++it)
    {
        res.insert(it->second->getDatatypeptr());
    };
    for (map<string, Empleado *>::iterator it = empleados.begin(); it != empleados.end(); ++it)
    {
        res.insert(new DTEmpleado(it->second->getNombre(), it->second->getContrasena(), it->second->getEmail(), it->second->getCargo()));
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

    if (instancia != nullptr)
    {
        instancia = nullptr;
    }
}
set<DTCalificacion *> ControladorUsuario::obtenerComentariosSinResponderEmpleado(string EmailEMPLEADO)
{
    emailEmpRecordado = EmailEMPLEADO;
    for (map<string, Empleado *>::iterator it = empleados.begin(); it != empleados.end(); ++it)
    {
        if (it->second->getEmail() == EmailEMPLEADO)
        {
            return it->second->getHostal()->obtenerComentariosSinResponder();
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