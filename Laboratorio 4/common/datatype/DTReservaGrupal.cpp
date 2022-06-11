#include "header/DTReservaGrupal.hpp"

DTReservaGrupal::DTReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo) : DTReserva(codigo, checkIn, checkOut, estado, costo)
{
}

DTReservaGrupal::DTReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, DTHabitacion *habitacion, DTHuesped *huesped, std::list<DTHuesped> *listaHuesped) : DTReserva(codigo, checkIn, checkOut, estado, costo, habitacion, huesped)
{
	_listaHuesped = listaHuesped;
}

// Destructor
DTReservaGrupal::~DTReservaGrupal()
{
	if (_listaHuesped != nullptr)
		_listaHuesped->clear();

	delete _habitacion;
	delete _huesped;
	delete _listaHuesped;
}

std::ostream &DTReservaGrupal::operator<<(std::ostream &out)
{
	out << "IMPLEMENTAR" << std::endl;
	return out;
}

// Getters
std::list<DTHuesped> *DTReservaGrupal::getListaHuesped() const
{
	return _listaHuesped;
}
