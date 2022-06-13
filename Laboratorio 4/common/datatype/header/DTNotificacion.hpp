#ifndef DTNOTIFICACION_HPP
# define DTNOTIFICACION_HPP

# include <iostream>
# include <string>

class DTNotificacion
{
	public:
		// Constructors
		DTNotificacion();
		DTNotificacion(const DTNotificacion &copy);
		DTNotificacion(std::string autor, std::string comentario, int puntaje);
		
		// Destructor
		~DTNotificacion();
		
		// Operators
		DTNotificacion & operator=(const DTNotificacion &assign);
		
		// Getters 
		std::string getAutor() const;
		std::string getComentario() const;
		int getPuntaje() const;
		
	private:
		std::string _autor;
		std::string _comentario;
		int _puntaje;
		
};

std::ostream &operator<<(std::ostream &out, DTNotificacion imprimir);

#endif