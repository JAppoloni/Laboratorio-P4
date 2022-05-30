#include "../include/Usuario.hpp"

Usuario::Usuario(int idUser, std::string email, std::string contrasena){
    this->idUser = idUser;
    this->email = email;
    this->contrasena = contrasena;
}

std::string Usuario::getEmail(){
    return email;
}

std::string Usuario::getContrasena(){
    return contrasena;
}

int Usuario::getId() {
    return idUser;
}