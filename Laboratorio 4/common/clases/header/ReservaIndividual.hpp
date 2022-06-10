#ifndef RESERVAINDIVIDUAL_HPP
#define RESERVAINDIVIDUAL_HPP

#include "Reserva.hpp"
class Huesped;
class Estadia;

class ReservaIndividual : public Reserva
{
public:
	// Constructors
	ReservaIndividual();
	ReservaIndividual(const ReservaIndividual &copy);
	ReservaIndividual(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, bool pago);
	ReservaIndividual(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, bool pago, Estadia *estadiaReserva);

	// Destructor
	~ReservaIndividual();

	// Operators
	ReservaIndividual &operator=(const ReservaIndividual &assign);

	// Getters / Setters
	bool getPago() const;
	void setPago(bool pago);
	Estadia *getEstadiaReserva() const;

	// Methods
	float calcularCosto();
	void agregarEstadia(Estadia* estadia);
	bool esReservaHostalHuesped(std::string email, std::string nombre);
	void darBaja();

private:
	bool _pago;
	Estadia *_estadiaReserva;
};

#endif