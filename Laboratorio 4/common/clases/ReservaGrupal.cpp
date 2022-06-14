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
	delete _huespedReserva;
	delete _habitacionReserva;

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
float ReservaGrupal::calcularCosto() // VER.
{
	return _checkIn.diferenciaDias(_checkOut) * _habitacionReserva->getPrecio();
}

void ReservaGrupal::agregarEstadia(Estadia *estadia)
{
	Huesped *huesped = estadia->getHuespedEstadia();

	if (_listaEstadia.begin() == _listaEstadia.end() && _listaEstadia.empty() != true && huesped == (*_listaEstadia.end())->getHuespedEstadia())
		throw YAEXISTEHUESPED();
	else
	{
		for (std::list<Estadia *>::iterator it = _listaEstadia.begin(); it != _listaEstadia.end(); ++it)
		{
			if ((*it)->getHuespedEstadia() == huesped)
			{
				throw YAEXISTEHUESPED();
				break;
			}
		}
	}

	if (this->_huespedReserva != huesped)
	{
		bool existeHuesped = false;

		if (_listaHuesped.begin() == _listaHuesped.end() && huesped == *_listaHuesped.end())
			throw YAEXISTEHUESPED();
		else
		{
			for (std::list<Huesped *>::iterator it = _listaHuesped.begin(); it != _listaHuesped.end(); ++it)
			{
				if ((*it) == huesped)
				{
					existeHuesped = true;
					break;
				}
			}
		}
		if (existeHuesped == false)
			throw NOEXISTEHUESPED();
	}
	_listaEstadia.push_back(estadia);
	// _listaEstadia.push_back(estadia);
}

bool ReservaGrupal::esReservaHostalHuesped(std::string email, std::string nombre)
{
	if (_habitacionReserva->getHostal()->getNombre() == nombre)
	{
		if (_huespedReserva->getEmail() == email)
		{
			return true;
		};
		for (std::list<Huesped *>::iterator it = _listaHuesped.begin(); it != _listaHuesped.end(); ++it)
		{
			if ((*it)->getEmail() == email)
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
	for (std::list<Huesped *>::iterator it = _listaHuesped.begin(); it != _listaHuesped.end(); ++it)
	{
		listaHuespedes->push_back((*it)->getDatatype());
	}

	return new DTReservaGrupal(_codigo,
										_checkIn,
										_checkOut,
										_estado,
										calcularCosto(),
										new DTHabitacion(_habitacionReserva->getNumero(), _habitacionReserva->getPrecio(), _habitacionReserva->getCapacidad()),
										_huespedReserva->getDatatypeptr(),
										listaHuespedes);
}
