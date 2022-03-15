exec: build
	make clean

build: menu
	g++ -Wall -o executable \
	main.cpp \
	*.o

menu:
	g++ -Wall -c menus/header/*.hpp
	g++ -Wall -c menus/*.cpp

clean:
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.hpp.gch' -exec rm {} \;
