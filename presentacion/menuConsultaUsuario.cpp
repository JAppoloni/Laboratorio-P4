#include "header/menuConsultaUsuario.hpp"

DTUsuario *consultarUsuarioExiste(list<DTUsuario *> usuarios, string email)
{
    for (list<DTUsuario *>::iterator itr = usuarios.begin(); itr != usuarios.end(); itr++)
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
    IControladorUsuario *controlador = Fabrica().getControladorUsuario();
    list<DTUsuario *> usuarios = controlador->listarUsuarios();

    if (!usuarios.empty())
    {
        int minElem = 1;
        int maxElem = 0;
        cout << "Listado de emails de usuarios del sistema: " << endl
             << endl;
        for (auto it : usuarios)
        {
            maxElem++;
            cout << GRN << maxElem << NC << ". " << it->getEmail() << endl;
        }

        cout << "Ingrese el numero del usuario ( " << RED << minElem << " - " << maxElem << NC << " ):";
        int eleccion = leerIntIntervalo(minElem, maxElem);

        for (auto it : usuarios)
        {
            if (minElem == eleccion)
            {
                cout << "Consulta de usuario: " << it->getNombre() << " - " << it->getEmail();

                DTEmpleado *empleado = dynamic_cast<DTEmpleado *>(it);
                if (empleado != nullptr)
                {
                    cout << " - " << cargoAString(empleado->getCargo()) << endl;
                }

                DTHuesped *huesped = dynamic_cast<DTHuesped *>(it);
                if (huesped != nullptr)
                {
                    cout << " - " << (huesped->getEsFinger() ? "Es FInger" : "No es FInger") << endl;
                }
            }
            minElem++;
            delete it;
            it = nullptr;
        }
        usuarios.clear();
    }
    else
    {
        cout << "No hay usuarios en el sistema. Presione enter para continuar.";
    }
    presioneParaContinuar();
}