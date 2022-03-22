#ifndef _SISTEMA_HH_
#define _SISTEMA_HH_

#include "../../common/clases/header/Reserva.hpp"
#include "../../common/clases/header/ReservaIndividual.hpp"
#include "../../common/clases/header/ReservaGrupal.hpp"
#include "../../common/clases/header/Huesped.hpp"
#include "../../common/datatype/header/DTReserva.hpp"
#include "../../common/datatype/header/DTReservaGrupal.hpp"
#include "../../common/datatype/header/DTReservaIndividual.hpp"
#include "../../common/datatype/header/DTHuesped.hpp"
#include "../../common/datatype/header/DTHabitacion.hpp"
#include "Collection.hpp"
#include <string>

class Sistema
{
    static Sistema *_sistema;

protected:
    Sistema();

private:
    Collection<Huesped *> huespedes;
    Collection<Reserva *> reservas;
    Collection<Habitacion *> habitaciones;
    Collection<DTReserva *> dtreservas;

    

public:
    /**
     * @brief Registra un nuevo huésped en el sistema. Si ya existe un huésped registrado con el mismo email, se
    lanza una excepción de tipo std::invalid_argument
     *
     * @param nombre
     * @param email
     * @param esFinger
     */
    void agregarHuesped(std::string nombre, std::string email, bool esFinger);

    /**
     * @brief Registra una nueva habitación en el hostel. Si ya existe una habitación registrada con el mismo número, se lanza una excepción de tipo std::invalid_argument.
     *
     * @param numero
     * @param precio
     * @param capacidad
     */
     void agregarHabitacion(int numero, float precio, int capacidad);

    /**
     * @brief Devuelve un arreglo con información sobre los huéspedes registrados en el sistema. El parámetro cantHuespedes es un parámetro de salida donde se devuelve la cantidad de huéspedes devueltas por la operación (corresponde a la cantidad de instancias de DTHuesped retornadas).
     *
     * @param cantHuespedes
     * @return DtHuesped**
     */
    DTHuesped **obtenerHuespedes(int &cantHuespedes);

    /**
     * @brief Devuelve un arreglo con información sobre las habitaciones registradas en el sistema. El parámetro cantHabitaciones es un parámetro de salida donde se devuelve la cantidad de habitaciones devueltas por la operación (corresponde a la cantidad de instancias de DtHabitacion retornadas).
     *
     * @param cantHabitaciones
     * @return DtHabitacion**
     */
     DTHabitacion **obtenerHabitaciones(int &cantHabitaciones);

    /**
     * @brief Devuelve un arreglo con información de las reservas para la fecha indicada. El parámetro cantReservas es un parámetro de salida donde se devuelve la cantidad de reservas devueltas por la operación (corresponde a la cantidad de instancias de DTReserva retornadas). Entre los datos específicos de cada reserva individual se encuentra si la misma fue pagada o no, mientras que para cada reserva grupal se indican los datos de cada huésped.

     *
     * @param fecha
     * @param cantReservas
     * @return DtReserva**
     */
     DTReserva **obtenerReservas(DTFecha fecha, int &cantReservas);

    /**
     * @brief Registra una reserva individual o grupal para el huésped identificado por email. El parámetro de entrada reserva contiene la información completa de la reserva. Entre los datos comunes a ambos tipos de reserva se encuentra el número de habitación, la fecha de checkIn y checkOut. Además, si reserva es una instancia de DtReservaIndividual contiene si la reserva fue pagada o no, mientras que si es un instancia de DtReservaGrupal, se indica la lista de huéspedes. La reserva se da de alta con el estado “Abierta” y un código generado por el sistema. Si no existe una habitación registrada en el sistema con el número indicado en el campo habitación de reserva, o si no existe un huésped registrado con el email email, se lanza una excepción de tipo std::invalid_argument.

     *
     * @param email
     * @param reserva
     */
     void registrarReserva(std::string email, DTReserva *reserva);

    ~Sistema();

    // SINGLETON
    static Sistema *GetInstance();

    /**

     * @brief  Dado el ID de una Habitación se retorna el obj de la Habitación, si !E se retorna NULL
     *
     * @param ID
     * @return DTHabitacion*
     */
    Habitacion *ObtenerHabitacionXID(int ID);

    /**
     * @brief Dado el DT de una Huesped se retorna el obj de la Huesped, si !E se retorna NULL
     *
     * @param ID
     * @return Habitacion*
     */
    Huesped *ObtenerHuespedXDT(DTHuesped *pDTHuesped);

    /**
     * @brief Dado el email de una Huesped se retorna el obj de la Huesped, si !E se retorna NULL
     *
     * @param pDTHuesped
     * @return Huesped*
     */
    Huesped *ObtenerHuespedXEmail(std::string email);
};

#endif
