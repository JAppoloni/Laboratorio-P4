#include "header/utils.hpp"
#include <stdio.h>
#include <iostream>
#include <ostream>
#include <regex>

bool confirmarBaja()
{
   string confirmacion;
   bool seleccionCorrecta = false;
   while (!seleccionCorrecta)
   {
      cout << "Desea confirmar la baja? (S/N)" << endl;
      cin >> confirmacion;

      if (confirmacion != "S" && confirmacion != "s" && confirmacion != "N" && confirmacion != "n")
      {
         cout << "Seleccione una de las opciones disponibles." << endl;
      }
      else
      {
         seleccionCorrecta = true;
      }
   }

   if (confirmacion == "S" || confirmacion == "s")
   {
     return true;
   }
   else
   {
     return false;
   }
}

DTFecha ingresarFecha()
{
   DTFecha rtn;
   int dia, mes, anio, hh, wday, min;
   string str_fecha;

   bool validInput = false;
   while (!validInput)
   {
      try
      {
         str_fecha = leerString();
         dia = stoi(str_fecha.substr(0, 2));
         mes = stoi(str_fecha.substr(3, 2));
         anio = stoi(str_fecha.substr(6, 4));
         hh = stoi(str_fecha.substr(11, 2));
         min = stoi(str_fecha.substr(14, 2));
         wday = stoi(str_fecha.substr(17));

         rtn = DTFecha(min, hh, dia, mes, anio, wday);
         validInput = true;
      }
      catch (const std::exception &e)
      {
         cout << RED "\n\n --------------" << endl;
         cout << "El fomrato debe ser : dd 1-31" << endl;
         cout << "\t\t   mm 00-11" << endl;
         cout << "\t\t   yyyy >1900" << endl;
         cout << "\t\t   hh 00-23" << endl;
         cout << "\t\t   min 00-59" << endl;
         cout << "\t\t   D 0-6 (L, M, X, J, V, S, D)" << endl;
         std::cerr << "El error es el siguiente:  " << e.what() << '\n';
         cout << "--------------" NC << endl;

         cout << "Intrese una fecha (dd/mm/yyyy hh:mm D): ";
      }
   }
   return rtn;
}

bool Email_check(string email)
{
   const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return regex_match(email, pattern);
}

string leerEmail()
{
   bool valido = false;
   string cadena;
   while (valido == false)
   {
      getline(cin, cadena);
      if (Email_check(cadena))
         valido = true;
      else
         cout << "\n Ingrese un Email correcto: " << endl;
   }
   return cadena;
}

string leerString()
{
   bool valido = false;
   string cadena;
   while (valido == false)
   {
      getline(cin, cadena);

      if (cadena.length() > 0)
         valido = true;
      else
         cout << "\n El valor ingresado no es correcto. Ingreselo nuevamente: ";
   }
   return cadena;
}

string cargoAString(Cargo cargo) 
{
   if (cargo == administracion) 
   {
      return "Administracion";
   }
   else if (cargo == limpieza)
   {
      return "Limpieza";
   }
   else if (cargo == recepcion)
   {
      return "Recepcion";
   }
   else if (cargo == infraestructura)
   {
      return "Infraestructura";
   }

   return "<VACIO>";
}

int leerInt()
{
   int num;
   bool valido = false;
   while (valido == false)
   {
      try
      {
         string aux;
         getline(cin, aux);
         num = stoi(aux);
         valido = true;
      }
      catch (const std::exception &e)
      {
         std::cout << "\n Ingrese un número correcto: ";
      }
   }
   return num;
}

int leerIntPositivo()
{
   int num;
   bool valido = false;
   while (valido == false)
   {
      try
      {
         string aux;
         getline(cin, aux);
         num = stoi(aux);
         if (num < 0)
         {
            std::cout << "\n Ingrese un número positivo: ";
         }
         else
         {
            valido = true;
         }
      }
      catch (const std::exception &e)
      {
         std::cout << "\n Ingrese un número correcto: ";
      }
   }
   return num;
}

int leerIntIntervalo(int menor, int mayor)
{
   int num;
   bool valido = false;
   while (valido == false)
   {
      try
      {
         string aux;
         getline(cin, aux);
         num = stoi(aux);
         if (num < menor || num > mayor)
         {
            std::cout << "\n Ingrese un número entre " << RED << menor << NC << " y " << RED << mayor << NC << ": ";
         }
         else
         {
            valido = true;
         }
      }
      catch (const std::exception &e)
      {
         std::cout << "\n Ingrese un número correcto: ";
      }
   }
   return num;
}

float leerFloat()
{
   float num;
   bool valido = false;
   while (valido == false)
   {
      try
      {
         string aux;
         getline(cin, aux);
         num = stoi(aux);
         valido = true;
      }
      catch (const std::exception &e)
      {
         std::cout << "\n Ingrese un número correcto: ";
      }
   }
   return num;
}

float leerFloatPositivo()
{
   float num;
   bool valido = false;
   while (valido == false)
   {
      try
      {
         string aux;
         getline(cin, aux);
         num = stoi(aux);
         if (num < 0)
         {
            std::cout << "\n Ingrese un número positivo: ";
         }
         else
         {
            valido = true;
         }
      }
      catch (const std::exception &e)
      {
         std::cout << "\n Ingrese un número correcto: ";
      }
   }
   return num;
}

float leerFloatIntervalo(float menor, float mayor)
{
   float num;
   bool valido = false;
   while (valido == false)
   {
      try
      {
         string aux;
         getline(cin, aux);
         num = stoi(aux);
         if (num < menor || num > mayor)
         {
            std::cout << "\n Ingrese un número entre " << RED << menor << NC << " y " << RED << mayor << NC << ": ";
         }
         else
         {
            valido = true;
         }
      }
      catch (const std::exception &e)
      {

         std::cout << "\n Ingrese un número correcto: ";
      }
   }
   return num;
}

void limpiar()
{
   system("clear");
}

void presioneParaContinuar()
{
   cout << "Presione enter para continuar..." << endl;
   cin.ignore(1000, '\n');
}

void printProgress(double percentage)
{
   cout << GRN;
   int val = (int)(percentage * 100);
   int lpad = (int)(percentage * PBWIDTH);
   int rpad = PBWIDTH - lpad;
   printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
   fflush(stdout);
   cout << NC;
}

bool buscarNombreDeHostal(list<DTHostal*> hostales, string nombre)
{
    for (list<DTHostal *>::iterator itr = hostales.begin(); itr != hostales.end(); itr++) 
    {
        if ((*itr)->getNombre() == nombre)
        {
            return true;
        }
    }

    return false;
}
