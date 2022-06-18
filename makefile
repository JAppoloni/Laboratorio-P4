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
	g++ -Wall -Wextra -c -g presentacion/header/*.hpp  
	g++ -Wall -Wextra -c -g presentacion/*.cpp  
	g++ -Wall -Wextra -c -g dominio/header/*.hpp 
	g++ -Wall -Wextra -c -g dominio/*.cpp  
	g++ -Wall -Wextra -c -g common/clases/header/*.hpp 
	g++ -Wall -Wextra -c -g common/datatype/header/*.hpp 
	g++ -Wall -Wextra -c -g common/clases/*.cpp 
	g++ -Wall -Wextra -c -g common/datatype/*.cpp 
	g++ -Wall -Wextra -g -o executable main.cpp *.o
	make clean

	# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out  ./executable 

fing:
	g++ -Wall -Wextra -c -g presentacion/header/*.hpp  
	g++ -Wall -Wextra -c -g presentacion/*.cpp  
	find presentacion/header/ -type f -name '*.hpp.gch' -exec rm {} \;
	g++ -Wall -Wextra -c -g dominio/header/*.hpp 
	g++ -Wall -Wextra -c -g dominio/*.cpp  
	find dominio/header/ -type f -name '*.hpp.gch' -exec rm {} \;
	g++ -Wall -Wextra -c -g common/clases/header/*.hpp 
	g++ -Wall -Wextra -c -g common/datatype/header/*.hpp 
	g++ -Wall -Wextra -c -g common/clases/*.cpp 
	g++ -Wall -Wextra -c -g common/datatype/*.cpp 
	find common/ -type f -name '*.hpp.gch' -exec rm {} \;
	g++ -Wall -Wextra -g -o executable main.cpp *.o
	make clean

	# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out  ./executable 