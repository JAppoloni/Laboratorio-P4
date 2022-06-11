#include "header/utils.hpp"
#include<stdio.h>
#include <iostream>
#include <ostream>
#include <regex>
// #include "../Common/datatype/header/DTFecha.hpp"
// #include <chrono>
// #include <ctime>
// using namespace std;

// std::time_t t = std::time(0); // get time now
//       std::tm *now = std::localtime(&t);

// // Function to creating loading bar
// void loadingBar()
// {
//     // 0 - black background,
//     // A - Green Foreground
//     system("color 0A");

//     // Initialize char for printing
//     // loading bar
//     char a = 177, b = 219;

//     printf("\n\n\n\n");
//     printf("\n\n\n\n\t\t\t\t\t"
//            + "Loading...\n\n");
//     printf("\t\t\t\t\t");

//     // Print initial loading bar
//     for (int i = 0; i < 26; i++)
//         printf("%c", a);

//     // Set the cursor again starting
//     // point of loading bar
//     printf("\r");
//     printf("\t\t\t\t\t");

//     // Print loading bar progress
//     for (int i = 0; i < 26; i++) {
//         printf("%c", b);

//         // Sleep for 1 second
//         Sleep(1000);
//     }
// }

// // Driver Code
// int main()
// {
//     // Function Call
//     loadingBar();
//     return 0;
// }

DTFecha ingresarFecha()
{
   DTFecha rtn = DTFecha();
   int dia, mes, anio, hh, wday, min;
   string str_fecha;

   bool validInput = false;
   while (!validInput)
   {
      try
      {
         cin >> str_fecha;
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
         cout << "\n\n --------------";
         cout << "El fomrato debe ser : dd 1-31" << endl;
         cout << "\t\t   mm 0-11" << endl;
         cout << "\t\t   yyyy >1900" << endl;
         cout << "\t\t   hh 0-23" << endl;
         cout << "\t\t   min 0-59" << endl;
         cout << "\t\t   D 0-6 (L, M, X, J, V, S, D)" << endl;
         std::cerr << e.what() << '\n';
         cout << "--------------";

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

int leerInt()
{
   int num;
   bool valido = false;
   while (valido == false)
   {
      try
      {
         cin >> num;
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
         cin >> num;
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
         cin >> num;
         if (num < menor || num > mayor)
         {
            std::cout << "\n Ingrese un número entre " << menor << " y " << mayor << ": ";
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
         cin >> num;
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
         cin >> num;
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
         cin >> num;
         if (num < menor || num > mayor)
         {
            std::cout << "\n Ingrese un número entre " << menor << " y " << mayor << ": ";
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
