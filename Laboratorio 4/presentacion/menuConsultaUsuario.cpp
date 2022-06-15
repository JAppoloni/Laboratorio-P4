#include "header/menuConsultaUsuario.hpp"

DTUsuario* consultarUsuarioExiste(list<DTUsuario*> usuarios, string email) 
{
    for (list<DTUsuario*>::iterator itr = usuarios.begin(); itr != usuarios.end(); itr++) 
    {
        if ((*itr)->getEmail() == email)
        {
            return (*itr);
        }
    }

    return nullptr;
}

void menuConsultaUsuario()
{
    IControladorUsuario* controlador = Fabrica().getControladorUsuario();
    list<DTUsuario*> usuarios = controlador->obtenerTodosLosUsuariosDelSistema();

    system("clear");
    cout << "Listado de emails de usuarios del sistema: " << endl << endl;

    for (list<DTUsuario*>::iterator itr = usuarios.begin(); itr != usuarios.end(); itr++) 
    {
        cout << (*itr)->getEmail() << endl; // Aparentemente algunos usuarios tienen espacios al principio del mail
    }

    
    DTUsuario* usuarioSeleccionado;
    bool seleccionCorrecta = false;
    while (!seleccionCorrecta) 
    {
        string emailIngresado;
        cout << endl << "Seleccione uno de los emails para consultar un usuario" << endl;
        cin >> emailIngresado;

        usuarioSeleccionado = consultarUsuarioExiste(usuarios, emailIngresado);
        if (usuarioSeleccionado != nullptr) 
        {
            seleccionCorrecta = true;
        }
        else
        {
            cout << "El email ingresado no corresponde a un usuario del sistema." << endl;
        }
    }

    cout << "Consulta de usuario: " << usuarioSeleccionado->getNombre() << " - " << usuarioSeleccionado->getEmail();

    DTEmpleado* empleado = dynamic_cast<DTEmpleado*>(usuarioSeleccionado);
    if (empleado != nullptr) {
        cout << " - " << cargoAString(empleado->getCargo()) << endl;
    }

    DTHuesped* huesped = dynamic_cast<DTHuesped*>(usuarioSeleccionado);
    if (huesped != nullptr) {
        cout << " - " << (huesped->getEsFinger() ? "Es FInger" : "No es FInger") << endl;
    }

    cout << endl << "Presione enter para continuar." << endl;
    cin.ignore();
    cin.ignore(1000, '\n');
}