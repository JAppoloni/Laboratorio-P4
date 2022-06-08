#ifndef ESTADIA_HPP
#define ESTADIA_HPP

#include <iostream>
#include <string>
#include "../../datatype/header/DTFecha.hpp"
#include "../../datatype/header/DTCalificacion.hpp"
#include "Huesped.hpp"
#include "Reserva.hpp"
#include "ReservaGrupal.hpp"
#include "ReservaIndividual.hpp"
#include "Calificacion.hpp"
#include "EstadoReserva.hpp"

 class Calificacion;
 class Reserva;
 class Huesped;

class Estadia
{
	public:
		// Constructors
		Estadia(const Estadia &copy);
		Estadia(DTFecha checkIn, std::string promo, Reserva* reservaEstadia, Huesped* huespedEstadia);
		Estadia(DTFecha checkIn, DTFecha* chechOut, std::string promo, Reserva* reservaEstadia, Huesped* huespedEstadia, Calificacion* calificacionEstadia);
		
		// Destructor
		~Estadia();
		
		// Operators
		Estadia & operator=(const Estadia &assign);
		bool operator==(const Estadia & assign);

		
		// Getters / Setters
		DTFecha getCheckIn() const;
		void setCheckIn(DTFecha checkIn);
		DTFecha* getChechOut() const;
		void setChechOut(DTFecha* chechOut);
		std::string getPromo() const;
		void setPromo(std::string promo);
		Reserva* getReservaEstadia() const;
		void setReservaEstadia(Reserva* reservaEstadia);
		Huesped* getHuespedEstadia() const;
		void setHuespedEstadia(Huesped* huespedEstadia);
		Calificacion* getCalificacionEstadia() const;
		void setCalificacionEstadia(Calificacion* calificacionEstadia);
		
		// Exceptions
		class FechaCheckInMenor : public std::exception {
			virtual const char* what() const throw();
		};
		class HuesedNoExiste : public std::exception {
			virtual const char* what() const throw();
		};
		class CalificacionNoExiste : public std::exception {
			virtual const char* what() const throw();
		};

		// Methods
		DTCalificacion getCalificacionDataType();
		bool esEstadiaCalificaicon(std::string email, int codigo);
		bool getFinalizacion();
		std::string obtenerAutor();
		void notificarEstadia();
		void desvincular();
		int obtenerID();


		
	private:
		DTFecha _checkIn;
		DTFecha* _chechOut; // Puede ser NULL, es decir no ha terminado la estadía.
		std::string _promo;
		Reserva* _reservaEstadia;
		Huesped* _huespedEstadia;
		Calificacion* _calificacionEstadia;

		void ValidarEstadia(DTFecha checkIn , Reserva* reservaEstadia,Huesped* huesped);
		
};

#endif