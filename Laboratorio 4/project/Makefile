
# --------------------------------------------------------------------
# Curso de Programacion 4, Facultad de Ingenieria, InCo 2021

# Makefile basado en Makefile de la tarea 1 del curso de Programacion 2

# --------------------------------------------------------------------

# Objetivo predeterminado (no se necesita especificarlo al invocar `make').
all: main

# Objetivos que no son archivos.
.PHONY: all clean

MODULOS = CantUsuariosSusc Partida Desarrollador DtJugador Estadistica HorasTotalesJuego PMJ TipoDePlataforma Categoria DtCategoria DtPartida EstadisticasDev Jugador Puntua ControladorEstadisticas DtCosto DtPartidaIndividual Otros Suscripcion Usuario ControladorPartidas DtDesarrollador DtPartidaMultijugador FechaSistema Temporales Videojuego ControladorUsuarios DtEstadistica DtUsuario Genero PartidaIndividual Vitalicia ControladorVideojuegos DtFechaHora DtVideojuego HistorialDeSuscripciones PartidaMultijugador

# directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj

TESTDIR = test

# extensión de los archivos
EXT = cpp
HEXT = hpp
# compilador
CC = g++ # gcc -x c 
LD = g++ # gcc
# opciones de compilación
CCFLAGS = -Wall -Werror -I$(HDIR) -g #-DNDEBUG
# -DNDEBUG
# se agrega esta opción para que las llamadas a assert no hagan nada.


# cadena de archivos, con directorio y extensión
HS   = $(MODULOS:%=$(HDIR)/%.$(HEXT))
CPPS = $(MODULOS:%=$(CPPDIR)/%.$(EXT))
OS   = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=main
EJECUTABLE=main


$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).$(EXT)
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .cpp
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
$(ODIR)/%.o: $(CPPDIR)/%.$(EXT) $(HDIR)/%.$(HEXT)
	$(CC) $(CCFLAGS) -c $< -o $@

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(LD) $(CCFLAGS) $^ -o $@


check-syntax:
	gcc -o nul -S ${CHK_SOURCES}

clean:
	rm -rfv $(ODIR)/*