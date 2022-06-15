#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string>
#include "../../common/datatype/header/DTFecha.hpp"


#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"


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

void printProgress(double percentage);

#endif
