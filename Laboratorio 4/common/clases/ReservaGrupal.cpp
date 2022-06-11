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
	// if (_listaEstadia == NULL)
	// 	return 0;
	// else
	// {
	// 	return 1;
	// }
	return 0;
}

void ReservaGrupal::agregarEstadia(Estadia *estadia)
{
	Huesped *huesped = estadia->getHuespedEstadia();

	// iter _listaEstadia

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

	bool existeHuesped = false;

	// La lista de Huespedes no tener nombres repetidos y debe tener al menos dos elementos
	for (std::list<Huesped *>::iterator it = _listaHuesped.begin(); it != _listaHuesped.end(); ++it)
	{
		if ((*it) == huesped)
		{
			existeHuesped = true;
			break;
		}
	}
	if (existeHuesped == false)
		throw NOEXISTEHUESPED();
	else
		_listaEstadia.push_back(estadia);
}

bool ReservaGrupal::esReservaHostalHuesped(std::string email, std::string nombre)
{ // iterar si esta en la lista
	return _huespedReserva->getNombre() == nombre && _huespedReserva->getEmail() == email;
}

DTReserva* ReservaGrupal::getDataReserva()
{
	std::list<DTHuesped> listaHuespedes;
	for (std::list<Huesped *>::iterator it = _listaHuesped.begin(); it != _listaHuesped.end(); ++it)
	{
		listaHuespedes.push_back((*it)->getDatatype());
	}

	return new DTReservaGrupal(_codigo,
								  _checkIn,
								  _checkOut,
								  _estado,
								  calcularCosto(),
								  DTHabitacion(_habitacionReserva->getNumero(), _habitacionReserva->getPrecio(), _habitacionReserva->getCapacidad()),
								  _huespedReserva->getDatatype(),
								  listaHuespedes);
}
