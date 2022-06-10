#ifndef RESERVAGRUPAL_HPP
#define RESERVAGRUPAL_HPP

#include "Reserva.hpp"

class Huesped;
class Estadia;

class ReservaGrupal : public Reserva
{
public:
	// Constructors
	ReservaGrupal();
	ReservaGrupal(const ReservaGrupal &copy);
	ReservaGrupal(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, std::list<Huesped *> listaHuesped);
	ReservaGrupal(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, std::list<Estadia *> listaEstadia, std::list<Huesped *> listaHuesped);

	// Destructor
	~ReservaGrupal();

	// Operators
	ReservaGrupal &operator=(const ReservaGrupal &assign);

	// Getters / Setters
	std::list<Estadia *> getListaEstadia() const;
	void setListaEstadia(std::list<Estadia *> listaEstadia);
	std::list<Huesped *> getListaHuesped() const;
	void setListaHuesped(std::list<Huesped *> listaHuesped);

	//Exception
	class YAEXISTEHUESPED : public std::exception
	{
		virtual const char *what() const throw();
	};

	// Methods
	float calcularCosto();
	void agregarEstadia(Estadia* estadia);
	bool esReservaHostalHuesped(std::string email, std::string nombre);
	void darBaja();

private:
	std::list<Estadia *> _listaEstadia;
	std::list<Huesped *> _listaHuesped;
};

#endif