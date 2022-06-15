#ifndef RESERVAINDIVIDUAL_HPP
#define RESERVAINDIVIDUAL_HPP

#include "Reserva.hpp"
#include "../../datatype/header/DTReservaIndividual.hpp"

class Huesped;
class Estadia;

class ReservaIndividual : public Reserva
{
public:
	// Constructors
	ReservaIndividual();
	ReservaIndividual(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, bool pago);
	

	// Destructor
	~ReservaIndividual();

	// Operators
	ReservaIndividual &operator=(const ReservaIndividual &assign);

	// Getters / Setters
	bool getPago() const;
	void setPago(bool pago);
	Estadia *getEstadiaReserva() const;

	// Methods
	void agregarEstadia(Estadia *estadia);
	bool esReservaHostalHuesped(std::string email, std::string nombre);
	DTReserva* getDataReserva();

private:
	bool _pago;
	Estadia *_estadiaReserva;
};

#endif