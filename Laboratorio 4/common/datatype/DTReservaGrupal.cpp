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
	out << "Código: " << getCodigo() << std::endl;
	out << "Estado: ";
	imprimirEstadoReserva(getEstado());
	out << std::endl;
	out << "CheckIn: " << getCheckIn();
	out << "CheckOut: " << getCheckOut();
	out << "Costo: " << getCosto() << std::endl;
	out << "Habitacion:   Número: " << getHabitacion()->getNumero() << std::endl;
	out << "\t      "
		 << "Capacidad: " << getHabitacion()->getCapacidad() << std::endl;
	out << "\t      "
		 << "Precio: " << getHabitacion()->getPrecio() << std::endl;

	out << "Huespedes: " << getHuesped()->getNombre() << "  " << getHuesped()->getEmail() << " ,  Es FINGER: " << ((getHuesped()->getEsFinger() == 0) ? " No " : " Sí ") << std::endl;
	if (getListaHuesped() != nullptr)
	{
		out << "Lista de huéspedes: " << std::endl;
		for (auto it = _listaHuesped->begin(); it != _listaHuesped->end(); ++it)
		{ // \t
			out << "\t   "
				 << it->getNombre() << "  " << it->getEmail() << " ,  Es FINGER: " << ((it->getEsFinger() == 0) ? " No " : " Sí ") << std::endl;
		}
	}
	return out;
}

// Getters
std::list<DTHuesped> *DTReservaGrupal::getListaHuesped() const
{
	return _listaHuesped;
}
