exec: build
	make clean

build: some
	g++ -Wall -o executable \
	main.cpp \
	*.o

some:
	g++ -Wall -c common/header/*.hpp
	g++ -Wall -c common/*.cpp

clean:
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.hpp.gch' -exec rm {} \;
