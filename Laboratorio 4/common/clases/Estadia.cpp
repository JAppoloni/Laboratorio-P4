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

			if ((reserva->getHuespedReserva() == huesped) || (*reserva->getListaHuesped().end()) == huesped)
				existe = true;

			if (existe == false)
			{

				for (std::list<Huesped *>::iterator it = reserva->getListaHuesped().begin(); it != reserva->getListaHuesped().end(); it++)
				{
					if ((*it) == huesped)
					{
						existe = true;
						break;
					}
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

Estadia::Estadia(const Estadia &copy)
{
	ValidarEstadia(copy.getCheckIn(), copy.getReservaEstadia(), copy.getHuespedEstadia());
	_checkIn = copy.getCheckIn();
	_chechOut = copy.getChechOut();
	_promo = copy.getPromo();
	_reservaEstadia = copy.getReservaEstadia();
	_huespedEstadia = copy.getHuespedEstadia();
	_calificacionEstadia = copy.getCalificacionEstadia();
}

Estadia::Estadia(DTFecha checkIn, DTFecha *chechOut, std::string promo, Reserva *reservaEstadia, Huesped *huespedEstadia, Calificacion *calificacionEstadia)
{
	ValidarEstadia(checkIn, reservaEstadia, huespedEstadia);
	_checkIn = checkIn;
	_chechOut = chechOut;
	_promo = promo;
	_reservaEstadia = reservaEstadia;
	_huespedEstadia = huespedEstadia;
	_calificacionEstadia = calificacionEstadia;
}

Estadia::Estadia(DTFecha checkIn, std::string promo, Reserva *reservaEstadia, Huesped *huespedEstadia)
{
	ValidarEstadia(checkIn, reservaEstadia, huespedEstadia);

	_checkIn = checkIn;
	_chechOut = nullptr;
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

	delete _chechOut;
	delete _reservaEstadia;
	delete _huespedEstadia;
	delete _calificacionEstadia;
}

// Operators
Estadia &Estadia::operator=(const Estadia &assign)
{
	_checkIn = assign.getCheckIn();
	_chechOut = assign.getChechOut();
	_promo = assign.getPromo();
	_reservaEstadia = assign.getReservaEstadia();
	_huespedEstadia = assign.getHuespedEstadia();
	_calificacionEstadia = assign.getCalificacionEstadia();
	return *this;
}

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
	return _chechOut;
}
void Estadia::setChechOut(DTFecha *chechOut)
{
	_chechOut = chechOut;
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
void Estadia::setCalificacionEstadia(Calificacion *calificacionEstadia)
{
	_calificacionEstadia = calificacionEstadia;
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


// Methods
DTCalificacion Estadia::getCalificacionDataType()
{

	if (_calificacionEstadia != nullptr)
		return DTCalificacion(*_calificacionEstadia);
	else
		throw CalificacionNoExiste();
}

bool Estadia::esEstadiaCalificaicon(std::string email, int codigo)
{
	return (_huespedEstadia->getEmail() == email && _reservaEstadia->getCodigo() == codigo);
}

bool Estadia::getFinalizacion()
{
	return _reservaEstadia->getEstado() == Cerrada;
}

std::string Estadia::obtenerAutor()
{
	return _huespedEstadia->getEmail();
}

void Estadia::notificarEstadia()
{
}

int Estadia::obtenerID()
{
	return _reservaEstadia->getCodigo();
}
