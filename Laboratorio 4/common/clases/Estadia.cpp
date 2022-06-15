#include "header/Estadia.hpp"
#include "header/ReservaIndividual.hpp"
#include "header/ReservaGrupal.hpp"

void Estadia::ValidarEstadia(DTFecha checkIn, Reserva *reservaEstadia, Huesped *huesped)
{
	if (checkIn >= reservaEstadia->getCheckIn())
	{
		if (dynamic_cast<ReservaGrupal *>(reservaEstadia))
		{
			bool existe = false;
			ReservaGrupal *reserva = dynamic_cast<ReservaGrupal *>(reservaEstadia);

			if ((reserva->getHuespedReserva() == huesped) || (*reserva->getListaHuesped().end()) == huesped || (*reserva->getListaHuesped().begin() == huesped))
				existe = true;

			if (existe == false)
			{
				int tope = 0;
				int lstElem = reserva->getListaHuesped().size();
				for (std::list<Huesped *>::iterator it = reserva->getListaHuesped().begin(); it != reserva->getListaHuesped().end(); it++)
				{
					if ((*it) == huesped)
					{
						existe = true;
						break;
					}
					if (tope > lstElem)
						break;
					tope++;
				}

				if (existe == false)
					throw HuesedNoExiste();
			}
		}
		else
		{
			ReservaIndividual *reserva = dynamic_cast<ReservaIndividual *>(reservaEstadia);
			if (reserva->getHuespedReserva() != huesped)
				throw HuesedNoExiste();
		}
	}
	else
	{
		throw FechaCheckInMenor();
	}
}

Estadia::Estadia(DTFecha checkIn, std::string promo, Reserva *reservaEstadia, Huesped *huespedEstadia)
{
	ValidarEstadia(checkIn, reservaEstadia, huespedEstadia);

	_checkIn = checkIn;
	_checkOut = nullptr;
	_promo = promo;
	_reservaEstadia = reservaEstadia;
	_huespedEstadia = huespedEstadia;
	_calificacionEstadia = nullptr;
}

// Destructor
Estadia::~Estadia()
{
	_reservaEstadia = nullptr;
	_huespedEstadia = nullptr;

	delete _checkOut;
	delete _calificacionEstadia;
}

// Operators

bool Estadia::operator==(const Estadia &assign)
{
	return (_reservaEstadia == assign._reservaEstadia && _huespedEstadia == assign._huespedEstadia);
}

// Getters / Setters
DTFecha Estadia::getCheckIn() const
{
	return _checkIn;
}
void Estadia::setCheckIn(DTFecha checkIn)
{
	_checkIn = checkIn;
}

DTFecha *Estadia::getChechOut() const
{
	return _checkOut;
}
void Estadia::setChechOut(DTFecha *chechOut)
{
	_checkOut = chechOut;
}

std::string Estadia::getPromo() const
{
	return _promo;
}
void Estadia::setPromo(std::string promo)
{
	_promo = promo;
}

Reserva *Estadia::getReservaEstadia() const
{
	return _reservaEstadia;
}
void Estadia::setReservaEstadia(Reserva *reservaEstadia)
{
	_reservaEstadia = reservaEstadia;
}

Huesped *Estadia::getHuespedEstadia() const
{
	return _huespedEstadia;
}
void Estadia::setHuespedEstadia(Huesped *huespedEstadia)
{
	_huespedEstadia = huespedEstadia;
}

Calificacion *Estadia::getCalificacionEstadia() const
{
	return _calificacionEstadia;
}

// Exceptions
const char *Estadia::FechaCheckInMenor::what() const throw()
{
	return "La fecha de checkIN es anterior a la de la reserva.";
}
const char *Estadia::HuesedNoExiste::what() const throw()
{
	return "El Huésped no aparece asociado a la Reserva.";
}

const char *Estadia::CalificacionNoExiste::what() const throw()
{
	return "No hay una calificación asociada a la Reserva.";
}

const char *Estadia::NOEXISTECHECKOUT::what() const throw()
{
	return "No hay una fecha de finalización asociada a la Reserva.";
}

// Methods
DTCalificacion Estadia::getCalificacionDataType()
{

	if (_calificacionEstadia != nullptr)
		return _calificacionEstadia->getDataType();
	else
		throw CalificacionNoExiste();
}

bool Estadia::esEstadiaCalificaicon(std::string email, int codigo)
{
	return (_huespedEstadia->getEmail() == email && _reservaEstadia->getCodigo() == codigo);
}

bool Estadia::getFinalizacion()
{
	return _checkOut != nullptr;
}

std::string Estadia::obtenerAutor()
{
	return _huespedEstadia->getEmail();
}

int Estadia::obtenerID()
{
	return _reservaEstadia->getCodigo();
}

float Estadia::calcularCosto()
{
	if (_checkOut == NULL)
	{
		throw NOEXISTECHECKOUT();
		return 0;
	}
	else
	{
		return _checkIn.diferenciaDias(DTFecha(_checkOut->getMinutos(), _checkOut->getHora(), _checkOut->getDia(), _checkOut->getMes(), _checkOut->getAnio())) * _reservaEstadia->getHabitacionReserva()->getPrecio();
	}
}

void Estadia::setCalificacionEstadia(Calificacion *calificacionEstadia)
{
	// ! Notificar
	_calificacionEstadia = calificacionEstadia;
}

void Estadia::notificarEstadia() // ! VER
{
}
