#include "header/ReservaGrupal.hpp"
#include "../datatype/header/DTHuesped.hpp"
#include "../datatype/header/DTHabitacion.hpp"

// Constructors
ReservaGrupal::ReservaGrupal() {}

ReservaGrupal::ReservaGrupal(int codigo, DTFecha CheckIn, DTFecha checkOut, Huesped *huespedReserva, EstadoReserva estado, Habitacion *habitacionReserva, std::list<Huesped *> listaHuesped)
{
	_codigo = codigo;
	_checkIn = CheckIn;
	_checkOut = checkOut;
	_huespedReserva = huespedReserva;
	_estado = estado;
	_habitacionReserva = habitacionReserva;
	_listaHuesped = listaHuesped;
}

// Destructor
ReservaGrupal::~ReservaGrupal()
{
	_huespedReserva = nullptr;
	_habitacionReserva = nullptr;
	_listaEstadia.clear();
	_listaHuesped.clear();
}

// Getters / Setters
std::list<Estadia *> ReservaGrupal::getListaEstadia() const
{
	return _listaEstadia;
}

void ReservaGrupal::setListaEstadia(std::list<Estadia *> listaEstadia)
{
	_listaEstadia = listaEstadia;
}

std::list<Huesped *> ReservaGrupal::getListaHuesped() const
{
	return _listaHuesped;
}
void ReservaGrupal::setListaHuesped(std::list<Huesped *> listaHuesped)
{
	_listaHuesped = listaHuesped;
}

// Exception
const char *ReservaGrupal::YAEXISTEHUESPED::what() const throw()
{
	return "Este huesped ya ha sido asignado.";
}

// Methods

void ReservaGrupal::agregarEstadia(Estadia *estadia)
{
	Huesped *huesped = estadia->getHuespedEstadia();

	if (_listaEstadia.size() != 0)
	{
		for (auto it : _listaEstadia)
		{
			if (it->getHuespedEstadia() == huesped)
			{
				throw YAEXISTEHUESPED();
				break;
			}
		}
	}

	if (this->_huespedReserva != huesped)
	{
		bool existeHuesped = false;

		for (auto it : _listaHuesped)
		{
			if (it == huesped)
			{
				existeHuesped = true;
				break;
			}
		}

		if (!existeHuesped)
			throw NOEXISTEHUESPED();
	}
	_listaEstadia.push_back(estadia);
	// _listaEstadia.push_back(estadia);
}

bool ReservaGrupal::esReservaHostalHuesped(std::string email, std::string nombreHostal)
{
	if (_habitacionReserva->getHostal()->getNombre() == nombreHostal)
	{
		if (_huespedReserva->getEmail() == email)
		{
			return true;
		};
		for (auto it : _listaHuesped)
		{
			if (it->getEmail() == email)
			{
				return true;
			};
		};
	};
	return false;
}

DTReserva *ReservaGrupal::getDataReserva()
{
	std::list<DTHuesped> *listaHuespedes = new std::list<DTHuesped>;
	for (auto it : _listaHuesped)
	{
		listaHuespedes->push_back(it->getDatatype());
	}

	return new DTReservaGrupal(_codigo,
										_checkIn,
										_checkOut,
										_estado,
										this->calcularCosto(),
										new DTHabitacion(_habitacionReserva->getNumero(), _habitacionReserva->getPrecio(), _habitacionReserva->getCapacidad()),
										_huespedReserva->getDatatypeptr(),
										listaHuespedes);
}
