exec: build
	make clean

build: menu
	g++ -Wall -o executable \
	Ejercicio_1/main.cpp \
	*.o

menu:
	g++ -Wall -c Ejercicio_1/Presentacion/header/*.hpp
	g++ -Wall -c Ejercicio_1/Presentacion/*.cpp

clean:
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.hpp.gch' -exec rm {} \;
