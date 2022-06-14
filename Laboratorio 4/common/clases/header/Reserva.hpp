#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>
#include <list>
#include "../../datatype/header/DTReserva.hpp"
#include "../../datatype/header/DTFecha.hpp"
#include "EstadoReserva.hpp"
#include "Habitacion.hpp"
#include "Huesped.hpp"
#include "Estadia.hpp"

class Habitacion;
class Estadia;
class Huesped;
class DTReserva;

class Reserva
{
public:
	// Constructors
	Reserva();

	// Destructor
	virtual ~Reserva();

	// Operators
	bool operator==(const Reserva &assign);

	// Getters / Setters
	int getCodigo() const;
	void setCodigo(int codigo);
	DTFecha getCheckIn() const;
	void setCheckIn(DTFecha CheckIn);
	DTFecha getCheckOut() const;
	void setCheckOut(DTFecha checkOut);
	Huesped *getHuespedReserva() const;
	void setHuespedReserva(Huesped *huespedReserva);
	EstadoReserva getEstado() const;
	void setEstado(EstadoReserva estado);
	Habitacion *getHabitacionReserva() const;
	void setHabitacionReserva(Habitacion *habitacionReserva);

	// Exceptions
	class NOEXISTEHUESPED : public std::exception
	{
		virtual const char *what() const throw();
	};

	class YAEXISTEESTADIA : public std::exception
	{
		virtual const char *what() const throw();
	};

	// Methods
	void cancelarReserva();

	virtual DTReserva* getDataReserva() = 0;
	virtual float calcularCosto() = 0;
	virtual void agregarEstadia(Estadia* estadia) = 0;
	virtual bool esReservaHostalHuesped(std::string email, std::string nombre) = 0;
	// virtual void darBaja(); // DEPENDE DEL TIPO DE RESERVA

protected:
	int _codigo;
	DTFecha _checkIn;
	DTFecha _checkOut;
	Huesped *_huespedReserva;
	EstadoReserva _estado;
	Habitacion *_habitacionReserva;
};
#endif
