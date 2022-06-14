#include "header/DTReservaIndividual.hpp"

// Constructors
DTReservaIndividual::DTReservaIndividual(int codigo,
													  DTFecha checkIn,
													  DTFecha checkOut,
													  EstadoReserva estado,
													  float costo,
													  bool pago) : DTReserva(codigo, checkIn, checkOut, estado, costo)
{
	_pago = pago;
}
DTReservaIndividual::DTReservaIndividual(int codigo,
													  DTFecha checkIn,
													  DTFecha checkOut,
													  EstadoReserva estado,
													  float costo,
													  DTHabitacion *habitacion,
													  DTHuesped *huesped,
													  bool pago) : DTReserva(codigo, checkIn, checkOut, estado, costo, habitacion, huesped)
{
	_pago = pago;
}

// Destructor
DTReservaIndividual::~DTReservaIndividual()
{
	delete _habitacion;
	delete _huesped;
}

// Operators
std::ostream &DTReservaIndividual::operator<<(std::ostream &out)
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
	out << "Huésped: " << getHuesped()->getNombre() << "  " << getHuesped()->getEmail() << " ,  Es FINGER: " << ((getHuesped()->getEsFinger() == 0) ? " No " : " Sí ") << std::endl;
	return out;
}

// Getters
bool DTReservaIndividual::getPago() const
{
	return _pago;
}
