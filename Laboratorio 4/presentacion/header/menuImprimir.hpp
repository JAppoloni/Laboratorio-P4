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
 * @brief Imprime todas las reservas del sistema si codigo<0, sino solo la reserva con ese codigo
 * 
 * @param cod 
 */
void ImprimirReservas(int cod);

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
