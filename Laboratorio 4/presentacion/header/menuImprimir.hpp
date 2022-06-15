#ifndef MENU_IMPRIMIR_H
#define MENU_IMPRIMIR_H
#include <stdlib.h>
#include <iostream>
#include "utils.hpp"
#include "../../dominio/header/Fabrica.hpp"


using namespace std;

/**
 * @brief Imprimer todos los hostales del sistema si nombre=="", sino solo el hostal con ese nombre
 * 
 * @param nombre 
 */
void ImprimirHostales(string nombre);

/**
 * @brief Imprimer todas las reservas del sistema si codigo<=0 y email == 0 imprime todoas, si el email es vacio imprime todas las del codifo, si el cod es vacio y el email no imprime todas las de ese email (No incluye reservas grupales)
 * 
 * @param codigo 
 * @param email 
 */
void ImprimirReservas(int cod,  string email);

/**
 * @brief Imprime todos los usuarios del sistema si email=="", sino solo el usuario con ese email
 * 
 * @param email 
 */
void ImprimirUsuario(string email);

/**
 * @brief Imprime todos los hostales del sistema
 * 
 */
void ImprimirEstadias();

#endif
