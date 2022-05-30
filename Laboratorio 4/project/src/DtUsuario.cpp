#include "../include/DtUsuario.hpp"

DtUsuario::DtUsuario(std::string email, std::string password) {
    this->email = email;
    this->password = password;
}

std::string DtUsuario::getEmail() {
    return email;
}

std::string DtUsuario::getPassword() {
    return password;
}