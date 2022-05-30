#include "../include/DtDesarrollador.hpp"

DtDesarrollador::DtDesarrollador(std::string email,
                                 std::string password,
                                 std::string empresa)
    : DtUsuario(email, password) {
    this->empresa = empresa;
}

std::string DtDesarrollador::getEmpresa() {
    return empresa;
}