exec: build
	 make clean

build: source
	g++ -Wall -o executable \
	main.cpp \
	*.o

source:
	g++ -Wall -c presentacion/header/*.hpp
	g++ -Wall -c presentacion/*.cpp
	g++ -Wall -c dominio/header/*.hpp
	g++ -Wall -c dominio/*.cpp
	g++ -Wall -c common/clases/header/*.hpp
	g++ -Wall -c common/datatype/header/*.hpp
	g++ -Wall -c common/clases/*.cpp
	g++ -Wall -c common/datatype/*.cpp

clean:
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.hpp.gch' -exec rm {} \;

debug:
	g++ -Wall -c -g presentacion/header/*.hpp  
	g++ -Wall -c -g presentacion/*.cpp  
	g++ -Wall -c -g dominio/header/*.hpp 
	g++ -Wall -c -g dominio/*.cpp  
	g++ -Wall -c -g common/clases/header/*.hpp 
	g++ -Wall -c -g common/datatype/header/*.hpp 
	g++ -Wall -c -g common/clases/*.cpp 
	g++ -Wall -c -g common/datatype/*.cpp 
	g++ -Wall -g -g -o executable main.cpp *.o
	make clean