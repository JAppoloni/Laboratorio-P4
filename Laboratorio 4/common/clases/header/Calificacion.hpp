#ifndef _CALIFICACION_HH_
#define _CALIFICACION_HH_
#include "../../datatype/header/DTCalificacion.hpp"
class Calificacion {
private:
 int id;
 bool respond;
public:
 
 int obtenerID();
 bool estaRespondida();
 DTCalificacion getDatatype();
 std::string getComentario() const;

int getPuntaje() const;


};

#endif