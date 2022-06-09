#include "header/Calificacion.hpp"
#include <iostream>
#include <string>

int Calificacion::obtenerID(){
return 1;
}

bool Calificacion::estaRespondida(){
     return true;
 }

 Calificacion::Calificacion(const Calificacion &copy)
{

}

Calificacion::Calificacion(int puntaje, std::string comentario, DTFecha fecha, Estadia *estadiaComentario)
{
	
}

//Calificacion::Calificacion(int puntaje, std::string comentario, DTFecha fecha, Estadia *estadiaComentario, Comentario *respuestaComentario)
//{
	
//}
