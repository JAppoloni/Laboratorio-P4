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