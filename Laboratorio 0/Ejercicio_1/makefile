exec: build
	make clean

build: source
	g++ -Wall -o executable \
	main.cpp \
	*.o

source:
	g++ -Wall -c presentacion/header/*.hpp
	g++ -Wall -c presentacion/*.cpp
	g++ -Wall -c persistencia/header/*.hpp
	g++ -Wall -c persistencia/*.cpp
	g++ -Wall -c common/clases/header/*.hpp
	g++ -Wall -c common/datatype/header/*.hpp
	g++ -Wall -c common/clases/*.cpp
	g++ -Wall -c common/datatype/*.cpp

clean:
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.hpp.gch' -exec rm {} \;
