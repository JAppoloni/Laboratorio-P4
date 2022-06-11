#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string>
#include "../../Common/datatype/header/DTFecha.hpp"
using namespace std;

DTFecha ingresarFecha();

bool Email_check(string email);

string leerEmail();

string leerString();

int leerInt();

int leerIntPositivo();


int leerIntIntervalo(int menor, int mayor);

float leerFloat();

float leerFloatPositivo();

float leerFloatIntervalo(float menor, float mayor);

void limpiar();

void presioneParaContinuar();

#endif
